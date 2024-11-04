import java.util.List;

public class ElementUtils<T> {
    public T lastEntity(List<T> list) {
        return list.getLast();
    }
}
