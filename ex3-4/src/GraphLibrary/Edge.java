package GraphLibrary;

public class Edge<E, L> {

    private E label = null;
    private double weight = 0;

    /**
     * Init an {@code GraphLibrary.Edge} with the given {@code label}
     *
     * @param label name of the edge
     */
    public Edge(E label) {
        this.label = label;
    }

    /**
     * Set the {@code weight} of the {@code edge}
     *
     * @param weight
     */
    public void setWeight(double weight) {
        this.weight = weight;
    }

    /**
     * @return the {@code weight} of the {@code edge}
     */
    public double getWeight() {
        return this.weight;
    }

    /**
     * @return the {@code label} of the {@code edge}
     */
    public E getLabel() {
        return this.label;
    }

    @Override
    public String toString() {
        return "" + this.weight;
    }

    public Vertex<L,E> getDestination() {
        Vertex<L,E> destination = new Vertex<L, E>((L) this.label);
        return destination;
    }
}
