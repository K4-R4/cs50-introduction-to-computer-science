# TODO
from cs50 import get_float


def main():
    while True:
        change = get_float("Change owed: ")
        if change > 0:
            break
    cents = int(get_cents(change))

    quarters = get_quarters(cents)
    cents -= quarters * 25

    dimes = get_dimes(cents)
    cents -= dimes * 10

    nickels = get_nickels(cents)
    cents -= nickels * 5

    pennies = get_pennies(cents)
    cents -= pennies * 1

    coins = quarters + dimes + nickels + pennies
    print(coins)


# Get cents
def get_cents(change):
    return change * 100


# Get quarters
def get_quarters(cents):
    return cents // 25


# Get dimes
def get_dimes(cents):
    return cents // 10


# Get nickels
def get_nickels(cents):
    return cents // 5


# Get pennies
def get_pennies(cents):
    return cents // 1


main()