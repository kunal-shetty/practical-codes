num = int(input("Enter number of terms : "))
a = 0
b = 1
print("Fibonacci series")
for i in range(1, num + 1):
    print(a, end=" ")
    c = a + b
    a = b
    b = c