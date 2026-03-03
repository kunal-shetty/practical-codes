# Java Concepts Cheatsheet

This cheatsheet simplifies the core Java concepts from your practical codes, stripping away redundancy to focus on what you actually need to know.

## 1. User Input
Use the `Scanner` class to read input from the user.
```java
import java.util.Scanner;

Scanner scanner = new Scanner(System.in);
int age = scanner.nextInt();      // Read integer
String name = scanner.nextLine(); // Read string
```

## 2. Pattern Printing
Pattern printing relies on **nested loops**. The outer loop controls rows, and the inner loop controls columns.
```java
for (int i = 1; i <= 5; i++) { // Rows
    for (int j = 1; j <= i; j++) { // Columns
        System.out.print("* ");
    }
    System.out.println(); // Next line after each row
}
```

## 3. String toCharArray()
Converts a `String` into an array of characters (`char[]`). Useful for modifying or reversing strings.
```java
String str = "Hello";
char[] charArray = str.toCharArray(); 
// charArray is now ['H', 'e', 'l', 'l', 'o']
```

## 4. Integer Class (Decimal to Binary & Vice Versa)
The `Integer` wrapper class provides built-in methods for number conversions so you don't have to write the math logic manually.
```java
// Decimal to Binary String
String binary = Integer.toBinaryString(10); // "1010"

// Binary String to Decimal Integer
int decimal = Integer.parseInt("1010", 2);  // 10
```

## 5. String charAt()
Retrieves a specific character from a string at a given index (0-based indexing).
```java
String str = "Java";
char ch = str.charAt(1); // 'a'
```

## 6. Classes & Constructors
A **Constructor** is a special method used to initialize objects. It has the same name as the class and no return type.
```java
class Student {
    String name;
    
    // Default Constructor
    Student() { 
        name = "Unknown"; 
    }
    
    // Parameterized Constructor
    Student(String n) { 
        name = n; 
    }
}
```

## 7. Method Overloading
Having multiple methods with the **same name but different parameters** (different type or number of arguments) within the same class.
```java
void add(int a, int b) { ... }
void add(double a, double b) { ... }
void add(int a, int b, int c) { ... }
```

## 8. Static Methods
Methods that belong to the class itself, not to a specific object. They can be called directly without creating an instance.
```java
class MathUtils {
    static int square(int x) { return x * x; }
}
// Calling it directly:
int result = MathUtils.square(5);
```

## 9. Inheritance & Method Overriding
**Inheritance** (`extends`) allows one class to inherit properties from another. **Overriding** is when a subclass provides a specific implementation for a method already defined in its parent class.
```java
class Animal {
    void sound() { System.out.println("Animal sound"); }
}
class Dog extends Animal {
    @Override
    void sound() { System.out.println("Bark"); }
}
```

## 10. Abstract Classes & Methods
An **abstract class** (`abstract`) cannot be instantiated directly. It can contain **abstract methods** (without a body) that must be implemented by subclasses.
```java
abstract class Shape {
    abstract void draw(); // No body
}
class Circle extends Shape {
    void draw() { System.out.println("Drawing Circle"); }
}
```

## 11. Interfaces
An interface (`implements`) is a blueprint of a class containing only abstract methods (until Java 8). It's used to achieve 100% abstraction and multiple inheritance in Java.
```java
interface Printable {
    void print();
}
class Document implements Printable {
    public void print() { System.out.println("Printing..."); }
}
```

## 12. Exceptions (Built-in & User-Defined)
Exceptions handle runtime errors gracefully using `try`, `catch`, and `finally`.
```java
// Built-in Exception
try {
    int res = 10 / 0;
} catch (ArithmeticException e) {
    System.out.println("Cannot divide by zero!");
}

// User-Defined Exception
class InvalidAgeException extends Exception {
    InvalidAgeException(String msg) { super(msg); }
}
// Throwing it:
if (age < 18) throw new InvalidAgeException("Too young");
```

## 13. Multithreading: Bouncing Balls Concept
Used for concurrent execution, like smooth animations in GUI.
- The class implementing the balls implements `Runnable`.
- A background `Thread` is started, running a `while(true)` loop inside `run()`.
- Updates the (x, y) coordinates of the balls, calls `repaint()`, and pauses briefly with `Thread.sleep()`.

## 14. Thread Life Cycle
1. **New**: Created but not started (`new Thread()`).
2. **Runnable**: Ready to run, waiting for CPU (`t.start()`).
3. **Running**: Currently executing `run()`.
4. **Blocked/Waiting**: Waiting for a resource or sleeping (`Thread.sleep()`).
5. **Terminated**: Finished executing `run()`.

## 15. Thread Class vs Runnable Interface
Two ways to create threads. `Runnable` is preferred because Java doesn't support multiple inheritance, so extending `Thread` limits your class from inheriting other classes.
```java
// 1. Extending Thread
class MyThread extends Thread {
    public void run() { ... }
}
new MyThread().start();

// 2. Implementing Runnable (Better)
class MyRunnable implements Runnable {
    public void run() { ... }
}
new Thread(new MyRunnable()).start();
```

## 16. JDBC Complete (Database Connectivity)
**Steps:** Load driver -> Get Connection -> Create Statement -> Execute Query -> Process ResultSet.
```java
// 1. Load Driver
Class.forName("com.mysql.cj.jdbc.Driver");
// 2. Connect
Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/db", "root", "password");
// 3. Statement (With Navigation ability)
Statement st = con.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
// 4. Execute & 5. Process
ResultSet rs = st.executeQuery("SELECT * FROM student");
while(rs.next()) {
    System.out.println(rs.getInt(1) + " " + rs.getString(2));
}
```

## 17. Swing Complete (GUI)
Java's lightweight GUI toolkit. Provides components like buttons and text areas.
```java
JFrame frame = new JFrame("App");
JButton btn = new JButton("Click Me");
frame.add(btn);
frame.setSize(300, 300);
frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
frame.setVisible(true);
```

## 18. Layout Managers
Control how components are arranged in a GUI container.
- **BorderLayout**: Divides into North, South, East, West, Center (Default for `JFrame`).
- **FlowLayout**: Arranges components in a line, one after another (Default for `JPanel`).
- **GridLayout**: Arranges components in a rigid grid of evenly sized rows and columns.

## 19. Event Handling
Used for listening to user actions (clicks, typing, focus). Links an action to a piece of code.
```java
JButton btn = new JButton("Click");
btn.addActionListener(new ActionListener() {
    public void actionPerformed(ActionEvent e) {
        System.out.println("Button was clicked!");
    }
});
```

## 20. File Handling (Open, Read, Copy, Write)
Using `FileReader` and `FileWriter` for standard text files.
```java
// Write
FileWriter fw = new FileWriter("file.txt");
fw.write("Hello World");
fw.close();

// Read
FileReader fr = new FileReader("file.txt");
int i;
while ((i = fr.read()) != -1) {
    System.out.print((char) i);
}
fr.close();
```

## 21. Adapter Classes & Anonymous Inner Classes
- **Adapter Classes**: Dummy implementations of listener interfaces with multiple methods (e.g., `MouseListener` has 5 methods). Adapters like `MouseAdapter` let you override only the one specific method you actually need, saving redundant code.
- **Anonymous Inner Class**: A class without a name, declared and instantiated in a single step (often used for event listeners to avoid creating a whole separate class file).
```java
// Using Adapter and Anonymous Inner Class together
frame.addMouseListener(new MouseAdapter() {
    public void mouseClicked(MouseEvent e) {
        System.out.println("Only overriding click!");
    }
});
```
