package GraphLibrary.GenericPriorityQueue;

import GraphLibrary.Vertex;

import java.util.Comparator;

public class GenericComparator<L, E> implements Comparator<Vertex<L, E>> {
    @Override
    public int compare(Vertex<L, E> o1, Vertex<L, E> o2) {
        if (o1.getDistance() > o2.getDistance()) {
            return 1;
        } else if (o1.getDistance() < o2.getDistance()) {
            return -1;
        } else {
            return 0;
        }
    }
}
