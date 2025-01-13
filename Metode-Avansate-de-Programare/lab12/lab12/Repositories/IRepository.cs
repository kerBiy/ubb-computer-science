namespace Repositories
{
    public interface IRepository<ID, E>
    {
        IEnumerable<E> FindAll();
        E FindById(ID id);
        void Add(E entity);
        void Update(ID id, E entity);
        void Delete(ID id);
    }
}