//class A {
//    public int x = 0;
//}
//class G10 {
//    public A foo() {
//        A a = new A();
//        try {
//            a.x = 1;
//            throw new NullPointerException();
//        } catch (Exception e) {
//            a.x = 2;
//            return a;
//        } finally {
//            a.x = 3;
//        }
//    }
//
//    public static void main (String[] args) {
//        G10 ex = new G10();
//        System.out.println(ex.foo().x);
//    }
//}
//
//// rezultat: 3 (finally se apeleaza or ce ar fi)