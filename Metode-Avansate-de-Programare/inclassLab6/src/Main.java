import java.util.List;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) {
        // a

        List<String> words = List.of("Ana", "are", "mere");
        words.stream().map(String::toUpperCase).forEach(System.out::println);

        // b

        List<Dog> dogs = List.of(new Dog("Sam", 11), new Dog("Rex", 15), new Dog("Luna", 3));

        System.out.println("2.1.");
        dogs.stream()
                .filter(dog -> dog.getAge() > 10)
                .forEach(System.out::println);

        System.out.println("2.2.");
        List<Dog> sortedDogs = dogs.stream()
                .sorted(Comparator.comparing(Dog::getAge).reversed())
                .toList();
        sortedDogs.forEach(System.out::println);

        System.out.println("2.3.");
        dogs.stream()
                .filter(dog -> "Sam".equals(dog.getName()))
                .forEach(System.out::println);

        System.out.println("2.4.");
        dogs.stream()
                .map(Dog::getName)
                .forEach(System.out::println);

        // c

        List<Integer> ints = List.of(1, 2, 3, 4, 5);
        ints.stream().map(e -> e * e).forEach(System.out::println);

        // d

        List<Mall> malls = List.of(
            new Mall("Mall A", "Manager A", 2010, 1000000.0),
            new Mall("Mall B", "Manager B", 2015, 2000000.0),
            new Mall("Mall C", "Manager C", 2020, 1500000.0),
            new Mall("Mall D", "Manager D", 2018, 2500000.0)
        );

        malls.forEach(mall -> mall.setProfit(mall.getProfit() * 3));

        Mall maxProfitMall = malls.stream()
                .max(Comparator.comparing(Mall::getProfit))
                .orElse(null);

        System.out.println(maxProfitMall);

    }
}