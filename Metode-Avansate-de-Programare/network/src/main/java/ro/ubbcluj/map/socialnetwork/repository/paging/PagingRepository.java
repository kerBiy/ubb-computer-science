package ro.ubbcluj.map.socialnetwork.repository.paging;

import ro.ubbcluj.map.socialnetwork.domain.CererePrietenie;
import ro.ubbcluj.map.socialnetwork.domain.Entity;
import ro.ubbcluj.map.socialnetwork.repository.Repository;

import java.util.Optional;

public interface PagingRepository<ID ,
        E extends Entity<ID>>
        extends Repository<ID, E> {

    Page<E> findAllOnPage(Pageable pageable, Long id);

}