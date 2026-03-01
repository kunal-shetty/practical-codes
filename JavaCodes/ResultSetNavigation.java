import javax.swing.*;
import java.awt.*;
import java.sql.*;

public class ResultSetNavigation {

    static ResultSet rs;

    public static void main(String[] args) throws Exception {

        Class.forName("com.mysql.cj.jdbc.Driver");

        Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/test",
                "root","");

        Statement st = con.createStatement(
                ResultSet.TYPE_SCROLL_INSENSITIVE,
                ResultSet.CONCUR_READ_ONLY);

        rs = st.executeQuery("select * from student");

        JFrame frame = new JFrame("Navigation");
        frame.setLayout(new BorderLayout());

        JTextArea area = new JTextArea();
        JButton next = new JButton("Next");
        JButton prev = new JButton("Previous");

        next.addActionListener(e -> {
            try {
                if(rs.next()) {
                    area.setText(
                        rs.getInt(1) + " " +
                        rs.getString(2) + " " +
                        rs.getInt(3));
                }
            } catch(Exception ex) {}
        });

        prev.addActionListener(e -> {
            try {
                if(rs.previous()) {
                    area.setText(
                        rs.getInt(1) + " " +
                        rs.getString(2) + " " +
                        rs.getInt(3));
                }
            } catch(Exception ex) {}
        });

        JPanel panel = new JPanel();
        panel.add(prev);
        panel.add(next);

        frame.add(panel, BorderLayout.NORTH);
        frame.add(area, BorderLayout.CENTER);

        frame.setSize(400,300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}