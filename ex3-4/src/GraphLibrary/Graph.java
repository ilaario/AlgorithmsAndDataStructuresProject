package GraphLibrary;

/*import java.util.HashSet;
import java.util.Hashtable;
import java.util.Set;
import java.util.Map.Entry;

public class Graph<T, S> {
    private Hashtable<T, Vertex<T, S>> vertices = null;
    private GraphType type = GraphType.DIRECTED;

    /**
     * Creazione di un {@code grafo} vuoto – O(1)

    public Graph() {
        this.vertices = new Hashtable<>();
    }

    /**
     * @return the {@code type} of the {@code GraphLibrary.Graph}

    public GraphType getType() {
        return this.type;
    }

    /**
     * Verifica se il {@code grafo} è {@code diretto} – O(1)

    public boolean isDirected() {
        return this.type == GraphType.DIRECTED;
    }

    /**
     * Determinazione del numero di {@code nodi} – O(1)

    public int getNumberVertices() {
        return this.vertices.size();
    }

    /**
     * Determinazione del numero di {@code archi} – O(n)

    public int getNumberEdges() {
        int sum = 0;

        for (T a : vertices.keySet()) {
            sum += vertices.get(a).getOutDegree();
        }

        return (isDirected() ? sum : sum / 2);
    }

    /**
     * Aggiunta di un {@code nodo} – O(1)
     *
     * @param vertexLabel
     * @return {@code TRUE} se il nodo è aggiunto con successo, {@code FALSE} se esiste già
     *         a vertex with the same {@code vertexLabel}
     * @throws NullPointerException se {@code vertexLabel} è {@code null}
     * @see Vertex

    public boolean addVertex(T vertexLabel) throws NullPointerException {
        if (vertexLabel == null)
            throw new NullPointerException("addVertex(vertexLabel): vertexLabel must not be null");

        Vertex<T, S> newVertex = new Vertex<>(vertexLabel);

        return (vertices.putIfAbsent(vertexLabel, newVertex) == null);
    }

    /**
     * Restituisce il {@code grafo} contiene un dato {@code nodo} – opzionale
     * @param vertexLabel
     * @return Il {@code GraphLibrary.Vertex} con la {@code vertexLabel}, {@code null} se non esiste
     * @throws NullPointerException se {@code vertexLabel} è {@code null}
     * @see Vertex

    public Vertex<T, S> getVertex(T vertexLabel) throws NullPointerException {
        if (vertexLabel == null)
            throw new NullPointerException("getVertex(vertexLabel): vertexLabel must not be null");

        return vertices.get(vertexLabel);
    }

    /**
     * Verifica se il {@code grafo} contiene un dato {@code nodo} – O(1)
     *
     * @param vertexLabel
     * @return {@code TRUE} se {@code vertexLabel} è contenuta nel
     *         {@code GraphLibrary.Graph}, altrimenti {@code FALSE}
     * @throws NullPointerException se {@code vertexLabel} è {@code null}

    public boolean containsVertex(T vertexLabel) throws NullPointerException {
        if (vertexLabel == null)
            throw new NullPointerException("containsVertex(vertexLabel): vertexLabel must not be null");

        return vertices.containsKey(vertexLabel);
    }

    /**
     * Verifica se il {@code grafo} contiene un dato {@code arco} – O(1)
     * @param vertexA
     * @param vertexB
     * @return {@code TRUE} se esiste un {@code edge} tra {@code vertexA} e
     *         {@code vertexB}, altrimenti {@code FALSE}
     * @throws NullPointerException
     *                              <ul>
     *                              <li>se {@code vertexA} is {@code null}</li>
     *                              <li>se {@code vertexB} is {@code null}</li>
     *                              <li>se non ci sono {@code GraphLibrary.Vertex} con la label
     *                              {@code vertexA} o con la label {@code vertexB}
     *                              in cui cercare </li>
     *                              </ul>

    public boolean containsEdge(T vertexA, T vertexB) throws NullPointerException {
        if (vertexA == null)
            throw new NullPointerException("containsEdge(vertexA, vertexB): vertexA must not be null");

        if (vertexB == null)
            throw new NullPointerException("containsEdge(vertexA, vertexB): vertexB must not be null");

        Vertex<T, S> firstVertex = vertices.get(vertexA);
        Vertex<T, S> secondVertex = vertices.get(vertexB);

        return firstVertex.hasAdjacent(vertexB) || secondVertex.hasAdjacent(vertexB);
    }

    /**
     * @return a new {@link Set} of vertices label

    public Set<T> getVerticesLabel() {
        Set<T> verts = new HashSet<>();
        for (T a : vertices.keySet()) {
            verts.add(a);
        }
        return verts;
    }

    /**
     * Recupero dei nodi del {@code grafo} – O(n)
     *
     * @return un nuovo {@link Set} di {@code GraphLibrary.Vertex}
     * @see Vertex

    public Set<Vertex<T, S>> getVertices() {
        Set<Vertex<T, S>> vertices = new HashSet<>();
        for (T vLabel : getVerticesLabel()) {
            vertices.add(getVertex(vLabel));
        }
        return vertices;
    }

    /**
     * Recupero degli archi del {@code grafo} – O(n)
     *
     * @return un nuovo {@code Set} di {@code GraphLibrary.Edge}
     * @see Edge

    public Set<Edge<S,T>> getEdges() {
        Set<Edge<S,T>> edges = new HashSet<>();

        for (T vLabel : this.vertices.keySet()) {
            for (Edge<S,T> b : getVertex(vLabel).getEdges()) {
                edges.add(b);
            }
        }

        return edges;
    }

    /**
     * Cancellazione di un {@code nodo} – O(n)
     * @param vertexLabel da rimuovere
     * @return il {@code GraphLibrary.Vertex} rimosso con la label
     * @throws NullPointerException se {@code vertexLabel} è {@code null}

    public Vertex<T, S> removeVertex(T vertexLabel) throws NullPointerException {
        if (vertexLabel == null)
            throw new NullPointerException("removeVertex(vertexLabel): vertexLabel must not be null");

        Vertex<T, S> ris = vertices.remove(vertexLabel);

        if (ris != null) {
            Set<T> verticesLabel = getVerticesLabel();

            for (T vLabel : verticesLabel) {
                Vertex<T, S> curr = this.vertices.get(vLabel);
                if (curr.hasAdjacent(vertexLabel)) {
                    curr.removeEdge(vertexLabel);
                }
            }
        }

        return ris;
    }

    /**
     * Recupero {@code vertexLabel} adiacenti di un dato {@code nodo} – O(1)
     * @param vertexLabel il nodo di cui si vogliono conoscere gli adiacenti
     * @return un {@link Set} di vertexLabel adiacenti al {@code vertexLabel}
     * @throws NullPointerException se {@code vertexLabel} è {@code null}

    public Set<T> getAdjacentVerticesLabel(T vertexLabel) throws NullPointerException, GraphException {
        if (vertexLabel == null)
            throw new NullPointerException("getAdjacentVerticesLabel(vertexLabel): vertexLabel must not be null");

        if (!vertices.containsKey(vertexLabel))
            return null;

        Vertex<T, S> vertex = vertices.get(vertexLabel);

        return vertex.getAdjacentVerticesLabel();
    }

    /**
     * Recupero {@code nodi} adiacenti di un dato {@code nodo} – O(1)
     * @param vertexLabel il nodo di cui si vogliono conoscere gli adiacenti
     * @return un {@link Set} di nodi adiacenti al {@code vertexLabel}
     * @throws NullPointerException se {@code vertexLabel} è {@code null}

    public Set<Vertex<T, S>> getAdjacentVertices(T vertexLabel) throws NullPointerException, GraphException {
        if (vertexLabel == null)
            throw new NullPointerException("getAdjacentVertices(vertexLabel): vertexLabel must not be null");

        if (!vertices.containsKey(vertexLabel))
            return null;

        Set<T> adjVerticesLabel = getAdjacentVerticesLabel(vertexLabel);

        Set<Vertex<T, S>> adjVertices = new HashSet<>();
        for (T adjLabel : adjVerticesLabel) {
            adjVertices.add(getVertex(adjLabel));
        }
        return adjVertices;
    }

    /**
     * Controlla se due {@code nodi} sono adiacenti – O(1)
     *
     * @param vertexFrom
     * @param vertexTo
     * @return {@code TRUE} se i due nodi sono adiacenti, altrimenti {@code FALSE}
     * @throws NullPointerException se {@code vertexFrom} O {@code vertexTo} sono
     *                              {@code null}

    public boolean areAdjacents(T vertexFrom, T vertexTo) throws NullPointerException {
        if (vertexFrom == null)
            throw new NullPointerException("areAdjacents(vertexFrom, vertexTo): vertexFrom must not be null");

        if (vertexTo == null)
            throw new NullPointerException("areAdjacents(vertexFrom, vertexTo): vertexTo must not be null");

        Vertex<T, S> firstVertex = vertices.get(vertexFrom);

        return firstVertex.hasAdjacent(vertexTo);
    }

    /**
     * Controlla se due {@code nodi} sono adiacenti e completi – O(1):
     * <ul>
     * <li>{@code vertexA} è adiacente a {@code vertexB}</li>
     * <li>{@code vertexB} è adiacente a {@code vertexA}</li>
     * </ul>
     * Per {@code UNDIRECTED} {@code GraphLibrary.Graph} {@link #areAdjacents(Object, Object)}
     * e {@link #areCompleteAdjacents(Object, Object)} ritornano lo stesso risultato
     *
     * @param vertexA
     * @param vertexB
     * @return {@code TRUE} se i due nodi sono adiacenti e completi,
     *         altrimenti {@code FALSE}
     *
     * @throws NullPointerException se {@code vertexA} O {@code vertexB} sono
     *                              {@code null}

    public boolean areCompleteAdjacents(T vertexA, T vertexB) {
        return areAdjacents(vertexA, vertexB) && areAdjacents(vertexB, vertexA);
    }

    /**
     * @param vertexFrom
     * @param vertexTo
     * @return the edge that connect {@code vertexFrom} with {@code vertexTo} on
     *         success, {@code null} otherwise
     * @throws NullPointerException iff {@code vertexFrom} OR {@code vertexTo} are
     *                              {@code null}

    public Edge<S,T> getEdge(T vertexFrom, T vertexTo) throws NullPointerException {
        if (vertexFrom == null)
            throw new NullPointerException("getEdge(vertexFrom, vertexTo): vertexFrom must not be null");

        if (vertexTo == null)
            throw new NullPointerException("getEdge(vertexFrom, vertexTo): vertexTo must not be null");

        Vertex<T, S> vertex = vertices.get(vertexFrom);

        if (vertex == null)
            return null;

        return vertex.getEdge(vertexTo);
    }

    /**
     * Aggiunta di un {@code arco} – O(1)
     * @param vertexFrom
     * @param vertexTo
     * @param edgeLabel
     * @throws NullPointerException se {@code vertexFrom} O {@code vertexTo} O
     *                              {@code edgeLabel} sono {@code null}
     * @throws GraphException       se {@code vertexFrom} O {@code vertexTo}
     *                              non sono nel {@code GraphLibrary.Graph}

    public void addEdge(T vertexFrom, T vertexTo, S edgeLabel) throws NullPointerException, GraphException {
        if (vertexFrom == null)
            throw new NullPointerException("addEdge(vertexFrom, vertexTo, edgeLabel): vertexFrom must not be null");

        if (vertexTo == null)
            throw new NullPointerException("addEdge(vertexFrom, vertexTo, edgeLabel): vertexTo must not be null");

        if (edgeLabel == null)
            throw new NullPointerException("addEdge(vertexFrom, vertexTo, edgeLabel): edgeLabel must not be null");

        if (!vertices.containsKey(vertexFrom))
            throw new GraphException("There is no vertexFrom:" + vertexFrom + " in the GraphLibrary.Graph");

        if (!vertices.containsKey(vertexTo))
            throw new GraphException("There is no vertexTo" + vertexTo + " in the GraphLibrary.Graph");

        Vertex<T, S> firstVertex = vertices.get(vertexFrom);

        firstVertex.addAdjacent(vertexTo, edgeLabel);

        if (!isDirected()) {
            Vertex<T, S> secondVertex = vertices.get(vertexTo);
            secondVertex.addAdjacent(vertexFrom, edgeLabel);
        }
    }

    /**
     * Cancellazione di un {@code arco} – O(1)
     * @param vertexA
     * @param vertexB
     * @return il {@code GraphLibrary.Edge} rimosso
     * @throws NullPointerException se {@code vertexA} O {@code vertexB} sono
     *                              {@code null}
     * @throws GraphException
     *                              <ul>
     *                              <li>se {@code vertexA} o {@code vertexB} non sono {@code GraphLibrary.Graph}</li>
     *                              <li>se non esiste un {@code edge} tra i due nodi</li>
     *                              </ul>

    public Edge<S,T> removeEdge(T vertexA, T vertexB) throws NullPointerException, GraphException {
        if (vertexA == null)
            throw new NullPointerException("removeEdge(vertexA, vertexB): vertexA must not be null");

        if (vertexB == null)
            throw new NullPointerException("removeEdge(vertexA, vertexB): vertexB must not be null");

        if (!vertices.containsKey(vertexA))
            throw new GraphException("There is no vertexA:" + vertexA + " in the GraphLibrary.Graph");

        if (!vertices.containsKey(vertexB))
            throw new GraphException("There is no vertexB:" + vertexB + " in the GraphLibrary.Graph");

        Vertex<T, S> firstVertex = vertices.get(vertexA);

        Edge<S,T> edgeRemoved = firstVertex.removeEdge(vertexB);

        if (edgeRemoved == null)
            throw new GraphException(
                    "There is no edge between vertexA:" + vertexA + " and vertexB:" + vertexB + " in the GraphLibrary.Graph");

        if (!isDirected()) {
            Vertex<T, S> secondVertex = vertices.get(vertexB);

            if (secondVertex.removeEdge(vertexA) == null)
                throw new GraphException(
                        "There is no edge between vertexB:" + vertexB + " and vertexA:" + vertexA
                                + " in the GraphLibrary.Graph");
        }

        return edgeRemoved;
    }

    @Override
    public String toString() {
        String s = "{\n";
        for (Entry<T, Vertex<T, S>> e : vertices.entrySet()) {
            s += "  " + e.getKey() + ": " + e.getValue().adjacentsToString() + "\n";
        }
        s += "}";
        return s;
    }
}



*/



