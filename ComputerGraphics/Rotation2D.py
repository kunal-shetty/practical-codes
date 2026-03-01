import matplotlib.pyplot as plt
import math

def rotate2D(x, y, angle):
    r = math.radians(angle)
    xr = [x[i]*math.cos(r) - y[i]*math.sin(r) for i in range(len(x))]
    yr = [x[i]*math.sin(r) + y[i]*math.cos(r) for i in range(len(y))]

    x += [x[0]]
    y += [y[0]]
    xr += [xr[0]]
    yr += [yr[0]]

    plt.plot(x, y, 'o-', label="Original")
    plt.plot(xr, yr, 'o-', label="Rotated")
    plt.gca().set_aspect("equal")
    plt.grid()
    plt.legend()
    plt.title("2D Rotation")
    plt.show()

x = [1, 3, 3, 1]
y = [1, 1, 3, 3]

rotate2D(x, y, 45)
