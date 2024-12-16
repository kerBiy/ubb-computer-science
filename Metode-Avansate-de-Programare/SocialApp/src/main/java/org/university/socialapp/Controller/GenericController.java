package org.university.socialapp.Controller;

import org.university.socialapp.Service.Service;

import java.util.Optional;

public class GenericController {
    protected Service service;

    public void setService(Service service) {
        this.service = service;
    }

    public void setSomething(Optional<Object> parameter) {
    }
}
