package ro.ubbcluj.map.socialnetwork.repository.PagingRepository;

import ro.ubbcluj.map.socialnetwork.domain.CererePrietenie;
import ro.ubbcluj.map.socialnetwork.domain.Tuple;
import ro.ubbcluj.map.socialnetwork.domain.Utilizator;
import ro.ubbcluj.map.socialnetwork.domain.validators.CerereValidator;
import ro.ubbcluj.map.socialnetwork.repository.CerereDBRepository;
import ro.ubbcluj.map.socialnetwork.repository.paging.Page;
import ro.ubbcluj.map.socialnetwork.repository.paging.Pageable;
import ro.ubbcluj.map.socialnetwork.repository.paging.PagingRepository;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class CerereDBPagingRepository extends CerereDBRepository implements PagingRepository<Tuple<Long,Long>, CererePrietenie> {

    private Connection connection;

    public CerereDBPagingRepository(CerereValidator validator, String url, String username, String password) {
        super(validator, url, username, password);
        try {
            this.connection = DriverManager.getConnection(url, username, password);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public Page<CererePrietenie> findAllOnPage(Pageable pageable, Long id) {
        List<CererePrietenie> friendRequests = new ArrayList<>();

        try (
                PreparedStatement statement = connection.prepareStatement("""
            SELECT r.id1, r.id2, status, date
             FROM requests r
                      INNER JOIN users u1 ON u1.id = r.id1
                      INNER JOIN users u2 ON u2.id = r.id2
             WHERE r.id2 = ?
             LIMIT ? OFFSET ?
             
        """);
                PreparedStatement countStatement = connection.prepareStatement("""
            SELECT COUNT(*) AS count FROM requests WHERE id2 = ?
        """)
        ) {
            statement.setLong(1, id);
            statement.setInt(2, pageable.getPageSize());
            statement.setInt(3, pageable.getPageSize() * pageable.getPageNr());
            ResultSet resultSet = statement.executeQuery();

            while (resultSet.next()) {
                friendRequests.add(getCererePrietenie(resultSet));
            }

            countStatement.setLong(1, id);
            ResultSet countResultSet = countStatement.executeQuery();
            int count = 0;
            if (countResultSet.next()) {
                count = countResultSet.getInt("count");
            }

            return new Page<>(friendRequests, count);
        } catch (SQLException ex) {
            throw new RuntimeException(ex);
        }
    }

    private static CererePrietenie getCererePrietenie(ResultSet resultSet) throws SQLException {
        Long id1 = resultSet.getLong("id1");
        Long id2 = resultSet.getLong("id2");
        String status = resultSet.getString("status");
        Timestamp date = resultSet.getTimestamp("date");

        CererePrietenie cererePrietenie = new CererePrietenie();
        cererePrietenie.setId(new Tuple<>(id1, id2));
        cererePrietenie.setStatus(status);
        cererePrietenie.setDate(date.toLocalDateTime());
        return cererePrietenie;
    }
}

