from matplotlib import pyplot as plt

def MidPointCircle(r):
    x, y = 0, r
    p = 1 - r

    xPoints, yPoints = [], []

    while x <= y:
        xPoints += [ x,  y,  y,  x, -x, -y, -y, -x]
        yPoints += [ y,  x, -x, -y, -y, -x,  x,  y]

        x += 1
        if p < 0:
            p += 2 * x + 1
        else:
            y -= 1
            p += 2 * (x - y) + 1

    plt.scatter(xPoints, yPoints)
    plt.gca().set_aspect('equal')
    plt.title("Midpoint Circle Algorithm")
    plt.show()

MidPointCircle(100)