import java.util.List;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.function.Supplier;

public class Main {
    public static void main(String[] args) {
//        List<Square> squares = List.of(new Square(2), new Square(4));
//        List<Circle> circles = List.of(new Circle(2), new Circle(4));
//        Area<Square> areaSquare = x -> x.getLength() * x.getLength();
//        Area<Circle> areaCircle = x -> x.getRadius() * x.getRadius() * Math.PI;

//        Area<Square> areaSquare = Main::squareArea;
//        Area<Circle> areaCircle = Main::circleArea;
//
//        squares.forEach(x -> System.out.println(areaSquare.getArea(x)));
//        circles.forEach(x -> System.out.println(areaCircle.getArea(x)));

//        Predicate<String> evenLength = s -> s.startsWith("P");
//        List<String> list = List.of("Paul", "Razvan", "Giorgi", "Ioan", "Andrei");
//        printByCriteria(list, evenLength);

//        Predicate<Character> isVowel = x -> "aeiou".contains(String.valueOf(x));
//
//        Function<String, Integer> converterMethodReference= Integer::valueOf;
//
//        Function<String, String> converterPasareasca = x -> {
//            StringBuilder res = new StringBuilder();
//            for (int i = 0; i < x.length(); i++) {
//                if (isVowel.test(x.charAt(i))) {
//                    res.append("p");
//                }
//                res.append(x.charAt(i));
//            }
//
//            return res.toString();
//        };
//
//        System.out.println(converterMethodReference.apply("14"));
//        System.out.println(converterPasareasca.apply("mama merge la piata"));

//        Supplier<Circle> supplier= Circle::new;

        List<Integer> list = List.of(1,2,3,4,5);
        System.out.println(list.stream().reduce((a,b) -> a+b).get());


    }

    public static double squareArea(Square square) {
        return square.getLength() * square.getLength();
    }

    public static double circleArea(Circle circle) {
        return circle.getRadius() * circle.getRadius() * Math.PI;
    }

    public static <E> void printByCriteria(List<E> list, Predicate<E> predicate) {
        list.forEach(elem -> {
           if (predicate.test(elem)) {
               System.out.println(elem);
           }
        });
    }
}