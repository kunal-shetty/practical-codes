import javax.swing.*;
import java.awt.event.*;

public class AnonymousClassDemo {

    public static void main(String[] args) {

        JFrame frame = new JFrame("Anonymous Class Demo");
        JButton button = new JButton("Click Me");

        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(
                        frame, 
                        "Handled Using Anonymous Inner Class");
            }
        });

        frame.add(button);
        frame.setSize(350, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}