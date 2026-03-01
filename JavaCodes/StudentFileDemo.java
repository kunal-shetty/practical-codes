import java.io.*;
import java.util.Scanner;

public class StudentFileDemo {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        try {
            FileWriter fw = new FileWriter("students.txt", true);

            System.out.print("Enter Student Name: ");
            String name = sc.nextLine();

            System.out.print("Enter Marks: ");
            int marks = sc.nextInt();

            fw.write("Name: " + name + 
                     " | Marks: " + marks + "\n");

            fw.close();

            System.out.println("Data Saved Successfully!");

        } catch(Exception e) {
            System.out.println("Error: " + e);
        }
    }
}