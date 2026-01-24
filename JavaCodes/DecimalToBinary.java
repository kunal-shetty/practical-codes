/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author mihir shetty
 */
import java.util.Scanner;

public class DecimalToBinary {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter binary number: ");
        String binaryString = scanner.nextLine();
        System.out.println("Decimal: " + Integer.parseInt(binaryString, 2));
        System.out.println("Enter decimal number: ");
        int decimalNumber = scanner.nextInt();
        System.out.println("Decimal: " + Integer.toBinaryString(decimalNumber));
    }
}
