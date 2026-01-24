/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author mihir shetty
 */

class Animal {
	void sound() {
		System.out.println("Animal makes a sound");
	}
}

class Cat extends Animal {
	@Override
	void sound() {
		System.out.println("Meow meow");
	}
}
	
public class PolymorphismDemo {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        Animal a = new Animal();
        a.sound();
        
        Cat c = new Cat();
        c.sound();
        
        Animal obj = new Cat();
        obj.sound();
        
    }
}
