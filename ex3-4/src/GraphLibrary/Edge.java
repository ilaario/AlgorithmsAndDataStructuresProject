package GraphLibrary;
import java.util.Objects;

public class Edge<T> implements Comparable<Edge<T>> {
    private final double weight;
    private final Node<T> src;
    private final Node<T> dest;

    // Edge Constructor
    public Edge(T src, T dest, int weight) {
        this(new Node<>(src), new Node<>(dest), weight);
    }

    // Edge Constructor
    public Edge(Node<T> src, Node<T> dest, int weight) {
        this.src = src;
        this.dest = dest;
        this.weight = weight;
    }

    // Edge Constructor
    public Edge(T src, T dest, double weight) {
        this(new Node<>(src), new Node<>(dest), weight);
    }

    // Edge Constructor
    public Edge(Node<T> src, Node<T> dest, double weight) {
        this.src = src;
        this.dest = dest;
        this.weight = weight;
    }

    // Returns node source
    public Node<T> getSource() {
        return this.src;
    }

    // Returns node destination
    public Node<T> getDestination() {
        return this.dest;
    }

    // Returns weight of an edge
    public double getWeight() {
        return this.weight;
    }

    // Checks if two objects are the same
    @Override
    @SuppressWarnings("unchecked")
    public boolean equals(Object toCheck) {
        if (toCheck == null)
            return false;
        if (toCheck == this)
            return true;
        if (!(toCheck instanceof Edge<?>))
            return false;

        Edge<T> edgeToCheck = (Edge<T>) toCheck;
        return Objects.equals(this.src, edgeToCheck.src) && Objects.equals(this.dest, edgeToCheck.dest);
    }

    // Calculates an hash code
    @Override
    public int hashCode() {
        return src.hashCode() + (63 * dest.hashCode());
    }

    // Returns a string containing an edge's source and destination
    @Override
    public String toString() {
        return "Edge{Source: " + this.src.toString() + ", Destination: " + this.dest.toString() + ", Weight: " + this.weight + "}";
    }

    // Compare the weight of two edges
    @Override
    public int compareTo(Edge<T> e) {
        if (this.weight <= e.weight) {
            return -1;
        }
        return 1;
    }
}

