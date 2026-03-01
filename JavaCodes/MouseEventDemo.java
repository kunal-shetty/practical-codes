import javax.swing.*;
import java.awt.event.*;

public class MouseEventDemo extends JFrame {

    JLabel label;

    public MouseEventDemo() {

        label = new JLabel("Click anywhere inside window");

        addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                label.setText("Mouse Clicked at X=" 
                        + e.getX() + " Y=" + e.getY());
            }
        });

        add(label);
        setSize(400, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public static void main(String[] args) {
        new MouseEventDemo();
    }
}