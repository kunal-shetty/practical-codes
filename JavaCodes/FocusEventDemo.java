import javax.swing.*;
import java.awt.event.*;

public class FocusEventDemo extends JFrame {

    JLabel label;

    public FocusEventDemo() {

        JTextField textField = new JTextField(15);
        label = new JLabel("Click inside text field");

        textField.addFocusListener(new FocusAdapter() {
            public void focusGained(FocusEvent e) {
                label.setText("TextField Gained Focus");
            }

            public void focusLost(FocusEvent e) {
                label.setText("TextField Lost Focus");
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
        new FocusEventDemo();
    }
}