package GraphLibrary;
import java.util.Comparator;
import java.util.Objects;
import java.util.Set;

public class Node<T> implements Comparable<Node<T>> {
    private T value;
    private double distance;
    private long id;

    public Node(T value) {
        this.value = value;
        this.distance = Double.POSITIVE_INFINITY;
    }

    // Constructor
    public Node(T value, long id) {
        this.value = value;
        this.distance = Double.POSITIVE_INFINITY;
        this.id = id;
    }

    // Get node value
    public T getValue() {
        return this.value;
    }

    public long getId() {
        return this.id;
    }

    public double getDistance() {
        return distance;
    }

    public void setDistance(double distance) {
        this.distance = distance;
    }

    public int compare(Node<T> o1, Node<T> o2) {
        return Double.compare(o1.distance, o2.distance);
    }

    // Checks if both objects are the same
    @Override
    @SuppressWarnings("unchecked")
    public boolean equals(Object toCheck) {
        if (toCheck == null)
            return false;
        if (toCheck == this)
            return true;
        if (!(toCheck instanceof Node<?>))
            return false;

        Node<T> nodeToCheck = (Node<T>) toCheck;
        return Objects.equals(value, nodeToCheck.value);
    }

    // Calculates the hash code of a node
    @Override
    public int hashCode() {
        return value.hashCode();
    }

    // Returns the node value as string
    @Override
    public String toString() {
        return value.toString();
    }


    @Override
    public int compareTo(Node<T> o) {
        return Double.compare(this.distance, o.distance);
    }
}

