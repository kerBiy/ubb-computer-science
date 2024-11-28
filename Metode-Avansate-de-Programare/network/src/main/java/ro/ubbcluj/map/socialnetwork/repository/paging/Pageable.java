package ro.ubbcluj.map.socialnetwork.repository.paging;


public class Pageable  {

    private int pageNr;
    private int pageSize;

    public Pageable(int pageNr, int pageSize) {
        this.pageNr = pageNr;
        this.pageSize = pageSize;
    }

    public int getPageNr() {
        return pageNr;
    }

    public int getPageSize() {
        return pageSize;
    }
}
