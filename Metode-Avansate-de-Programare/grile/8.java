//interface Formula {
//    double calculate(double a);
//}
//
//class A implements Formula {
//    static int var1 =100;
//    double x=9;
//    public double calculate (double a) {
//        double x =A.this.var1 * a;
//        x++;
//        Formula f = (double b) -> {
//            return Math.abs(x);
//        };
//        return f.calculate(a);
//    }
//}
//
//class R11 {
//    public static void main (String[] args) {
//        System.out.printf("%.0f", new A().calculate(10));
//    }
//}
//
//// Rezultat: eroare la compilare
//// variabila x trebuie sa fie final sau effectively final (restrictie din java) adica sa nu fie modificata dupa
//// initializare