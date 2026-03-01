import javax.swing.*;
import java.awt.event.*;

public class AdapterClassDemo extends JFrame {

    public AdapterClassDemo() {

        JLabel label = new JLabel("Click inside window");

        addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                label.setText("Mouse Clicked Using Adapter");
            }
        });

        add(label);
        setSize(350, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public static void main(String[] args) {
        new AdapterClassDemo();
    }
}