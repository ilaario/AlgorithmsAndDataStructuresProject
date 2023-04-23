package GraphLibrary;
import java.util.Objects;
import java.util.Set;

public class Node<T> implements Comparable<Node<T>> {
    private T value;

    // Constructor
    public Node(T value) {
        this.value = value;
    }

    // Get node value
    public T getValue() {
        return this.value;
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
        return 63 * value.hashCode();
    }

    // Returns the node value as string
    @Override
    public String toString() {
        return "Node{Value: " + value.toString() + "}";
    }

    @Override
    public int compareTo(Node<T> o) {
        return 0;
    }
}

