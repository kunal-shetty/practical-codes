import matplotlib.pyplot as plt
import numpy as np

# Create blank screen
width, height = 100, 100
screen = np.zeros((height, width))

# Draw circle (boundary)
cx, cy, r = 50, 50, 20
for x in range(width):
    for y in range(height):
        if abs((x - cx)**2 + (y - cy)**2 - r*r) < 50:
            screen[y][x] = 1   # boundary color

# Flood fill algorithm
def flood_fill(x, y):
    if x < 0 or x >= width or y < 0 or y >= height:
        return
    if screen[y][x] != 0:
        return
    screen[y][x] = 2
    flood_fill(x+1, y)
    flood_fill(x-1, y)
    flood_fill(x, y+1)
    flood_fill(x, y-1)

# Fill the circle from center
flood_fill(cx, cy)

# Display
plt.imshow(screen, cmap='gray')
plt.title("Flood Fill Algorithm - Circle")
plt.axis('off')
plt.show()