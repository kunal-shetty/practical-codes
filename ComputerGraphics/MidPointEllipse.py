from matplotlib import pyplot as plt

def MidPointEllipse(rx, ry):
    x, y = 0, ry

    rx2 = rx * rx
    ry2 = ry * ry

    xPoints, yPoints = [], []

    # -------- Region 1 --------
    p1 = ry2 - (rx2 * ry) + (0.25 * rx2)
    dx = 2 * ry2 * x
    dy = 2 * rx2 * y

    while dx < dy:
        xPoints += [ x, -x,  x, -x]
        yPoints += [ y,  y, -y, -y]

        x += 1
        dx += 2 * ry2

        if p1 < 0:
            p1 += dx + ry2
        else:
            y -= 1
            dy -= 2 * rx2
            p1 += dx - dy + ry2

    # -------- Region 2 --------
    p2 = (ry2 * (x + 0.5)**2) + (rx2 * (y - 1)**2) - (rx2 * ry2)

    while y >= 0:
        xPoints += [ x, -x,  x, -x]
        yPoints += [ y,  y, -y, -y]

        y -= 1
        dy -= 2 * rx2

        if p2 > 0:
            p2 += rx2 - dy
        else:
            x += 1
            dx += 2 * ry2
            p2 += dx - dy + rx2

    plt.scatter(xPoints, yPoints)
    plt.gca().set_aspect('equal')
    plt.title("Midpoint Ellipse Drawing Algorithm")
    plt.show()

MidPointEllipse(3000, 2000)