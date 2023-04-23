package GraphLibrary;
import java.util.*;

public class NotOrientedGraph<T> extends Graph<T> {
    public NotOrientedGraph() {
        super();
    }

    public NotOrientedGraph(Set<Edge<T>> edges) {
        super(edges);
    }

    @Override
    public boolean isDirected() {
        return false;
    }

    @Override
    public int getEdgeSize() {
        return super.getEdgeSize() / 2;
    }

    @Override
    public boolean addEdge(Edge<T> edge) {
        return (edge == null) ? false : super.addEdge(edge.getSource(), edge.getDestination(), edge.getWeight()) && super.addEdge(edge.getDestination(), edge.getSource(), edge.getWeight());
    }

    @Override
    public boolean addEdge(T src, T dest, int weight) {
        return super.addEdge(new Node<>(src), new Node<>(dest), weight) && super.addEdge(new Node<>(dest), new Node<>(src), weight);
    }

    @Override
    public boolean addEdge(Node<T> src, Node<T> dest, int weight) {
        return super.addEdge(src, dest, weight) && super.addEdge(dest, src, weight);
    }

    @Override
    public boolean addEdge(T src, T dest, double weight) {
        return super.addEdge(new Node<>(src), new Node<>(dest), weight) && super.addEdge(new Node<>(dest), new Node<>(src), weight);
    }

    @Override
    public boolean addEdge(Node<T> src, Node<T> dest, double weight) {
        return super.addEdge(src, dest, weight) && super.addEdge(dest, src, weight);
    }

    @Override
    public boolean removeEdge(Edge<T> edge) {
        return (edge == null) ? false : super.removeEdge(edge.getSource(), edge.getDestination()) && super.removeEdge(edge.getDestination(), edge.getSource());
    }

    @Override
    public boolean removeEdge(Node<T> src, Node<T> dest) {
        return super.removeEdge(src, dest) && super.removeEdge(dest, src);
    }
}

