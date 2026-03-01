import javax.swing.*;
import java.awt.event.*;

public class ActionEventDemo {

    public static void main(String[] args) {

        JFrame frame = new JFrame("Action Event Demo");
        JButton button = new JButton("Click Me");
        JLabel label = new JLabel("Waiting for click...");

        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                label.setText("Button Clicked!");
            }
        });

        frame.setLayout(new java.awt.FlowLayout());
        frame.add(button);
        frame.add(label);

        frame.setSize(350, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}