import java.util.*;

public abstract class Graph<T> {
    protected Map<Node<T>, Map<Node<T>, Double>> nodes;
    private int controlNodeSize;
    private int controlEdgeSize;
    private Set<Edge<T>> controlEdgeSet;

    // Empty Graph constructor
    public Graph() {
        this.nodes = new HashMap<>();
        this.controlNodeSize = -1;
        this.controlEdgeSize = -1;
        this.controlEdgeSet = null;
    }

    // Graph with edges constructor
    public Graph(Set<Edge<T>> edgeSet) {
        this();
        if (edgeSet == null)
            return;

        for (Edge<T> e : edgeSet) {
            Node<T> src = e.getSource();
            Node<T> dest = e.getDestination();
            this.addNode(src);
            this.addNode(dest);
            this.addEdge(src, dest, e.getWeight());
        }
    }

    // Checks if this is a directed graph
    public boolean isDirected() {
        return true;
    }

    // Returns a set of nodes
    public Set<Node<T>> getNodes() {
        if (nodes.size() == 0)
            return null;
        return nodes.keySet();
    }

    // Returns Graph edges
    public Set<Edge<T>> getEdges() {
        if (nodes.size() == 0)
            return null;
        if (this.controlEdgeSet != null)
            return this.controlEdgeSet;

        this.controlEdgeSet = new TreeSet<>();
        for (Map.Entry<Node<T>, Map<Node<T>, Double>> node : nodes.entrySet()) {
            for (Map.Entry<Node<T>, Double> edge : node.getValue().entrySet()) {
                this.controlEdgeSet.add(new Edge<>(node.getKey(), edge.getKey(), edge.getValue()));
            }
        }
        return this.controlEdgeSet;
    }

