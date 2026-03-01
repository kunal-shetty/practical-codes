import javax.swing.*;
import java.awt.*;
import java.util.Random;

public class RandomColorSwing {

    public static void main(String[] args) {

        JFrame frame = new JFrame("Random Color");
        JButton button = new JButton("Change Background");

        button.addActionListener(e -> {
            Random r = new Random();
            Color c = new Color(
                    r.nextInt(256),
                    r.nextInt(256),
                    r.nextInt(256));

            frame.getContentPane().setBackground(c);
        });

        frame.add(button);
        frame.setSize(400,200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}