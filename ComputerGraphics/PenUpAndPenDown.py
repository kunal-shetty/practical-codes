import turtle

t = turtle.Turtle()
t.speed(2)

# Circle
t.color('red')
t.penup()
t.goto(-250, 100)
t.pendown()
t.write("Circle", font=("Arial", 12, "bold"))
t.penup()
t.goto(-250, 80)
t.pendown()
t.circle(50)

#Rectangle
t.color('blue')
t.penup()
t.goto(-50, 150)
t.pendown()
t.write("Rectangle", font=("Arial", 12, "bold"))
t.penup()
t.goto(-50, 100)
t.pendown()

for _ in range(2):
    t.forward(120)
    t.right(90)
    t.forward(60)
    t.right(90)

#Oval
t.color('yellow')
t.penup()
t.goto(200, 130)
t.pendown()
t.write("Oval", font=("Arial", 12, "bold"))
t.penup()
t.goto(200, 80)
t.pendown()

for _ in range(2):
    t.circle(60, 90)
    t.circle(30, 90)

#Triangle
t.color('orange')
t.penup()
t.goto(-150, -50)
t.pendown()
t.write("Triangle", font=("Arial", 12, "bold"))
t.pendown()

for _ in range(3):
    t.forward(100)
    t.left(120)

#Square
t.color('green')
t.penup()
t.goto(100, -50)
t.pendown()
t.write("Square", font=("Arial", 12, "bold"))
t.penup()
t.goto(100, -100)
t.pendown()

for _ in range(4):
    t.forward(100)
    t.right(90)

turtle.done()
