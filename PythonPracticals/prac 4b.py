a = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
b = [60]

def areEqual(list1, list2):
    for item1 in list1:
        for item2 in list2:
            if item1 == item2:
                return True
    return False

print(areEqual(a, b))

def deleteFromlist(nums ,*indices):
    for index in indices:
        nums[index] = -1
    nums = [num for num in nums if num != -1]
    return nums
indices = [0, 2, 4, 5]

newList = deleteFromlist(a, *indices)

for item in newList:
    print(item, end=" ")