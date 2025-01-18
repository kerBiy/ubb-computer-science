import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

class EmailSender {
    private String message;
    public EmailSender(String s) { message=s;}
    public String run() {
        System.out.print(message+" ");
        return "sent";
    }
}
class G30 {
    static final Integer NTHREDS=1;
    public static void main(String[] args)
            throws InterruptedException {
        ExecutorService executor =
                Executors.newFixedThreadPool(NTHREDS);
        List<Callable<String>> l=new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            Callable<String> worker = new EmailSender("m"+i)::run;
            l.add(worker);
        }
        List<Future<String>> futures = executor.invokeAll(l);
        executor.shutdown();
    }
}

// Rezultat: m0 m1 m2 sau o permutare
// se creaza thread urile si se apleaza pentru fiecare handler ul acestuia (metoda run)