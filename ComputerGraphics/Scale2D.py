import matplotlib.pyplot as plt

def scale2D(x, y, sx, sy):
    xs = [i * sx for i in x] + [x[0] * sx]
    ys = [i * sy for i in y] + [y[0] * sy]
    x += [x[0]]
    y += [y[0]]

    plt.plot(x, y, 'o-', label="Original")
    plt.plot(xs, ys, 'o-', label="Scaled")
    plt.gca().set_aspect("equal")
    plt.grid()
    plt.legend()
    plt.title("2D Scaling")
    plt.show()

x = [1, 3, 3, 1]
y = [1, 1, 3, 3]

scale2D(x, y, 4, 5)
