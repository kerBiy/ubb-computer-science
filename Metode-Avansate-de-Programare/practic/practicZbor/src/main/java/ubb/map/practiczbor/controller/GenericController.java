package ubb.map.practiczbor.controller;


import ubb.map.practiczbor.service.Service;

import java.util.Optional;

public abstract class GenericController {
    protected Service service;

    public void setService(Service service) {
        this.service = service;
    }

    public abstract void setSomething(Optional<Object> parameter);
}