package org.university.socialapp.Domain.Validation;

import org.university.socialapp.Domain.Conversation;

public class ConversationValidator implements Validator<Conversation> {
    public void validate(Conversation conversation) {
        String errorMessage = "";

        if (conversation == null) {
            errorMessage += "Conversation object is null";
        }

        if (!errorMessage.isEmpty()) {
            throw new ValidationException(errorMessage);
        }
    }
}
