import turtle

t = turtle.Turtle()
t.speed(0)        # Fastest drawing

radius = 20       # Starting radius

for i in range(6):    # Number of circles
    t.penup()
    t.goto(0, -radius)   # Move to bottom of the circle
    t.pendown()
    t.circle(radius)
    radius += 20         # Increase radius for next circle

turtle.done()
