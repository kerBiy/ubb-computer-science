package ro.ubbcluj.map.socialnetwork.repository.paging;

public class Page<E> {

    private Iterable<E> elementsOnPage;
    private int totalNrOfElems;

    public Page(Iterable<E> elementsOnPage, int totalNrOfElems) {
        this.elementsOnPage = elementsOnPage;
        this.totalNrOfElems = totalNrOfElems;
    }

    public Iterable<E> getElementsOnPage() {
        return elementsOnPage;
    }

    public int getTotalNrOfElems() {
        return totalNrOfElems;
    }
}