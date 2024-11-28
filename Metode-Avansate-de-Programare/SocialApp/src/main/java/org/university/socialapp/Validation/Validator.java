package validation;

import domain.User;

public class Validator {
    public void validateUser(User user) {
        String errorMessage = "";

        if (user.getId() <= 0) {
            errorMessage += "User id must be a pozitive number!\n";
        }
        if (user.getName().length() > 32) {
            errorMessage += "User name must be less than 32 characters!\n";
        }
        if (!user.getEmail().contains("@")) {
            errorMessage += "Email address must be a valid email address!\n";
        }

        if (!errorMessage.isEmpty()) {
            throw new ValidationException(errorMessage);
        }
    }
}
