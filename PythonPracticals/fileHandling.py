# Read file
# f = open("meowmeow.txt", "r")
# content = f.read()
# print(content)

# Read line by line
f = open("meowmeow.txt", "r")
contents = f.readlines()
for i in range(len(contents) - 1, -1, -1):
    print(contents[i], end="")

# Append to file
# f = open("meowmeow.txt", "a")
# f.write("Hello world")

# Write to file (overwrite existing)
# f = open("meowmeow.txt", "w")
# f.write("Hello world")


# Close file
f.close()