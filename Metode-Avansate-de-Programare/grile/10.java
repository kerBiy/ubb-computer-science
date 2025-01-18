import java.util.stream.Stream;

class G226 {
public static void main (String[] args) {
Stream<String> ss = Stream. of("ee ", "xe ", "xe y ");
        var res = ss.filter(s -> {
                    System.out.print(s);
                    return s.contains("x");
            }).map ((x) -> {
                System.out.print(x);
                return x.toUpperCase();
            }).reduce ((x, y) -> x + y);
        res.ifPresent(System.out::print);
}}

// Rezultat: ee xe xe xe y xe y XE XE Y
// Basic