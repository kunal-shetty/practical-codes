import turtle

t = turtle.Turtle()
t.speed(2)

# X axis
t.penup()
t.goto(300, 0)
t.pendown()
t.goto(-300, 0)

# Y axis
t.penup()
t.goto(0, 300)
t.pendown()
t.goto(0, -300)

# Circle
t.penup()
t.goto(150, 50)
t.pendown()
t.circle(100)

# Circle label
t.penup()
t.goto(150, 170)
t.write("Circle", font=("Arial", 12, "normal"))

# Square
t.penup()
t.goto(-200, 50)
t.pendown()
for i in range(4):
    t.forward(150)
    t.left(90)

# Square label
t.penup()
t.goto(-200, 210)
t.write("Square", font=("Arial", 12, "normal"))

# Ellipse
t.penup()
t.goto(-200, -200)
t.pendown()
for _ in range(2):
    t.circle(100, 90)
    t.circle(50, 90)

# Ellipse label
t.penup()
t.goto(-200, -70)
t.write("Ellipse", font=("Arial", 12, "normal"))

# Half Ellipse
t.penup()
t.goto(200, -200)
t.pendown()
t.circle(100, 90)
t.circle(50, 90)

# Half Ellipse label
t.penup()
t.goto(200, -70)
t.write("Half Ellipse", font=("Arial", 12, "normal"))
t.hideturtle()
turtle.done()
