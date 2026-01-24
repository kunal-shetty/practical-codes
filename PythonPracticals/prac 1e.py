num = int(input("Enter your number : "))
def armstrongCheck(num):
    check = num
    rev = 0
    while num > 0:
        rem = num % 10
        num //=  10
        rev = rev + rem** 3
        
    print("Armstrong" if check == rev else "Not Armstrong")

def palindromeCheck(num):
    temp = num
    rev = 0
    while num > 0:
        rev = rev * 10 + (num % 10)
        num //= 10
    print("Palindrome" if temp == rev else "Not Palindrome")

armstrongCheck(num)
palindromeCheck(num)