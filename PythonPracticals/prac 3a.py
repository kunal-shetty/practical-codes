pangram = True
alphabets = 'abcdefghijklmnopqrstuvwxyz'
sentence = "The quick brown fox jumps over the lazy dog"
for alphabet in alphabets:
    if alphabet not in sentence.lower():
        pangram = False

print("Pangram" if pangram else "Not A Pangram")


