package ro.ubbcluj.map.socialnetwork.domain.validators;

import ro.ubbcluj.map.socialnetwork.domain.Utilizator;

public class UtilizatorValidator implements Validator<Utilizator> {
    @Override
    public void validate(Utilizator entity) throws ValidationException {
        if(entity == null){
            throw new ValidationException("Utilizatorul nu poate fi null");
        }

//        if(entity.getUsername().length()<3){
//            throw new ValidationException("Usernameul trebuie sa aiba minim 3 caractere");
//        }
//
//        if(entity.getPassword().lines() < 3 || entity.getPassword().length()>30){
//            throw new ValidationException("Parola trebuie sa aiba intre 3 si 30 de caractere");
//        }

        if(entity.getFirstName().isEmpty()){
            throw new ValidationException("Numele nu poate fi gol");
        }

        if(entity.getLastName().isEmpty()){
            throw new ValidationException("Prenumele nu poate fi gol");
        }

    }
}

