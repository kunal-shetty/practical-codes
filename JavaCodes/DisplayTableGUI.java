import javax.swing.*;
import java.sql.*;

public class DisplayTableGUI {

    public static void main(String[] args) throws Exception {

        Class.forName("com.mysql.cj.jdbc.Driver");

        Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/test",
                "root", "");

        Statement st = con.createStatement(
                ResultSet.TYPE_SCROLL_INSENSITIVE,
                ResultSet.CONCUR_READ_ONLY);

        ResultSet rs = st.executeQuery("select * from student");

        rs.last();
        int rows = rs.getRow();
        rs.beforeFirst();

        String data[][] = new String[rows][3];
        int i = 0;

        while(rs.next()) {
            data[i][0] = rs.getString(1);
            data[i][1] = rs.getString(2);
            data[i][2] = rs.getString(3);
            i++;
        }

        String column[] = {"ID","Name","Marks"};

        JTable table = new JTable(data, column);
        JFrame frame = new JFrame("Student Data");

        frame.add(new JScrollPane(table));
        frame.setSize(500,300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);

        con.close();
    }
}