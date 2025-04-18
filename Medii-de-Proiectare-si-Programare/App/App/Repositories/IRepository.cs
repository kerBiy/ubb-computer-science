namespace App.Repositories;

public interface IRepository<TId, TEntity>
{
    TEntity? FindOne(TId id);
    IEnumerable<TEntity> FindAll();
    TEntity? Save(TEntity entity);
    TEntity? Delete(TId id);
    TEntity? Update(TEntity entity);
}