import turtle

t = turtle.Turtle()
t.speed(2)

# Hut base (rectangle)
t.penup()
t.goto(-100, -100)
t.pendown()
for _ in range(2):
    t.forward(200)
    t.left(90)
    t.forward(150)
    t.left(90)

# Roof (triangle)
t.penup()
t.goto(-100, 50)
t.pendown()
t.goto(0, 150)
t.goto(100, 50)

# Door
t.penup()
t.goto(-20, -100)
t.pendown()
for _ in range(2):
    t.forward(40)
    t.left(90)
    t.forward(70)
    t.left(90)

# Window (left)
t.penup()
t.goto(-70, -20)
t.pendown()
for _ in range(4):
    t.forward(30)
    t.left(90)

# Window (right)
t.penup()
t.goto(40, -20)
t.pendown()
for _ in range(4):
    t.forward(30)
    t.left(90)

t.hideturtle()
turtle.done()
