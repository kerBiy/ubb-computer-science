import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class Main {
    public static void main(String[] args) {
        String url = "jdbc:postgresql://localhost:5432/SocialApp"; // Adjust host and port if necessary
        String user = "postgres"; // Replace with your database username
        String password = "nush"; // Replace with your database password

        // Query to execute
        String query = "SELECT id, name FROM users"; // Replace 'users' with your actual table name

        try (Connection conn = DriverManager.getConnection(url, user, password);
             PreparedStatement stmt = conn.prepareStatement(query);
             ResultSet rs = stmt.executeQuery()) {

            System.out.println("Connected to the database!");

            // Process the result set
            while (rs.next()) {
                int id = rs.getInt("id");
                String name = rs.getString("name");
                System.out.println("ID: " + id + ", Name: " + name);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}