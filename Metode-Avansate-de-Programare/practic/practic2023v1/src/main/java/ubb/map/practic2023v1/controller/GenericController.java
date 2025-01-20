package ubb.map.practic2023v1.controller;

import ubb.map.practic2023v1.service.Service;

import java.util.Optional;

public abstract class GenericController {
    protected Service service;

    public void setService(Service service) {
        this.service = service;
    }

    public abstract void setSomething(Optional<Object> parameter);
}