/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author mihir shetty
 */
import java.util.Scanner;

public class ReverseString {
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter string: ");
        String input = scanner.nextLine();
        char[] ch = input.toCharArray();
        System.out.print("Reversed String: ");
        for(int i = input.length() - 1; i >= 0; i--) {
            System.out.print(ch[i]);
        }
    }
}
