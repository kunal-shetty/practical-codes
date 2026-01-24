/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author mihir shetty
 */
public class Pattern {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        int rows = 5;
        for(int i = 1; i <= rows; i++) {
            for(int j = 5; j >= i; j--) {
                System.out.printf("* ");
            }
            System.out.println();
        }
    }
}
