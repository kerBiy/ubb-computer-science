class A{
    int i;
    public A(int i){
        System.out.print("A()");
    }
}

class B extends A{
    float i = 3;
    public B(){
        System.out.print("B()");
    }
}

public class AB extends B{
    public static void main(String argv[]){
        AB[] x= new AB[]{new AB(), new AB()};
        for (AB obj: x) {
            obj.testMethodCA("AB");
        }
    }
    public void testMethodCA(String s){
        System.out.println(s);
    }
}

// eroare in constructor b
// nu gaseste constructor fara parametri in superclasa