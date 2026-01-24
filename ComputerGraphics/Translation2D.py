import matplotlib.pyplot as plt

def translate2D(x1, x2, y1, y2, tx, ty):
    x3 = x1 + tx
    y3 = y1 + ty
    x4 = x2 + tx
    y4 = y2 + ty

    plt.plot([x1, x2], [y1, y2], marker='o', label="Original Line")
    plt.plot([x3, x4], [y3, y4], marker='o', label="Translated Line", color="red")

    plt.axhline(0, color="black", linewidth=0.5)
    plt.axhline(0, color="black", linewidth=0.5)
    plt.grid(True)
    plt.legend()
    plt.title("Line Translation")
    plt.xlabel("X-axis")
    plt.ylabel("Y-axis")
    plt.show()

print("Enter the line end points")
x1 = int(input("x1 : "))
y1 = int(input("y1 : "))
x2 = int(input("x2 : "))
y2 = int(input("y2 : "))

print("Enter the translation (shift) coordinates")
tx = int(input("X shift : "))
ty = int(input("Y shift : "))

translate2D(x1, x2, y1, y2, tx, ty)


