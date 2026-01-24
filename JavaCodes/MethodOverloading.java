class MathOperations { 
	int add(int a, int b) {
		return a + b;
	}
	int add(int a, int b, int c) {
		return a + b + c;
	}
	double add(double a, double b) {
		return a + b;
	}
}

public class MethodOverloading {
    public static void main(String args[]) {
        MathOperations mathOps = new MathOperations();
	System.out.println("Sum of two: " + mathOps.add(1, 4));
	System.out.println("Sum of three: " + mathOps.add(1, 2, 3));
	System.out.println("Decimal sum: " + mathOps.add(1.0, 2.1));
    }
}
