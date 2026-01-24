/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author mihir shetty
 */

import java.util.Scanner;
 
class Helper { 
    
    static double PI = 3.14;
    
    static double areaOfCircle(double radius) {
        return radius * radius * PI;
    }
    
    static double perimeterOfCircle(double radius) {
        return 2 * radius * PI;
    }
}

public class AreaAndPerimeter {
    final double PI = 3.14;
    /**
     * @param args the command line arguments
     */
    
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        float radius = scanner.nextFloat();
        System.out.println("Area of circle: " + Helper.areaOfCircle(radius));
        System.out.println("Perimeter of circle: " + Helper.perimeterOfCircle(radius));
    } 
}
