package ro.map.practic1.controller;

import ro.map.practic1.service.Service;

import java.util.Optional;

public class GenericController {
    protected Service service;

    public void setService(Service service) {
        this.service = service;
    }

    public void setSomething(Optional<Object> parameter) {
    }
}