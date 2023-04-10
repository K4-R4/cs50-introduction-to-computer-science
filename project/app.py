from cs50 import SQL
from flask import Flask, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///database.db")


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
    """Show library"""
    rows = db.execute("SELECT * FROM books JOIN users_books ON books.id == users_books.book_id WHERE user_id = ? ORDER BY title", session["user_id"])
    return render_template("index.html", rows=rows)


@app.route("/add", methods=["GET", "POST"])
@login_required
def add():
    """Add a book to the record"""
    # User reached route via POST
    if request.method == "POST":
        title = request.form.get("title").strip()
        author = request.form.get("author").strip()
        year = request.form.get("year").strip()
        rating = request.form.get("rating").strip()
        note = request.form.get("note").strip()

        # Ensure all input fields ware completed
        if not (title and author and year and rating and note):
            return apology("must complete all the input fields")
            
        # Ensure submitted "year" was integer
        if not year.isdecimal():
            return apology("invalid year")
        # Ensure submitted "rating" was integer
        if not rating.isdecimal():
            return apology("invalid rating")

        db.execute("INSERT INTO books (title, author, year, rating, note) VALUES(?, ?, ?, ?, ?)", title, author, year, rating, note)
        lastInsertedID = db.execute("SELECT * FROM sqlite_sequence WHERE name = ?", "books")[0]["seq"]
        db.execute("INSERT INTO users_books (user_id, book_id) VALUES(?, ?)", session["user_id"], lastInsertedID)
        return redirect("/")

    # User reached route via GET
    else:
        return render_template("add.html")


@app.route("/delete")
@login_required
def delete():
    book_id = request.args.get("id")
    db.execute("DELETE FROM users_books WHERE user_id = ? AND book_id = ?", session["user_id"], book_id)
    return redirect("/")

@app.route("/edit", methods=["GET", "POST"])
@login_required
def edit():
    if request.method == "POST":
        book_id = request.args.get("id").strip()
        title = request.form.get("title").strip()
        author = request.form.get("author").strip()
        year = request.form.get("year").strip()
        rating = request.form.get("rating").strip()
        note = request.form.get("note").strip()

        # Ensure all input fields ware completed
        if not (title and author and year and rating and note):
            return apology("must complete all the input fields")

        db.execute("UPDATE books set title = ?, author = ?, year = ?, rating = ?, note = ? WHERE id = ?", title, author, year, rating, note, book_id)
        return redirect("/")
    else:
        book_id = request.args.get("id")
        row = db.execute("SELECT * FROM books WHERE id = ? ORDER BY title", book_id)[0]
        return render_template("edit.html", row=row)


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


@app.route("/search", methods=["GET", "POST"])
@login_required
def search():
    """Search for specific books"""
    if request.method == "POST":
        title = request.form.get("title")
        author = request.form.get("author")
        year = request.form.get("year")
        rating = request.form.get("rating")
        note = request.form.get("note")

        # Attach place holders to input for partial match
        if title:
            title = "%" + title[0:len(title)] + "%"
        # Attach place holders to input for partial match
        if author:
            author = "%" + author[0:len(author)] + "%"
        # Attach place holders to input for partial match
        if note:
            note = "%" + note[0:len(note)] + "%"

        # Cause an error if no input was submitted
        if not (title or author or year or rating or note):
            return apology("missing input")

        rows = db.execute("SELECT * FROM books JOIN users_books ON books.id == users_books.book_id WHERE user_id = ? AND (title LIKE ? OR author LIKE ? OR year = ? OR rating = ? OR note LIKE ?) ORDER BY title", session["user_id"], title, author, year, rating, note)
        return render_template("searched.html", rows=rows)
    else:
        return render_template("search.html")