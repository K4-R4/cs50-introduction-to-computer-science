import os

from cs50 import SQL
from datetime import datetime
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    stocks = db.execute("SELECT symbol, name, SUM(shares) FROM transactions WHERE user_id = ? GROUP BY symbol", session["user_id"])
    price = []
    for stock in stocks:
        price.append(lookup(stock["symbol"]))

    # Create normalized rows to pass to render_template
    rows = []
    for i in range(len(stocks)):
        rows.append({**stocks[i], **price[i]})
        rows[i]["shares"] = rows[i]["SUM(shares)"]
        del rows[i]["SUM(shares)"]

    # Calculate cash
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]
    return render_template("index.html", rows=rows, cash=cash)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy.html")
    else:
        # lookup
        result = lookup(request.form.get("symbol"))
        if result == None:
            return apology("the stock did not exist")

        # Confirm requested shares are valid amount
        if not request.form.get("shares").isdigit() or request.form.get("shares", type=int) < 0:
            return apology("shares should be positive number")

        # Check whether user can afford to buy the stocks
        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]
        cost = result["price"] * request.form.get("shares", type=int)
        if cash < cost:
            return apology("You cannot afford that")

        # Record transaction time
        time = datetime.now()

        # Record transactions and update user's cash
        db.execute("INSERT INTO transactions (user_id, symbol, name, shares, price, time) VALUES(?, ?, ?, ?, ?, ?)",
                   session["user_id"], result["symbol"], result["name"], request.form.get("shares", type=int), result["price"], time)
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash - cost, session["user_id"])
        return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    records = db.execute("SELECT * FROM transactions WHERE user_id = ? ORDER BY time", session["user_id"])
    return render_template("history.html", records=records)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username and password were submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")
    else:
        # Confirm the existence of the referenced stock
        result = lookup(request.form.get("symbol"))
        if not result:
            return apology("the stock did not exist")
        return render_template("quoted.html", result=result)


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # Forget any user_id
    session.clear()

    if request.method == "POST":
        # Ensure username and passqord were submitted
        if not request.form.get("username"):
            return apology("username is missing")
        elif not request.form.get("password"):
            return apology("password is missing")

        # Ensure password and password confirmation match
        if request.form.get("password") != request.form.get("confirmation"):
            return apology("password and password confirmation do not match")

        # Ensure no duplicate username
        dupeRows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))
        if len(dupeRows) != 0:
            return apology("the username is already used")

        # Register user
        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", request.form.get(
            "username"), generate_password_hash(request.form.get("password")))

        # Remember which user has logged in
        registerdUserRow = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))
        session["user_id"] = registerdUserRow[0]["id"]

        # Redirect user to home page
        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    symbolsAndShares = db.execute(
        "SELECT symbol, SUM(shares) FROM transactions WHERE user_id = ? GROUP BY symbol", session["user_id"])
    if request.method == "GET":
        return render_template("sell.html", symbols=symbolsAndShares)
    else:
        # lookup
        result = lookup(request.form.get("symbol"))
        if result == None:
            return apology("the stock did not exist")

        # Confirm valid input
        if not request.form.get("shares").isdigit() or request.form.get("shares", type=int) < 0:
            return apology("shares should be positive number")

        # Confirm user has requested shares
        for stock in symbolsAndShares:
            if stock["symbol"] == request.form.get("symbol"):
                if stock["SUM(shares)"] < request.form.get("shares", type=int):
                    return apology("you do not have that amount of stocks")

        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]
        profit = result["price"] * request.form.get("shares", type=int)
        time = datetime.now()

        # Record transactions and update user's cash
        db.execute("INSERT INTO transactions (user_id, symbol, name, shares, price, time) VALUES(?, ?, ?, ?, ?, ?)",
                   session["user_id"], result["symbol"], result["name"], -request.form.get("shares", type=int), result["price"], time)
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash + profit, session["user_id"])
        return redirect("/")


@app.route("/add-cash", methods=["GET", "POST"])
@login_required
def add_cash():
    """Add cash"""
    if request.method == "GET":
        return render_template("add_cash.html")
    else:
        # Confirm valid input
        if not request.form.get("amount").isdigit() or request.form.get("amount", type=int) < 0:
            return apology("amount should be positive number")

        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash + request.form.get("amount", type=int), session["user_id"])
        return redirect("/")