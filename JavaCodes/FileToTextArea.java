import javax.swing.*;
import java.io.*;

public class FileToTextArea {

    public static void main(String[] args) {

        JFrame frame = new JFrame("File Viewer");
        JTextArea area = new JTextArea();
        JScrollPane scroll = new JScrollPane(area);

        JFileChooser chooser = new JFileChooser();
        int result = chooser.showOpenDialog(frame);

        if(result == JFileChooser.APPROVE_OPTION) {
            File file = chooser.getSelectedFile();
            try {
                BufferedReader br = new BufferedReader(
                        new FileReader(file));

                String line;
                while((line = br.readLine()) != null) {
                    area.append(line + "\n");
                }
                br.close();
            } catch(Exception e) {}
        }

        frame.add(scroll);
        frame.setSize(500,400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}