    // Returns amount of nodes
    public int getNodeSize() {
        if (this.controlNodeSize > -1)
            return this.controlNodeSize;
        return this.controlNodeSize = nodes.size();
    }

    // Returns amount of edges
    public int getEdgeSize() {
        if (this.controlEdgeSize > -1)
            return this.controlEdgeSize;

        this.controlEdgeSize = 0;
        for (Map.Entry<Node<T>, Map<Node<T>, Double>> node : nodes.entrySet()) {
            this.controlEdgeSize += node.getValue().size();
        }

        return this.controlEdgeSize;
    }// Return adjent nodes
    public Set<Node<T>> getAdjentNodes(Node<T> value) {
        if (nodes.size() == 0)
            return null;

        Set<Node<T>> adjentNodes = new HashSet<>();
        Map<Node<T>, Double> srcNode = nodes.get(value);
        if (srcNode == null)
            return null;

        for (Map.Entry<Node<T>, Double> edge : srcNode.entrySet())
            adjentNodes.add(edge.getKey());
        return adjentNodes;
    }

    // Get the edge weight of a graph
    public double getEdgeWeight(Node<T> src, Node<T> dest) {
        if (nodes.containsKey(src)) {
            Map<Node<T>, Double> edges = nodes.get(src);
            if (edges.containsKey(dest)) {
                return edges.get(dest);
            }
        }
        return -1.0;
    }

