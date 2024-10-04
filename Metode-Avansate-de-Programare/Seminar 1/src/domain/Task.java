package domain;

import java.util.Objects;

public class Task {
    private String id;
    private String desc;

    public Task(String id, String desc) {
        this.id = id;
        this.desc = desc;
    }

    public String getId() {
        return id;
    }

    public String getDesc() {
        return desc;
    }

    @Override
    public String toString() {
        return "Task{" +
                "id='" + id + '\'' +
                ", desc='" + desc + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Task task = (Task) o;
        return Objects.equals(id, task.id) && Objects.equals(desc, task.desc);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, desc);
    }
}
