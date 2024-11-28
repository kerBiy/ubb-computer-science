package ro.ubbcluj.map.socialnetwork.service;

import ro.ubbcluj.map.socialnetwork.domain.CererePrietenie;
import ro.ubbcluj.map.socialnetwork.domain.Prietenie;
import ro.ubbcluj.map.socialnetwork.domain.Tuple;
import ro.ubbcluj.map.socialnetwork.domain.Utilizator;
import ro.ubbcluj.map.socialnetwork.domain.validators.ValidationException;
import ro.ubbcluj.map.socialnetwork.observer.Observable;
import ro.ubbcluj.map.socialnetwork.observer.Observer;
import ro.ubbcluj.map.socialnetwork.repository.CerereDBRepository;
import ro.ubbcluj.map.socialnetwork.repository.PagingRepository.CerereDBPagingRepository;
import ro.ubbcluj.map.socialnetwork.repository.PrietenieDBRepository;
import ro.ubbcluj.map.socialnetwork.repository.UserDBRepository;
import ro.ubbcluj.map.socialnetwork.repository.paging.Page;
import ro.ubbcluj.map.socialnetwork.repository.paging.Pageable;

import java.sql.SQLException;
import java.time.LocalDateTime;
import java.util.*;

public class CerereService implements Observable {

    private final PrietenieDBRepository repoPrietenie;
    private final UserDBRepository repoUtilizatori;
    private final CerereDBRepository repoCerere;

    private final CerereDBPagingRepository repoPageCerere;

    private final List<Observer> observers = new ArrayList<>();

    public CerereService(PrietenieDBRepository repoPrietenie, UserDBRepository repoUtilizatori, CerereDBRepository repoCerere, CerereDBPagingRepository repoPageCerere) {
        this.repoPrietenie = repoPrietenie;
        this.repoUtilizatori = repoUtilizatori;
        this.repoCerere = repoCerere;
        this.repoPageCerere = repoPageCerere;
    }

    public void addCerere(CererePrietenie cererePrietenie) throws SQLException {

        if(repoPrietenie.findOne(new Tuple<>(cererePrietenie.getId().getRight(), cererePrietenie.getId().getLeft())).isPresent() ||
            repoPrietenie.findOne(cererePrietenie.getId()).isPresent()){
            throw new ValidationException("Exista deja prietenie intre ei");
        }

        if (repoCerere.findOne(cererePrietenie.getId()).isPresent()) {
            throw new ValidationException("Exista o cerere deja trimisa");
        }

        repoCerere.save(cererePrietenie);
        notifyAllObservers();
    }

    public boolean verifyCerere(Long id1, Long id2) throws SQLException {
        return repoCerere.findOne(new Tuple<>(id1, id2)).isPresent() ||
                repoCerere.findOne(new Tuple<>(id2, id1)).isPresent();
    }

    public void respondRequest(Tuple<Long, Long> id, String raspunsCerere) throws SQLException {
        Optional<CererePrietenie> cererePrietenie = repoCerere.findOne(id);
        if (cererePrietenie.isEmpty()) {
            throw new ValidationException("Nu exista cererea de prietenie");
        }

        if ("APPROVED".equals(raspunsCerere)) {
            Prietenie prietenie = new Prietenie();
            prietenie.setId(id);
            prietenie.setDate(LocalDateTime.now());
            repoPrietenie.save(prietenie);
            repoCerere.delete(id);
        } else {
            repoCerere.delete(id);
        }
        notifyAllObservers();
    }

    public List<Utilizator> pendingRequests(Long idUser) {
        List<Utilizator> rez = new ArrayList<>();

        repoUtilizatori.findOne(idUser).ifPresentOrElse(
                user -> repoCerere.findAll().forEach(cerere -> {
                    if (Objects.equals(cerere.getId().getRight(), idUser)) {
                        repoUtilizatori.findOne(cerere.getId().getLeft()).ifPresent(rez::add);
                    }
                }),
                () -> {
                    throw new ValidationException("Userul nu exista");
                }
        );

        return rez;
    }
    @Override
    public void registerObserver(Observer o) {
        observers.add(o);
    }

    @Override
    public void removeObserver(Observer o) {
        observers.remove(o);
    }

    @Override
    public void notifyAllObservers() throws SQLException {
        for (Observer observer : observers) {
                observer.update();
        }
    }

    public Page<Utilizator> findAllOnPage(Pageable pageable, Long id) {

        Page<CererePrietenie> pageRequests = repoPageCerere.findAllOnPage(pageable, id);
        List<Utilizator> users = new ArrayList<>();
        List<CererePrietenie> cererePrietenies = (List<CererePrietenie>) pageRequests.getElementsOnPage();
        cererePrietenies.forEach(cererePrietenie -> {
            Long userId = cererePrietenie.getId().getLeft();
            repoUtilizatori.findOne(userId).ifPresent(users::add);
        });

        return new Page<>(users, pageRequests.getTotalNrOfElems());
    }

}
