package ui;

import domain.User;
import service.Service;
import service.ServiceException;
import validation.ValidationException;

import java.util.Scanner;

public class Console {
    private Service service;

    public Console(Service service) {
        this.service = service;
    }

    private String input(String prompt) {
        Scanner input = new Scanner(System.in);
        System.out.print(prompt);
        return input.nextLine();
    }

    private void printCommands() {
        System.out.println("1. Add user");
        System.out.println("2. Remove user");
        System.out.println("3. Add friendship");
        System.out.println("4. Remove friendship");
        System.out.println("5. Show number of communities");
        System.out.println("6. Show the largest community");
        System.out.println("0. Show all users");
        System.out.println("q. Exit");
    }

    private void addUser() {
        try {
            Long id = Long.parseLong(input("User id: "));
            String name = input("User name: ");
            String email = input("User email: ");

            User user = service.addUser(id, name, email);

            System.out.println("User created: " + user.getName());
        } catch (ValidationException ex) {
            System.out.println("Validation error: " + ex.getMessage());
        } catch (ServiceException ex) {
            System.out.println("Service error: " + ex.getMessage());
        } catch (Exception e) {
            System.out.println("Exception: " + e.getMessage());
        }
    }

    private void removeUser() {
        try {
            Long id = Long.parseLong(input("User id: "));

            User user = service.removeUser(id);

            System.out.println("User deleted: " + user.getName());
        } catch (ValidationException ex) {
            System.out.println("Validation error: " + ex.getMessage());
        } catch (ServiceException ex) {
            System.out.println("Service error: " + ex.getMessage());
        } catch (Exception e) {
            System.out.println("Exception: " + e.getMessage());
        }

    }

    private void addFriendship() {
        try {
            Long idUser1 = Long.parseLong(input("First user id: "));
            Long idUser2 = Long.parseLong(input("Second user id: "));

            service.addFriendship(idUser1, idUser2);

            System.out.println("First user is now friend with second user");
        } catch (ValidationException ex) {
            System.out.println("Validation error: " + ex.getMessage());
        } catch (ServiceException ex) {
            System.out.println("Service error: " + ex.getMessage());
        } catch (Exception e) {
            System.out.println("Exception: " + e.getMessage());
        }
    }

    private void removeFriendship() {
        try {
            Long idUser1 = Long.parseLong(input("First user id: "));
            Long idUser2 = Long.parseLong(input("Second user id: "));

            service.removeFriendship(idUser1, idUser2);

            System.out.println("Friendship removed");
        } catch (ValidationException ex) {
            System.out.println("Validation error: " + ex.getMessage());
        } catch (ServiceException ex) {
            System.out.println("Service error: " + ex.getMessage());
        } catch (Exception e) {
            System.out.println("Exception: " + e.getMessage());
        }
    }

    private void showNumberOfCommunities() {
        try {
            var numberOfCommunities = service.getCommunityNumber();
            System.out.println("Number of communities: " + numberOfCommunities);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

    }

    private void showLargestCommunity() {
        try {
            var largestCommunity = service.getLargestCommunity();
            System.out.println("Largest community: ");
            largestCommunity.forEach(user -> System.out.println(user.getName()));
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

    }

    private void showAllUsers() {
        var allUsers = service.getUsers();
        allUsers.forEach(user -> System.out.println(user.getName()));
    }

    public void show() {
        String cmd;
        boolean isRunning = true;

        while (isRunning) {
            System.out.print("\nMENU:\n");
            printCommands();

            cmd = input("\nEnter command: ");
            System.out.println();

            switch (cmd) {
                case "1":
                    addUser();
                    break;

                case "2":
                    removeUser();
                    break;

                case "3":
                    addFriendship();
                    break;

                case "4":
                    removeFriendship();
                    break;

                case "5":
                    showNumberOfCommunities();
                    break;

                case "6":
                    showLargestCommunity();
                    break;

                case "0":
                    showAllUsers();
                    break;

                case "q":
                    System.out.println("Exiting the program...");
                    isRunning = false;
                    break;

                default:
                    System.out.println("Invalid command!");
            }
        }
    }

}
