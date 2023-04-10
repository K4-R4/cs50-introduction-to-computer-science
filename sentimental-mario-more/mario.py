# TODO
from cs50 import get_int


# Prompt users type input
while True:
    height = get_int("Height: ")
    # Check whther the input is valid
    if 0 < height < 9:
        break

# Iterate for height times
for i in range(height):
    # Print left half of the pyramid
    for j in range(height - (i + 1)):
        print(" ", end="")
    for k in range(i + 1):
        print("#", end="")
    print("  ", end="")
    # Print right half of the pyramid
    for l in range(i + 1):
        print("#", end="")
    # Insert new line
    print()