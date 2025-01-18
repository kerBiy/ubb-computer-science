class Contact {
    static public String Name = "Mapescu I ";

    class Numar1 {
        private String nr = "0987654321";

        public String ContactNou() {
            return Name + nr;
        }
    }
    static class Numar2 {
        private String nr = "0945654321";

        public String ContactNou() {
            return Name + nr;
        }
    }
}

class G12 {
    public static void main(String[] args) {
        Contact c=new Contact();
        Contact.Numar1 c1= c.new Numar1();
        Contact.Numar2 c2= new Contact.Numar2();
        System.out.println(c1.ContactNou());
        System.out.println(c2.ContactNou());
    }

}

// Rezultat: errare la linia 15
// Nu poti sa faci o metoda statica folsoind variabile specifice instantelor