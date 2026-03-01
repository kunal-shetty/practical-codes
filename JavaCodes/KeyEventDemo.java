import javax.swing.*;
import java.awt.event.*;

public class KeyEventDemo extends JFrame {

    JLabel label;

    public KeyEventDemo() {

        JTextField textField = new JTextField(15);
        label = new JLabel("Press any key");

        textField.addKeyListener(new KeyAdapter() {
            public void keyReleased(KeyEvent e) {
                label.setText("Last Key Pressed: " + e.getKeyChar());
            }
        });

        setLayout(new java.awt.FlowLayout());
        add(textField);
        add(label);

        setSize(350, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public static void main(String[] args) {
        new KeyEventDemo();
    }
}