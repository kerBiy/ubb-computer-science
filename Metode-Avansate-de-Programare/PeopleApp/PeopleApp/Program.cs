namespace PeopleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            // a. 
            Person person = new Person();
            person.Greet();

            // b. 
            Student student = new Student();
            student.SetAge(21);
            student.Greet();
            student.ShowAge();

            // c. 
            Professor professor = new Professor();
            professor.SetAge(30);
            professor.Explain();
            professor.Greet();
        }
    }
}