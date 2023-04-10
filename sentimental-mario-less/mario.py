# TODO
from cs50 import get_int

# Loop till getting the proper values
while True:
    height = get_int("Height: ")
    if 0 < height < 9:
        break

for i in range(height):
    # Print blanks
    for j in range(height - (i + 1)):
        print(" ", end='')
    # Print blocks
    for k in range(i + 1):
        print("#", end='')
    print()