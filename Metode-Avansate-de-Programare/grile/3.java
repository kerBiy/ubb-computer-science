import java.util.stream.Stream;

class R12 {
    public static void main (String[] args) {
        Stream<String> ss = Stream.of("asd ","bus ","aop ");

        var res = ss .filter(s -> {
                System.out.print(s);
                return s.contains("a");
            }).map ((x) -> {
                System.out.print(x);
                return x.toUpperCase();
            }).reduce("", (x, y) -> x + y) ;

        System.out.println(res);
}}

// Rezultat: asd asd bus aop aop ASD AOP
// ordinea operatilor (filter ul si map ul merg pe acelasi index impreuna pana la final)