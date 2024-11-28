package ro.ubbcluj.map.socialnetwork.repository.PagingRepository;

import ro.ubbcluj.map.socialnetwork.domain.CererePrietenie;
import ro.ubbcluj.map.socialnetwork.domain.Prietenie;
import ro.ubbcluj.map.socialnetwork.domain.Tuple;
import ro.ubbcluj.map.socialnetwork.domain.validators.CerereValidator;
import ro.ubbcluj.map.socialnetwork.domain.validators.PrietenieValidator;
import ro.ubbcluj.map.socialnetwork.repository.PrietenieDBRepository;
import ro.ubbcluj.map.socialnetwork.repository.paging.Page;
import ro.ubbcluj.map.socialnetwork.repository.paging.Pageable;
import ro.ubbcluj.map.socialnetwork.repository.paging.PagingRepository;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class PrietenieDBPagingRepository extends PrietenieDBRepository implements PagingRepository<Tuple<Long, Long>, Prietenie> {

    private Connection connection;

    public PrietenieDBPagingRepository(PrietenieValidator validator, String url, String username, String password) {
        super(validator, url, username, password);
        try {
            this.connection = DriverManager.getConnection(url, username, password);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public Page<Prietenie> findAllOnPage(Pageable pageable, Long id) {
        List<Prietenie> friends = new ArrayList<>();

        try (
                PreparedStatement statement = connection.prepareStatement("""
            SELECT r.id1, r.id2, data
             FROM friends r
                      INNER JOIN users u1 ON u1.id = r.id1
                      INNER JOIN users u2 ON u2.id = r.id2
             WHERE r.id2 = ? OR r.id1 = ?
             LIMIT ? OFFSET ?

        """);
                PreparedStatement countStatement = connection.prepareStatement("""
            SELECT COUNT(*) AS count FROM requests WHERE id2 = ? OR id1 =?
        """)
        ) {
            statement.setLong(1, id);
            statement.setLong(2, id);
            statement.setInt(3, pageable.getPageSize());
//            int offset = pageable.getPageSize() * (Math.max(pageable.getPageNr() ,1)-1);
            statement.setInt(4, pageable.getPageSize() * pageable.getPageNr());
            ResultSet resultSet = statement.executeQuery();

            while (resultSet.next()) {
                Long id1 =  resultSet.getLong("id1");
                Long id2 = resultSet.getLong("id2");
                Timestamp date = resultSet.getTimestamp("data");

                Prietenie prietenie = new Prietenie();
                prietenie.setId(new Tuple<>(id1, id2));

                friends.add(prietenie);
            }

                countStatement.setLong(1, id);
                countStatement.setLong(2,id);
                ResultSet countResultSet = countStatement.executeQuery();
                int count = 0;
                if (countResultSet.next()) {
                    count = countResultSet.getInt("count");
                }

            return new Page<>(friends, count);

        } catch (SQLException ex) {
            ex.printStackTrace();
            throw new RuntimeException(ex);
        }

    }
}
