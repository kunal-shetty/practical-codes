import matplotlib.pyplot as plt
import numpy as np

# Screen size
width, height = 100, 100
screen = np.zeros((height, width))

# Colors
BOUNDARY = 1
FILL = 2

# Draw circle boundary
cx, cy, r = 50, 50, 20
for x in range(width):
    for y in range(height):
        if abs((x - cx)**2 + (y - cy)**2 - r*r) < 50:
            screen[y][x] = BOUNDARY

# Boundary Fill Algorithm
def boundary_fill(x, y):
    if x < 0 or x >= width or y < 0 or y >= height:
        return
    if screen[y][x] == BOUNDARY or screen[y][x] == FILL:
        return
    screen[y][x] = FILL
    boundary_fill(x+1, y)
    boundary_fill(x-1, y)
    boundary_fill(x, y+1)
    boundary_fill(x, y-1)

# Fill inside the circle
boundary_fill(cx, cy)

# Display output
plt.imshow(screen, cmap='gray')
plt.title("Boundary Fill Algorithm - Circle")
plt.axis('off')
plt.show()