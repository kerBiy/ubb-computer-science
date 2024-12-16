package org.university.socialapp;

import org.university.socialapp.Domain.Validation.FriendshipValidator;
import org.university.socialapp.Domain.Validation.UserValidator;
import org.university.socialapp.Repository.ConversationRepository;
import org.university.socialapp.Repository.FriendshipRepository;
import org.university.socialapp.Repository.UserRepository;
import org.university.socialapp.Service.Service;

public class Main {
    public static void main(String[] args) {
        final String url = "jdbc:postgresql://localhost:5432/SocialApp";
        final String user = "postgres";
        final String password = "nush";

        UserValidator userValidator = new UserValidator();
        FriendshipValidator friendshipValidator = new FriendshipValidator();

        UserRepository userRepo = new UserRepository(userValidator, url, user, password);
        FriendshipRepository friendshipRepo = new FriendshipRepository(friendshipValidator, url, user, password);
        ConversationRepository conversationRepo = new ConversationRepository(url, user, password);

        Service service = new Service(userRepo, friendshipRepo, conversationRepo);

        GUI.setService(service);
        GUI.launch();
    }
}