package org.university.socialapp.Domain;

public interface Entity<ID> {
    ID getId();
    void setId(ID id);
}