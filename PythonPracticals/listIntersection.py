a = []
b = []
size = int(input("Enter number of elements for 1st list : "))
for i in range(0, size):
    num = int(input())
    a.append(num)

size = int(input("Enter number of elements for 2nd list : "))
for i in range(0, size):
    num = int(input())
    b.append(num)


def listEquator(list1, list2):
    for i in list1:
        for j in list2:
            if i == j:
                return i == j
    return False

if listEquator(a,b):
    print("At least one element of first list exists in second list")
else:
    print("No elements of first list exist in second list")