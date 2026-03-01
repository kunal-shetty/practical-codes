import java.io.*;

public class CopyFileDemo {

    public static void main(String[] args) {

        try {
            FileInputStream in = new FileInputStream("source.txt");
            FileOutputStream out = new FileOutputStream("destination.txt");

            int data;

            while((data = in.read()) != -1) {
                out.write(data);
            }

            in.close();
            out.close();

            System.out.println("File Copied Successfully!");

        } catch(Exception e) {
            System.out.println("Error: " + e);
        }
    }
}