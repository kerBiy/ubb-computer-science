package org.university.socialapp.Domain.Validation;

import org.university.socialapp.Domain.FriendRequest;

import java.util.Objects;

public class FriendRequestValidator implements Validator<FriendRequest> {
    @Override
    public void validate(FriendRequest entity) throws ValidationException {
        String errorMessage = "";

        if (Objects.equals(entity.getUser1(), entity.getUser2())) {
            errorMessage += "You are already friends!\n";
        }

        if (!errorMessage.isEmpty()) {
            throw new ValidationException(errorMessage);
        }
    }
}
