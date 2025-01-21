package ubb.map.practicajutor.service;

import ubb.map.practicajutor.domain.Nevoie;
import ubb.map.practicajutor.domain.Persoana;
import ubb.map.practicajutor.repository.NevoieRepository;
import ubb.map.practicajutor.repository.PersoanaRepository;
import ubb.map.practicajutor.utils.Observable;

import java.util.List;
import java.util.Optional;

public class Service extends Observable {
    PersoanaRepository persoanaRepository;
    NevoieRepository nevoieRepository;

    public Service(PersoanaRepository persoanaRepository, NevoieRepository nevoieRepository) {
        this.persoanaRepository = persoanaRepository;
        this.nevoieRepository = nevoieRepository;
    }

    public void savePersoana(Persoana persoana) {
        persoanaRepository.save(persoana);
        notifyObservers();
    }

    public List<Persoana> getAllPersoane() {
        return (List<Persoana>) persoanaRepository.findAll();
    }

    public List<Nevoie> getAllNevoi() {
        return (List<Nevoie>) nevoieRepository.findAll();
    }

    public void saveNevoie(Nevoie nevoie) {
        nevoieRepository.save(nevoie);
        notifyObservers();
    }

    public void updateNevoie(Nevoie nevoie) {
        nevoieRepository.update(nevoie);
        notifyObservers();
    }

    public Optional<Persoana> findPersoanaByUsernameAndPassword(String username, String password) {
        List<Persoana> persoane = (List<Persoana>) persoanaRepository.findAll();

        return persoane.stream()
                .filter(persoana -> persoana.getUsername().equals(username) && persoana.getParola().equals(password))
                .findFirst();
    }
}
