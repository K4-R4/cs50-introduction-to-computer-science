# TODO
from cs50 import get_string
import re


def main():
    text = get_string("Text: ")

    letters = count_letters(text)

    words = count_words(text)

    sentences = count_sentences(text)

    L = letters / words * 100
    S = sentences / words * 100

    # Calculate index
    index = round(0.0588 * L - 0.296 * S - 15.8)
    # Print corresponding grades
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


# Count letters
def count_letters(text):
    return len(re.findall("[a-zA-Z]", text))


# Count words
def count_words(text):
    return text.count(" ") + 1


# Count sentences
def count_sentences(text):
    return text.count(".") + text.count("!") + text.count("?")


main()