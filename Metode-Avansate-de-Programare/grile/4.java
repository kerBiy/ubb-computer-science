class AA<E, T>{
    private E e;
    private T t;
    public void setValueE(E e){ this.e = e;}
    public void setValueT(T t){ this.t = t;}
    public E getValue() { return e; }
    public T getValue1() { return t; }
}

class Test {
    public static void main(String[] args) {
        AA bb = new AA<Integer, String>();
        bb.setValueE(1010);
        bb.setValueE("asfd");
        System.out.print(bb.getValue() + " " + bb.getValue1());
    }
}

// Rezultat: asfd null
// Deoarece variabila bb este de tip general, nu se mai face verificare cand atribuim string in loc de integer.