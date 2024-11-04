public class HorrorMovie extends Movie {
    private boolean intensityFear;

    public HorrorMovie(String name, int year, boolean intensityFear) {
        super(name, year);
        this.intensityFear = intensityFear;
    }

    public boolean isIntensityFear() {
        return intensityFear;
    }

    public void setIntensityFear(boolean intensityFear) {
        this.intensityFear = intensityFear;
    }
}
