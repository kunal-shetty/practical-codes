import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

fig, ax = plt.subplots()
ax.set_xlim(0, 100)
ax.set_ylim(0, 40)

# Car body (rectangle)
body = plt.Rectangle((0, 10), 30, 10, fc='blue')
ax.add_patch(body)

# Car top
top = plt.Rectangle((8, 20), 14, 8, fc='skyblue')
ax.add_patch(top)

# Wheels
wheel_radius = 3
wheel1 = plt.Circle((8, 10), wheel_radius, fc='black')
wheel2 = plt.Circle((22, 10), wheel_radius, fc='black')
ax.add_patch(wheel1)
ax.add_patch(wheel2)


def update(frame):
    x = frame

    # Move body and top
    body.set_x(x)
    top.set_x(x + 8)

    # Move wheels
    wheel1.center = (x + 8, 10)
    wheel2.center = (x + 22, 10)

    return body, top, wheel1, wheel2

ani = animation.FuncAnimation(
    fig, update, frames=np.arange(0, 70, 1),
    interval=100, blit=True, repeat=True
)

plt.title("Moving Car Animation")
plt.show()