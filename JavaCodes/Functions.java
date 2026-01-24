//2. OOPS concepts in java
//2a. wap to implement thee concepts of inheritance and method overriding
//2b. wap to implement the concepts of abstract classes and methods
//2c. wap to implement the concepts of interfaces


class Utility { 
	static void greet() {
		System.out.println("Hello World!");
	}
	static void showSum(int a, int b) {
		System.out.println("Sum of the numbers is " + (a + b));
	}
	static int square(int num) {
		return num * num;
	}
}
 
public class Functions {
	public static void main(String args[]){
		Utility.greet();
		Utility.showSum(2, 5);
		System.out.println("Square of numbers: " + Utility.square(5));
	}
}