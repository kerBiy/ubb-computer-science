public class ActionMovie extends Movie{
    private boolean isThriller;

    public ActionMovie(String name, int year, boolean isThriller) {
        super(name, year);
        this.isThriller = isThriller;
    }

    public boolean isThriller() {
        return isThriller;
    }

    public void setThriller(boolean thriller) {
        isThriller = thriller;
    }
}
