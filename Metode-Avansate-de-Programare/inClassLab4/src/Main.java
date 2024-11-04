import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        ArrayList<Movie> movies = new ArrayList<>();
        movies.add(new Movie("movie1", 1999));
        movies.add(new HorrorMovie("movie2", 2000, true));
        movies.add(new ActionMovie("movie3", 2001, false));
        movies.add(new HorrorMovie("movie4", 2002, false));

        for (Movie movie : movies) {
            if (movie instanceof HorrorMovie) {
                System.out.println(movie);
            }
        }

        List<String> lines = new ArrayList<String>();

        try (BufferedReader reader = new BufferedReader(new FileReader("/Users/alexbalta/Developer/ubb-computer" +
                "-science/Metode-Avansate-de-Programare/inClassLab4/src/fisier.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                lines.add(line);
            }
        } catch (IOException e) {
            System.out.println("Eroare la citirea fisierului: " + e.getMessage());
        }

        for (String line : lines) {
            if (line.contains("test")) {
                System.out.println(line);
            }
        }

        List<String> words= new ArrayList<>();

        try (BufferedReader reader = new BufferedReader(new FileReader("/Users/alexbalta/Developer/ubb-computer" +
                "-science/Metode-Avansate-de-Programare/inClassLab4/src/cuvinte.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                words.add(line);
            }
        } catch (IOException e) {
            System.out.println("Eroare la citirea fisierului: " + e.getMessage());
        }

        int maxLength = 0;
        String longestWord = "";

        for (String word : words) {
            if (word.length() > maxLength) {
                maxLength = word.length();
                longestWord = word;
            }
        }
        System.out.println(longestWord);


        List<String> random = new ArrayList<>();

        for (int i = 0; i < 5; ++i) {
            String randomNumber = String.valueOf(Math.random());
            random.add(randomNumber);
        }

        try (BufferedWriter writer = new BufferedWriter(new FileWriter("/Users/alexbalta/Developer/ubb-computer" +
                "-science/Metode-Avansate-de-Programare/inClassLab4/src/random.txt"))) {
            for (String word : random) {
                writer.write(word);
                writer.newLine();
            }
        } catch (IOException e) {
            System.out.println("Eroare la scriere in fisierului CSV: " + e.getMessage());
        }




    }
}