import javax.swing.*;
import java.awt.event.*;

public class SelectionEventDemo {

    public static void main(String[] args) {

        JFrame frame = new JFrame("Selection Event Demo");
        JComboBox<String> comboBox = new JComboBox<>(
                new String[]{"Java", "Python", "C++"});
        JLabel label = new JLabel("Select a language");

        comboBox.addItemListener(new ItemListener() {
            public void itemStateChanged(ItemEvent e) {
                if(e.getStateChange() == ItemEvent.SELECTED) {
                    label.setText("Selected: " 
                            + comboBox.getSelectedItem());
                }
            }
        });

        frame.setLayout(new java.awt.FlowLayout());
        frame.add(comboBox);
        frame.add(label);

        frame.setSize(350, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}