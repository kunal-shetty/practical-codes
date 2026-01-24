'''ch = input("Enter a character : ")
ch.lower()
print("Vowel" if ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' else "Consonant")
'''
rows = 5
for i in range(1, rows + 1):
    print("*  " * i)
for i in range(rows - 1 , 0, -1):
    print("*  " * i)