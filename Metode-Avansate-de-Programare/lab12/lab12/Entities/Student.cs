namespace Entities
{
    public class Student
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string School { get; set; }

        public Student(int id, string name, string school)
        {
            Id = id;
            Name = name;
            School = school;
        }

        public override string ToString()
        {
            return $"{Id},{Name},{School}";
        }
    }
}