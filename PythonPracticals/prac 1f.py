def factorial(num):
    if num == 1:
        return 1
    else:
        return num * factorial(num - 1)
num = int(input("Enter your number : "))
print(f"Factorial of number : {factorial(num)}")
