import matplotlib.pyplot as plt
import matplotlib.animation as animation
import numpy as np

fig, ax = plt.subplots()
ax.set_aspect('equal')
ax.set_xlim(-2, 2)
ax.set_ylim(-2, 2)
ax.axis('off')

# Face
face = plt.Circle((0, 0), 1, fill=False)
ax.add_patch(face)

# Eyes
ax.plot(-0.4, 0.4, 'o')
ax.plot(0.4, 0.4, 'o')

# Mouth
mouth, = ax.plot([], [], lw=2)

def update(frame):
    x = np.linspace(-0.5, 0.5, 200)

    curve_strength = (np.sin(frame * 0.2) + 1) / 2

    y = -0.3 + curve_strength * (x ** 2)

    mouth.set_data(x, y)
    return mouth,


ani = animation.FuncAnimation(fig, update, frames=100, interval=50)

plt.title("Smiling Face Animation")
plt.show()