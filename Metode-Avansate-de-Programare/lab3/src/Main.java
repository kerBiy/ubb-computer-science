import repository.FriendshipRepositoryDB;
import repository.UserRepositoryDB;
import service.Service;
import ui.Console;
import validation.Validator;

public class Main {
    public static void main(String[] args) {
        String url = "jdbc:sqlserver://localhost:1433;databaseName=SocialApp;encrypt=true;trustServerCertificate=true";
        String username = "sa";
        String password = "Strong.Pwd-123";

        Validator validator = new Validator();
        UserRepositoryDB userRepo = new UserRepositoryDB(validator, url, username, password);
        FriendshipRepositoryDB friendshipRepo = new FriendshipRepositoryDB(validator, url, username, password);

        Service service = new Service(userRepo, friendshipRepo);
        Console ui = new Console(service);

        ui.show();
    }
}