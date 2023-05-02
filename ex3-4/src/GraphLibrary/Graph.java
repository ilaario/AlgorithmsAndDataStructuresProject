package GraphLibrary;

import java.util.*;

public abstract class Graph<T> {
    protected Map<Node<T>, Map<Node<T>, Double>> nodes;
    private int controlNodeSize;
    private int controlEdgeSize;
    private Set<Edge<T>> controlEdgeSet;
    private double controlWeight;

    // Creazione di un grafo vuoto – O(1)
    public Graph() {
        this.nodes = new HashMap<>();
        this.controlNodeSize = -1;
        this.controlEdgeSize = -1;
        this.controlEdgeSet = null;
    }

    // Creazione di un grafo a partire da un insieme di archi – O(|E|) *opzionale*
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


    // Aggiunta di un nodo – O(1)
    public boolean addNode(Node<T> value) {
        if (value == null || value.getValue() == null)
            return false;
        this.controlNodeSize = -1;
        return nodes.putIfAbsent(value, new HashMap<>()) == null;
    }


    // Aggiunta di un arco – O(1)
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

    // addEdge overload
    public boolean addEdge(Edge<T> edge) {
        if (edge == null)
            return false;
        return this.addEdge(edge.getSource(), edge.getDestination(), edge.getWeight());
    }
    public boolean addEdge(T src, T dest, int weight) {
        return this.addEdge(new Node<>(src), new Node<>(dest), weight);
    }
    public boolean addEdge(Node<T> src, Node<T> dest, int weight) {
        return this.addEdge(src, dest, weight);
    }
    public boolean addEdge(T src, T dest, double weight) {
        return this.addEdge(new Node<>(src), new Node<>(dest), weight);
    }


    // Verifica se il grafo è diretto – O(1)
    public boolean isDirected() {
        return true;
    }
    private boolean containsEdge(Node<T> src, Node<T> dest) {
        if (nodes.containsKey(src) && nodes.containsKey(dest)) {
            return nodes.get(src).containsKey(dest);
        }
        return false;
    } // Returns true if the edge is in the hash map
    public boolean containsNode(T value) {
        return nodes.containsKey(new Node<>(value));
    } // containsNode overload
    public boolean containsNode(Node<T> value) {
        return nodes.containsKey(value);
    } // Checks if a value is in the hash map


    // Verifica se il grafo contiene un dato arco – O(1)
    public boolean containsEdge(T src, T dest) {
        return this.containsEdge(new Node<>(src), new Node<>(dest));
    }


    // Cancellazione di un nodo – O(n)
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
    public boolean removeNode(T value) {
        return this.removeNode(new Node<>(value));
    } // removeNode overload


    // Cancellazione di un arco – O(1)
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
    public boolean removeEdge(Edge<T> edge) {
        if (edge == null)
            return false;
        return this.removeEdge(edge.getSource(), edge.getDestination());
    } // removeEdge overload
    public boolean removeEdge(T src, T dest) {
        return this.removeEdge(new Node<>(src), new Node<>(dest));
    } // removeEdge overload


    // Determinazione del numero di nodi – O(1)
    public int getNodeSize() {
        if (this.controlNodeSize > -1)
            return this.controlNodeSize;
        return this.controlNodeSize = nodes.size();
    }


    // Determinazione del numero di archi – O(n)
    public int getEdgeSize() {
        if (this.controlEdgeSize > -1)
            return this.controlEdgeSize;

        this.controlEdgeSize = 0;
        for (Map.Entry<Node<T>, Map<Node<T>, Double>> node : nodes.entrySet()) {
            this.controlEdgeSize += node.getValue().size();
        }

        return this.controlEdgeSize;
    }


    // Recupero dei nodi del grafo – O(n)
    public Set<Node<T>> getNodes() {
        if (nodes.size() == 0)
            return null;
        return nodes.keySet();
    }


    // Recupero degli archi del grafo – O(n)
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


    // Recupero nodi adiacenti di un dato nodo – O(1)
    public Set<Node<T>> getAdjentNodes(Node<T> value) {
        if (nodes.containsKey(value)) {
            return nodes.get(value).keySet();
        }
        return null;
    }
    public Set<Node<T>> getAdjentNodes(T value) {
        return this.getAdjentNodes(new Node<>(value));
    } // getAdjentNodes overload


    // Recupero etichetta associata a una coppia di nodi – O(1) (*)
    public double getEdgeWeight(Node<T> src, Node<T> dest) {
        if (nodes.containsKey(src) && nodes.get(src).containsKey(dest)) {
            return nodes.get(src).get(dest);
        }
        return -1;
    }


    //Determinazione del peso del grafo (se il grafo non è pesato, il metodo può terminare con un errore)– O(n)
    public double getWeight() {
        if (nodes.size() == 0)
            return -1;
        if (this.controlWeight > -1)
            return this.controlWeight;

        this.controlWeight = 0;
        for (Map.Entry<Node<T>, Map<Node<T>, Double>> node : nodes.entrySet()) {
            for (Map.Entry<Node<T>, Double> edge : node.getValue().entrySet()) {
                this.controlWeight += edge.getValue();
            }
        }
        return this.controlWeight;
    }

    public void setNodeDistance(Node<T> node, double weight) {
        if (nodes.containsKey(node)) {
            nodes.get(node).put(node, weight);
        }
    }

    public double getNodeWeight(Node<T> node) {
        if (nodes.containsKey(node)) {
            return nodes.get(node).get(node);
        }
        return -1;
    }
}