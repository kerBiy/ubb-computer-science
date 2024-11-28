package org.university.socialapp;

import org.university.socialapp.ConsoleUI.Console;
import org.university.socialapp.Repository.FriendshipRepository;
import org.university.socialapp.Repository.UserRepository;
import org.university.socialapp.Service.Service;
import org.university.socialapp.Validation.Validator;

public class Main {
    public static void main(String[] args) {
        String url = "jdbc:postgresql://localhost:5432/SocialApp";
        String user = "postgres";
        String password = "nush";

        Validator validator = new Validator();
        UserRepository userRepo = new UserRepository(validator, url, user, password);
        FriendshipRepository friendshipRepo = new FriendshipRepository(validator, url, user, password);

        Service service = new Service(userRepo, friendshipRepo);
        Console console = new Console(service);

        console.show();
    }
}