import matplotlib.pyplot as plt

# Global window + line
xmin, ymin, xmax, ymax = 2, 2, 8, 8
x1, y1, x2, y2 = 0, 0, 10, 10

def liang():
    dx, dy = x2 - x1, y2 - y1
    u1, u2 = 0, 1

    for p, q in [(-dx, x1-xmin), (dx, xmax-x1),
                 (-dy, y1-ymin), (dy, ymax-y1)]:

        if p == 0 and q < 0: return None
        if p:
            t = q / p
            u1 = max(u1, t) if p < 0 else u1
            u2 = min(u2, t) if p > 0 else u2

    if u1 > u2: return None

    return (x1 + u1*dx, y1 + u1*dy,
            x1 + u2*dx, y1 + u2*dy)


result = liang()

plt.figure(figsize=(6,6))

plt.plot([xmin,xmax,xmax,xmin,xmin],
         [ymin,ymin,ymax,ymax,ymin], lw=2)

plt.plot([x1,x2],[y1,y2],'--', label="Original Line")

if result:
    plt.plot([result[0],result[2]],
             [result[1],result[3]], lw=3, label="Clipped Line")

plt.gca().set_aspect('equal')
plt.grid(True)
plt.legend()
plt.title("Liang–Barsky Line Clipping")
plt.show()