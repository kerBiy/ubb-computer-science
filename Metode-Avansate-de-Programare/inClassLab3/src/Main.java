import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        // 1.
        List<Circle> list = new ArrayList<>();

        double random_number = Math.random();
        while(random_number > 0.01) {
            list.add(new Circle(random_number));
           random_number = Math.random();
        }

        for (Circle circle : list) {
            double area = Math.pow(circle.getRadius(), 2) * Math.PI;
            System.out.println(area);
        }

        // 2.
        HashMap<String, String> map = new HashMap<>();
        map.put("a1234", "Steve Jobs");
        map.put("a1235", "Scott");
        map.put("a1236", "Jeff Bazos");
        map.put("a1237", "Larry");
        map.put("a1238", "Bill Gates");

        for (String key : map.keySet()) {
            var value = map.get(key);
            System.out.println(key + ": " + value);
        }

        // 3.
        String key = "A1234";
        var value = map.get(key.toLowerCase());
        System.out.println(value);


    }
}