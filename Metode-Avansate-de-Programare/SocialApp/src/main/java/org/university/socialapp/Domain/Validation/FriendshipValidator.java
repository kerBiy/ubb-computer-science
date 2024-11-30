package org.university.socialapp.Domain.Validation;

import org.university.socialapp.Domain.Friendship;

import java.util.Objects;

public class FriendshipValidator implements Validator<Friendship> {
    @Override
    public void validate(Friendship friendship) {
        String errorMessage = "";

        if (Objects.equals(friendship.getUser1(), friendship.getUser2())) {
            errorMessage += "You are already friends!\n";
        }

        if (!errorMessage.isEmpty()) {
            throw new ValidationException(errorMessage);
        }
    }
}
