import javax.swing.*;
import java.awt.*;
import java.sql.*;

public class ProductComboBox {

    public static void main(String[] args) throws Exception {

        Class.forName("com.mysql.cj.jdbc.Driver");

        Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/test",
                "root","");

        Statement st = con.createStatement();

        JFrame frame = new JFrame("Product Details");
        frame.setLayout(new BorderLayout());

        JComboBox<String> combo = new JComboBox<>();
        JTextArea area = new JTextArea();

        ResultSet rs = st.executeQuery("select name from product");
        while(rs.next()) {
            combo.addItem(rs.getString(1));
        }

        combo.addActionListener(e -> {
            try {
                ResultSet r = st.executeQuery(
                    "select * from product where name='" 
                    + combo.getSelectedItem() + "'");

                if(r.next()) {
                    area.setText(
                        "ID: " + r.getInt(1) +
                        "\nName: " + r.getString(2) +
                        "\nPrice: " + r.getInt(3)
                    );
                }
            } catch(Exception ex) {}
        });

        frame.add(combo, BorderLayout.NORTH);
        frame.add(new JScrollPane(area), BorderLayout.CENTER);

        frame.setSize(400,300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}