    // addNode overload
    public boolean addNode(T value) {
        return this.addNode(new Node<>(value));
    }

    // Add a node to the graph
    private boolean addNode(Node<T> value) {
        if (value == null || value.getValue() == null)
            return false;
        this.controlNodeSize = -1;
        return nodes.putIfAbsent(value, new HashMap<>()) == null;
    }

    // addEdge overload
    public boolean addEdge(Edge<T> edge) {
        if (edge == null)
            return false;
        return this.addEdge(edge.getSource(), edge.getDestination(), edge.getWeight());
    }

    // addEdge overload
    public boolean addEdge(T src, T dest, int weight) {
        return this.addEdge(new Node<>(src), new Node<>(dest), weight);
    }

    // addEdge overload
    public boolean addEdge(Node<T> src, Node<T> dest, int weight) {
        return this.addEdge(src, dest, weight);
    }

    // addEdge overload
    public boolean addEdge(T src, T dest, double weight) {
        return this.addEdge(new Node<>(src), new Node<>(dest), weight);
    }

    // Adds a node to the graph and returns true if successful
    public boolean addEdge(Node<T> src, Node<T> dest, double weight) {
        if (src == null || src.getValue() == null)
            return false;
        if (dest == null || dest.getValue() == null)
            return false;

        this.controlEdgeSize = -1;
        this.controlEdgeSet = null;

        if (nodes.containsKey(src) && nodes.containsKey(dest)) {
            return nodes.get(src).putIfAbsent(dest, weight) == null;
        }
        return false;
    }

