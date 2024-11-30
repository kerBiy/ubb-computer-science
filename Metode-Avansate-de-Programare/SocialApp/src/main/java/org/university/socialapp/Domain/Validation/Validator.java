package org.university.socialapp.Domain.Validation;

public interface Validator<T> {
    void validate(T entity) throws ValidationException;
}

