word1 = "USA North America"
word2 = "USA South America"

for word in word1:
    for wordd in word2:
        if wordd == word:
            print(wordd, end="")
            break

def letterCount(word, toCountLetter):
    count = 0
    for letter in word:
        if letter == toCountLetter:
            count += 1
    return count

print()
print(letterCount("Hello","l"))
