import javax.swing.*;
import java.awt.*;

public class ScrollPaneColor {

    public static void main(String[] args) {

        JFrame frame = new JFrame("Scroll Color");
        JTextArea area = new JTextArea();
        JScrollPane scroll = new JScrollPane(area);
        JButton button = new JButton("Choose Color");

        button.addActionListener(e -> {
            Color c = JColorChooser.showDialog(
                    frame, "Select Color", Color.white);
            scroll.getViewport().setBackground(c);
        });

        frame.add(button, BorderLayout.NORTH);
        frame.add(scroll, BorderLayout.CENTER);

        frame.setSize(500,400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}