/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author mihir shetty
 */

import java.util.Scanner;

public class MultiplicationTable {
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a number: ");
        int num = scanner.nextInt();
        System.out.println("Multiplication Table");
        for(int i = 1; i <= 10; i++)
            System.out.println(num + " x " + i + " = " + (num * i));
    }
}
