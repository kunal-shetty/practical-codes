// prac 1 : oops concept in java - 1
//1a. wap to create a class and implement a default, overloaded and copy constructor
//1b. wap to create a class and implement the concepts of method overloading
//1c. wap to create a class and implement the concepts of static method	

// when the local variable name and instantiated variable name are same, java gives priority to local variable, this is used to refer to the objects curent instance

class Person {
	String name;
	int age;
	Person() {
		name = "Kunal";
		age = 10;
		System.out.println("Default constructor called");
	}
	
	Person(String name) {
		this.name = name;    
		System.out.printf("\nHello %s", name);	
	}
	
	Person(String name, int age) {
		this.name = name;  
		this.age = age;
		System.out.printf("\nHello %s you are %d years old\n", name, age);	
	}

	Person(Person Other) {
		this.name = Other.name;
		this.age = Other.age;
		System.out.println("\nCopy constructor called");
	}

	void show(){
		System.out.println("Name : " + name + ", Age : " + age ); 
	}
}

public class ConstructorOverloading {
	public static void main(String args[]){
		Person p1 = new Person();
		p1.show();
		
		Person p2 = new Person("Kunal", 18);
		p2.show();

		Person p3 = new Person(p2);
		p3.show();
	}
}

//Hw print multiplication table using java 
// print name, city, college, roll no using java 