    // containsNode overload
    public boolean containsNode(T value) {
        return nodes.containsKey(new Node<>(value));
    }

    // Checks if a value is in the hash map
    public boolean containsNode(Node<T> value) {
        return nodes.containsKey(value);
    }

    // containsEdge overload
    public boolean containsEdge(T src, T dest) {
        return this.containsEdge(new Node<>(src), new Node<>(dest));
    }

    // Returns true if the edge is in the hash map
    private boolean containsEdge(Node<T> src, Node<T> dest) {
        if (nodes.containsKey(src) && nodes.containsKey(dest)) {
            return nodes.get(src).containsKey(dest);
        }
        return false;
    }

    // removeNode overload
    public boolean removeNode(T value) {
        return this.removeNode(new Node<>(value));
    }

    // Removes a node and returns true if successful
    public boolean removeNode(Node<T> value) {
        if (value == null || value.getValue() == null)
            return false;
        this.controlNodeSize = -1;

        for (Map.Entry<Node<T>, Map<Node<T>, Double>> node : nodes.entrySet()) {
            if (node.getKey().equals(value))
                continue;
            node.getValue().remove(value);
        }
        return nodes.remove(value) != null;
    }

    // removeEdge overload
    public boolean removeEdge(Edge<T> edge) {
        if (edge == null)
            return false;
        return this.removeEdge(edge.getSource(), edge.getDestination());
    }

    // removeEdge overload
    public boolean removeEdge(T src, T dest) {
        return this.removeEdge(new Node<>(src), new Node<>(dest));
    }

    // Remove an edge between two nodes and returns true when successful
    public boolean removeEdge(Node<T> src, Node<T> dest) {
        if (src == null || src.getValue() == null)
            return false;
        if (dest == null || dest.getValue() == null)
            return false;

        this.controlEdgeSize = -1;
        this.controlEdgeSet = null;

        if (nodes.containsKey(src))
            return nodes.get(src).remove(dest) != null;
        return false;
    }

}