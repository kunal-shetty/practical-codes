import turtle

# Create screen
s = turtle.Screen()
s.title("Coordinate Axes")
s.bgcolor("white")

# Create turtle
t = turtle.Turtle()
t.speed(2)
t.color("black")

# Draw X-axis
t.penup()
t.goto(-300, 0)
t.pendown()
t.goto(300, 0)

# Draw Y-axis
t.penup()
t.goto(0, -300)
t.pendown()
t.goto(0, 300)

# Label axes
t.penup()
t.goto(290, -20)
t.write("X", font=("Arial", 12, "bold"))

t.goto(-20, 290)
t.write("Y", font=("Arial", 12, "bold"))

t.hideturtle()
turtle.done()
