import turtle
s = turtle.Screen()
s.title("Coordinate Axes")

t = turtle.Turtle()

t.speed(2)

t.penup()
t.goto(300, 0)
t.pendown()
t.goto(-300, 0)
t.penup()
t.goto(0, 300)
t.pendown()
t.goto(0, -300)

t.penup()
t.goto(150, 50)
t.pendown()
t.circle(100)

t.penup()
t.goto(-150, 50)
t.pendown()
for i in range(4):
    t.forward(90)
    t.left(90)

t.penup()
t.goto(-200, -200)
t.pendown()
for i in range(2):
    t.circle(90, 90)
    t.circle(50, 90)

t.penup()
t.goto(200, -200)
t.pendown()

t.circle(90, 90)
t.circle(50, 90)

t.hideturtle()
turtle.done()