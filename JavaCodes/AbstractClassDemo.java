/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author mihir shetty
 */

abstract class Animal {
	abstract void sound();
        void sleep() {
            System.out.println("Animal is sleeping");
        }
}

class Cat extends Animal {
	@Override
	void sound() {
		System.out.println("Meow meow");
	}
}


public class AbstractClassDemo {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        Cat c = new Cat();
        c.sound();
        c.sleep();
    }
    
}
