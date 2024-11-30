package org.university.socialapp.Domain.Validation;

import org.university.socialapp.Domain.Message;

public class MessageValidator implements Validator<Message> {
    public void validate(Message message) {
        String errorMessage = "";

        if (message.getText().length() > 255) {
            errorMessage += "The message is too long";
        }

        if (!errorMessage.isEmpty()) {
            throw new ValidationException(errorMessage);
        }
    }
}
