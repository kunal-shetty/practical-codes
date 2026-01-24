str = input("Enter character : ").lower()
def vowelOrconsonant(str):
    vowels = ['a','e','i','o','u']
    if str in vowels:
        print("Vowel")
    else:
        print("Consonant")
vowelOrconsonant(str)
