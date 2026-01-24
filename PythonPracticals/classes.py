class Student:
    def __init__(self, name):
        self.name = name
    def doThat(self):
        print("Name : ", self.name)

class Parent(Student):
    def doThis(self):
        print("Meow meow")

object = Parent("Kun")
object.doThat()
object.doThis()
