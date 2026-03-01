import matplotlib.pyplot as plt
import matplotlib.animation as animation
import random

fig, ax = plt.subplots()
ax.set_xlim(0, 100)
ax.set_ylim(0, 100)
ax.axis('off')

text = ax.text(50, 50, "SCREEN SAVER", fontsize=15)

def update(frame):
    x = random.randint(0, 80)
    y = random.randint(0, 90)
    text.set_position((x, y))
    return text,

ani = animation.FuncAnimation(fig, update, interval=500)
plt.title("Simple Text Screen Saver")
plt.show()