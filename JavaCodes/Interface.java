  /*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author mihir shetty
 */
interface Animal {
    void sound();
    void sleep();
}
class Cat implements Animal {
    @Override 
    public void sound() {
        System.out.println("Meow"); 
    }
    @Override
    public void sleep() {
        System.out.println("Cat is sleeping.....");
    }
}

class Dog implements Animal {
    @Override 
    public void sound() {
        System.out.println("Bark"); 
    }
    @Override
    public void sleep() {
        System.out.println("Dog is sleeping.....");
    }
}

public class Interface {
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        Animal c = new Cat();            
        Animal d = new Dog();
        c.sleep(); c.sound();
        d.sleep(); d.sound();
    }
}
