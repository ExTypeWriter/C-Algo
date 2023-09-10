from time import time
import sys

memo = {}
YES_KEYWORDS = ["yes", "y", "yeah", "of course", "why not"]
NO_KEYWORDS = ["no", "nope", "n", "nah", "forget it"]

def fibo_n(n):
    if n in memo:
        
        return memo[n]
    if n <= 2:
        result = 1
    else:
        result = fibo_n(n-1) + fibo_n(n-2)
    memo[n] = result
    return result

# Set a higher recursion limit (use with caution)
sys.setrecursionlimit(100000000)  # Change this to the desired limit

is_using = True

while is_using:
    try:
        n = int(input("Input n Fibonacci numbers: "))
        if n < 0:
            print("Please enter a non-negative integer.")
            continue
        orderString = "th"
        if n == 1:
            orderString = "st"
        elif n == 2:
            orderString = "nd"
        elif n == 3:
            orderString = "rd"
        if n in memo:
            print("And it is in memo!")
        start = time()
        print(f"Here is {n}{orderString} : {fibo_n(n)}")
        stop = time()
        
        elapsed_time = stop - start
        print(f"Calculated in {elapsed_time:.20f} seconds")

    except ValueError:
        print("Invalid input")

    yes_or_no = input("Do you still want to use this program? (yes/no): ")
    if yes_or_no.lower() in YES_KEYWORDS:
        continue
    elif yes_or_no.lower() in NO_KEYWORDS:
        is_using = False
