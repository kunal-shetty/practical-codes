/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */
/**
 *
 * @author mihir shetty
 */

import java.util.Scanner;

public class AddBinary {
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter first binary number: ");
        String a = scanner.nextLine();
        System.out.println("Enter second binnary number: ");
        String b = scanner.nextLine();
        int sum = Integer.parseInt(a, 2) + Integer.parseInt(b, 2);
        String result = Integer.toBinaryString(sum);
        System.out.println("Sum = " + result);
    }
}
