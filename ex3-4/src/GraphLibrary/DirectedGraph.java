package GraphLibrary;
import java.util.*;

public class DirectedGraph<T> extends Graph<T> {
    public DirectedGraph() {
        super();
    }

    public DirectedGraph(Set<Edge<T>> edges) {
        super(edges);
    }

    @Override
    public boolean isDirected() {
        return true;
    }
}

