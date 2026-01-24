from matplotlib import pyplot as plt

def DDA(x0, x1, y0, y1):
    dx = x1 - x0
    dy = y1 - y0

    step = int(max(abs(dx), abs(dy)))

    xi = dx / step
    yi = dy / step

    xcord = []
    ycord = []

    x, y = x0, y0
    for i in range(step + 1):
        xcord.append(x)
        ycord.append(y)
        x += xi
        y += yi

    plt.plot(xcord, ycord)
    plt.title("DDA Line Drawing Algorithm")
    plt.show()

DDA(0, 50, 0, 2)