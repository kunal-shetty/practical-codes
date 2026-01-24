import matplotlib.pyplot as plt

def scale2D(x, y):
    sx = float(input("Enter scaling factor for X-axis: "))
    sy = float(input("Enter scaling factor for Y-axis: "))

    xArr, yArr = [], []

    for i in range(len(x)):
        xArr.append(x[i] * sx)
        yArr.append(y[i] * sy)

    # Close the shape
    x_plot = x + [x[0]]
    y_plot = y + [y[0]]
    x_scaled = xArr + [xArr[0]]
    y_scaled = yArr + [yArr[0]]

    plt.plot(x_plot, y_plot, marker="o", label="Original Object")
    plt.plot(x_scaled, y_scaled, marker="o", label="Scaled Object")

    plt.gca().set_aspect("equal", adjustable="box")
    plt.grid(True)
    plt.legend()
    plt.xlabel("X-axis")
    plt.ylabel("Y-axis")
    plt.title("2D Scaling")
    plt.show()

x, y = [], []

n = int(input("Enter number of vertices for the shape: "))

for i in range(n):
    a = int(input(f"Enter x{i+1}: "))
    b = int(input(f"Enter y{i+1}: "))
    x.append(a)
    y.append(b)

scale2D(x, y)
