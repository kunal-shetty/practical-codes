import matplotlib.pyplot as plt

INSIDE, LEFT, RIGHT, BOTTOM, TOP = 0, 1, 2, 4, 8

xmin, ymin, xmax, ymax = 2, 2, 8, 8

def code(x, y):
    c = INSIDE
    if x < xmin: c |= LEFT
    elif x > xmax: c |= RIGHT
    if y < ymin: c |= BOTTOM
    elif y > ymax: c |= TOP
    return c

def cohen(x1, y1, x2, y2):
    c1, c2 = code(x1,y1), code(x2,y2)

    while True:
        if not (c1 | c2):
            return x1, y1, x2, y2
        if c1 & c2:
            return None

        c = c1 if c1 else c2
        m = (y2 - y1) / (x2 - x1)

        if c & TOP:
            y = ymax
            x = x1 + (ymax - y1) / m

        elif c & BOTTOM:
            y = ymin
            x = x1 + (ymin - y1) / m

        elif c & RIGHT:
            x = xmax
            y = y1 + (xmax - x1) * m

        elif c & LEFT:
            x = xmin
            y = y1 + (xmin - x1) * m

        if c == c1:
            x1, y1 = x, y
            c1 = code(x1,y1)
        else:
            x2, y2 = x, y
            c2 = code(x2,y2)

x1, y1, x2, y2 = 0, 0, 10, 6

result = cohen(x1, y1, x2, y2)

plt.figure(figsize=(6,6))

plt.plot(
    [xmin, xmax, xmax, xmin, xmin],
    [ymin, ymin, ymax, ymax, ymin],
    linewidth=2,
    label="Clipping Window"
)

plt.plot([x1, x2], [y1, y2], '--', label="Original Line")

if result:
    plt.plot(
        [result[0], result[2]],
        [result[1], result[3]],
        linewidth=3,
        label="Clipped Line"
    )

plt.title("Cohen–Sutherland Line Clipping")
plt.legend()
plt.grid(True)
plt.show()
