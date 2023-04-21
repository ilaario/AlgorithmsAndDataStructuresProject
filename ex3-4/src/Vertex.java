import java.util.Enumeration;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.Set;

public class Vertex<L, E> implements Comparable<Vertex<L, E>> {
    private L label = null;
    private Hashtable<L, Edge<E,L>> adjacentList = null;
    private double distance = 0;
    private Vertex<L, E> pi = null;

    /**
     * Create a new {@code Vertex} with the given {@code label}
     */
    public Vertex(L label) {
        this.adjacentList = new Hashtable<>();
        this.label = label;
    }

    /**
     * @return the {@code label} of the {@code vertex}
     */
    public L getLabel() {
        return this.label;
    }

    /**
     * Set the {@code distance} from the {@code parent} vertex
     *
     * @param distance
     */
    public void setDistance(double distance) {
        this.distance = distance;
    }

    /**
     * @return the {@code distance} from the {@code parent} vertex
     */
    public double getDistance() {
        return this.distance;
    }

    /**
     * Set the {@code parent} {@code Vertex}
     *
     * @param pi {@code parent} {@code Vertex}
     */
    public void setPi(Vertex<L, E> pi) {
        this.pi = pi;
    }

    /**
     * @return the {@code parent} {@code Vertex}
     */
    public Vertex<L, E> getPi() {
        return pi;
    }

    /**
     * @return the total number of {@code edge} outgoing
     */
    public int getOutDegree() {
        return adjacentList.size();
    }

    /**
     * @return a new {@link Set} of vertex label containing all the vertices
     *         adjacents
     */
    public Set<L> getAdjacentVerticesLabel() {
        Set<L> adjacent = new HashSet<>();

        for (L a : adjacentList.keySet()) {
            adjacent.add(a);
        }
        return adjacent;
    }

    /**
     * @return a new {@link Set} of {@link Edge} containing all the edges
     */
    public Set<Edge<E,L>> getEdges() {
        Set<Edge<E,L>> ris = new HashSet<>();
        Enumeration<Edge<E,L>> edge = adjacentList.elements();

        while (edge.hasMoreElements()) {
            Edge<E,L> e = edge.nextElement();
            ris.add(e);
        }

        return ris;
    }

    /**
     * Check if the given {@code vertexLabel} is an adjacent of the current
     * {@code Vertex}
     *
     * @param vertexLabel label of the vertex to check if is adjacent
     * @return {@code TRUE} iff {@code vertexLabel} is an adjacent of the current
     *         {@code Vertex}, {@code FALSE} otherwise
     * @throws NullPointerException iff {@code vertexLabel} is {@code null}
     */
    public boolean hasAdjacent(L vertexLabel) throws NullPointerException {
        if (vertexLabel == null)
            throw new NullPointerException("hasAdjacent(vertexLabel): vertexLabel must not be null");

        return adjacentList.containsKey(vertexLabel);
    }

    /**
     * @param edge
     * @return {@code TRUE} iff {@code edge} is an {@link Edge} of the current
     *         {@code Vertex}, {@code FALSE} otherwise
     * @throws NullPointerException iff {@code edge} is {@code null}
     */
    public boolean hasEdge(Edge<E,L> edge) throws NullPointerException {
        if (edge == null)
            throw new NullPointerException("hasEdge(edge): edge must not be null");

        return adjacentList.contains(edge);
    }

    /**
     * @param adjacentLabel of the vertex adjacent
     * @param edgeLabel     of the edge
     * @return {@code TRUE} iff added successfully, {@code FALSE} otherwise
     * @throws NullPointerException iff {@code adjacentLabel} OR {@code edgeLabel}
     *                              are {@code null}
     */
    public boolean addAdjacent(L adjacentLabel, E edgeLabel) throws NullPointerException {
        if (adjacentLabel == null)
            throw new NullPointerException("addAdjacent(adjacentLabel, edgeLabel): adjacentLabel must not be null");

        if (edgeLabel == null)
            throw new NullPointerException("addAdjacent(adjacentLabel, edgeLabel): edgeLabel must not be null");

        Edge<E,L> edge = new Edge<>(edgeLabel);

        return (adjacentList.putIfAbsent(adjacentLabel, edge) == null);
    }

    /**
     * @param adjacentLabel
     * @return the {@code Edge} on success, {@code null} otherwise
     * @throws NullPointerException iff {@code adjacentLabel} is {@code null}
     * @see Edge
     */
    public Edge<E,L> getEdge(L adjacentLabel) throws NullPointerException {
        if (adjacentLabel == null)
            throw new NullPointerException("getEdge(adjacentLabel): adjacentLabel must not be null");

        return adjacentList.get(adjacentLabel);
    }

    /**
     * Retrieve the {@code weight} of the {@code edge} with the adjacent vertex with
     * the given {@code adjacentLabel}
     *
     * @param adjacentLabel label of the {@code adjacent} vertex
     * @return the {@code edge} {@code weight}
     * @throws NullPointerException
     *                              <ul>
     *                              <li>if {@code adjacentLabel} is
     *                              {@code null}</li>
     *                              <li>if there is no {@code edge} between the
     *                              vertex and his {@code adjacent}</li>
     *                              </ul>
     */
    public double getEdgeWeight(L adjacentLabel) throws NullPointerException {
        Edge<E,L> edge = getEdge(adjacentLabel);

        if (edge == null)
            throw new NullPointerException("getEdgeWeight(adjacentLabel): the edge between " + this.label + " and "
                    + adjacentLabel + " does not exists");

        return edge.getWeight();
    }

    /**
     * @param adjacentLabel the adjacent to remove
     * @return the edge of the adjacent removed on success, {@code null} otherwise
     * @throws NullPointerException iff {@code adjacentLabel} is {@code null}
     */
    public Edge<E,L> removeEdge(L adjacentLabel) throws NullPointerException {
        if (adjacentLabel == null)
            throw new NullPointerException("remove(adjacentLabel): adjacentLabel must not be null");

        return adjacentList.remove(adjacentLabel);
    }

    /**
     * Remove all the adjacents vertices
     */
    public void clearEdges() {
        adjacentList.clear();
    }

    @Override
    public String toString() {
        return "{" + this.label + "}";
    }

    public String adjacentsToString() {
        return adjacentList.toString();
    }

    @Override
    public int compareTo(Vertex<L, E> o) {
        return 0;
    }
}
