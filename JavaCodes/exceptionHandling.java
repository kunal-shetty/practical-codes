
import java.util.Scanner;

public class exceptionHandling {
    
    static void checkAge(int age) {
        if(age < 18) throw new ArithmeticException("Age must be 18 or above!");
        System.out.println("Valid age");
    }
    static void divide(int a, int b) {
        if(b == 0) throw new ArithmeticException("Division by zero is not allowed!");
        System.out.println("Result: " + (a / b));
    }
    static void checkName(String name) {
        if(name == null) throw new NullPointerException("Empty name input!");
        System.out.println("Name length: " + name.length());
    }
    static void checkArray(int []arr) {
        if(arr.length == 0) throw new ArrayIndexOutOfBoundsException("Empty Array!");
        System.out.println("First element: " + arr[0]);
    }
    
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        try {
            System.out.print("Enter age: ");
            int age = scanner.nextInt();
            checkAge(age);
            
            System.out.print("\nEnter numerator: ");
            int n = scanner.nextInt();
            System.out.print("Enter denominator: ");
            int d = scanner.nextInt();
            divide(n, d);
            
            System.out.print("\nEnter name: ");
            scanner.nextLine();
            String name = scanner.nextLine();
            
            if(name.length() != 0) checkName(name);
            else checkName(null);
            
            int []nums = {};
            
//            checkArray(nums);
        }
        
        catch(Exception e) {
            System.out.println("Exception caught: " + e.getMessage());
        }
        finally {
            System.out.println("End of program");
        }
    }
}
