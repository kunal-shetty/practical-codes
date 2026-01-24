from matplotlib import pyplot as plt

def BresenhamCircle(r):
    x, y = 0, r
    d = 3 - 2 * r

    xPoints, yPoints = [], []

    while x <= y:
        xPoints += [ x,  y,  y,  x, -x, -y, -y, -x]
        yPoints += [ y,  x, -x, -y, -y, -x,  x,  y]

        if d < 0:
            d += 4 * x + 6
        else:
            d += 4 * (x - y) + 10
            y -= 1
        x += 1

    plt.scatter(xPoints, yPoints)
    plt.gca().set_aspect('equal')
    plt.title("Bresenham Circle Algorithm")
    plt.show()

BresenhamCircle(20)
