import java.net.*;
import java.io.*;
 
public class Client1 {
    public static void main(String args[]) throws Exception {
        Socket c = new Socket("127.0.0.1", 1234);
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int a, b, s;
        System.out.print("a = ");
        a = Integer.parseInt(reader.readLine());
        System.out.print("b = ");
        b = Integer.parseInt(reader.readLine());
        
        DataInputStream socketIn = new DataInputStream(c.getInputStream());
        DataOutputStream socketOut = new DataOutputStream(c.getOutputStream());
        
        socketOut.writeShort(a);
        socketOut.writeShort(b);
        socketOut.flush();
        
        s = socketIn.readUnsignedShort();
        System.out.println("s = " + s);
        
        reader.close();
        c.close();  
    }
 
}