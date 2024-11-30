package org.university.socialapp.Domain.Validation;

import org.university.socialapp.Domain.User;

public class UserValidator implements Validator<User> {
    @Override
    public void validate(User user) {
        String errorMessage = "";

        if (user.getId() <= 0) {
            errorMessage += "User id must be a pozitive number!\n";
        }
        if (user.getName().length() > 32) {
            errorMessage += "User name must be less than 32 characters!\n";
        }

        if (!errorMessage.isEmpty()) {
            throw new ValidationException(errorMessage);
        }
    }
}
