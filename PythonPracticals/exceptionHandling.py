try:
    num = int(input("Enter number : "))
    result = 100 / num
except ValueError:
    print("Please enter valid number!")
except ZeroDivisionError:
    print("Cannot divide by zero!")
else:
    print("Result : ",result)