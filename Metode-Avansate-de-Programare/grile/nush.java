interface MyInterface {
    protected int X = 10;
    int y;
    int Z = 20;

    default int x() {
        return 0;
    }

    abstract void foo();

    final int f(int x);
}

public class nush {
}
