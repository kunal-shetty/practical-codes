import matplotlib.pyplot as plt
import math

# House figure
x = [1, 5, 5, 3, 1]
y = [1, 1, 4, 6, 4]

def draw(x, y, label):
    x = x + [x[0]]
    y = y + [y[0]]
    plt.plot(x, y, marker='o', label=label)

# (i) Scaling about origin + translation
sx, sy = 1.5, 1.5
tx, ty = 2, 1
x_st = [(i * sx) + tx for i in x]
y_st = [(i * sy) + ty for i in y]

# (ii) Scaling about arbitrary point
a, b = 2, 2
x_ar = [a + 2 * (i - a) for i in x]
y_ar = [b + 2 * (i - b) for i in y]

# (iii) Reflection about y = x
m, c = 1, 0
x_ref, y_ref = [], []
for i in range(len(x)):
    d = (m * x[i] - y[i] + c) / (m*m + 1)
    x_ref.append(x[i] - 2 * m * d)
    y_ref.append(y[i] + 2 * d)

# Create subplots
plt.figure(figsize=(10, 8))

plt.subplot(2, 2, 1)
draw(x, y, "Original")
plt.title("Original House")
plt.gca().set_aspect("equal")
plt.grid()

plt.subplot(2, 2, 2)
draw(x, y, "Original")
draw(x_st, y_st, "Scaled + Translated")
plt.title("Scaling + Translation")
plt.gca().set_aspect("equal")
plt.grid()

plt.subplot(2, 2, 3)
draw(x, y, "Original")
draw(x_ar, y_ar, "Scaled about Point")
plt.title("Scaling about Arbitrary Point")
plt.gca().set_aspect("equal")
plt.grid()

plt.subplot(2, 2, 4)
draw(x, y, "Original")
draw(x_ref, y_ref, "Reflected about y = x")
plt.title("Reflection")
plt.gca().set_aspect("equal")
plt.grid()

plt.tight_layout()
plt.show()
