// prac 1 : oops concept in java - 1
//1a. wap to create a class and implement a default, overloaded and copy constructor
//1b. wap to create a class and implement the concepts of method overloading
//1c. wap to create a class and implement the concepts of static method	

// when the local variable name and instantiated variable name are same, java gives priority to local variable, this is used to refer to the objects curent instance

class PersonDetail {
	String name;
	int age;
	PersonDetail() {
		name = "Kunal";
		age = 10;
		System.out.println("Default constructor called");
	}
	
	PersonDetail(String name) {
		this.name = name;    
		System.out.printf("Hello %s", name);	
	}
	
	PersonDetail(String name, int age) {
		this.name = name;  
		this.age = age;
		System.out.printf("Hello %s you are %d years old", name, age);	
	}

	PersonDetail(PersonDetail Other) {
		this.name = Other.name;
		this.age = Other.age;
		System.out.println("Copy constructor called");
	}
}

public class Person {
	public static void main(String args[]) {
		

