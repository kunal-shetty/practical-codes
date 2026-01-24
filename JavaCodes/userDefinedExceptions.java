
import java.util.Scanner;

class AgeException extends Exception {
    public AgeException(String message) {
        super(message);
    }
}

class BalanceException extends Exception {
    public BalanceException(String message) {
        super(message);
    }
}

class PasswordException extends Exception {
    public PasswordException(String message) {
        super(message);
    }
}

public class userDefinedExceptions {

    static void checkAge(int age) throws AgeException {
        if(age < 18) throw new AgeException("Age must be 18 or above!");
        System.out.println("Valid age");
    }
    
    static void withdraw(int balance, int amount) throws BalanceException {
        if(amount > balance) throw new BalanceException("Not enough balance!");
        System.out.println("Withdraw successful! . Remaining Balance: " + (balance - amount));
    }
    
    static void checkPassword(String password) throws PasswordException {
        if(password.length() < 8) throw new PasswordException("Password must be at least 8 characters long!");
        System.out.println("Password saved successfully!");
    }
    
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        try {
            
            System.out.print("Enter age: ");
            int age = scanner.nextInt();
            checkAge(age);
            
            System.out.print("Enter current balance: ");
            int bal = scanner.nextInt();
            System.out.print("Enter withdraw amount: ");
            int amt = scanner.nextInt();
            
            withdraw(bal, amt);
            
            System.out.print("\nEnter password: ");
            scanner.nextLine();
            String password = scanner.nextLine();
            checkPassword(password);
            
        }
        
        catch(Exception e) {
            System.out.println("Exception caught: " + e.getMessage());
        }
        finally {
            System.out.println("End of program");
        }
    }
}
