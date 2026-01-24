/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author mihir shetty
 */

import java.util.Scanner;

public class Input {

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a number: ");
        int num = scanner.nextInt();
        System.out.println("Enter a string: ");
        String name = scanner.next();
        System.out.println("Number: " + num);
        System.out.println("Name: " + name);
    }
}
