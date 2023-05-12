package Graph;

import java.util.*;

public class Graph<V, L extends Comparable<L>> implements AbstractGraph<V, L>{
    private final Map<V, Map<V, L>> graph;
    private final boolean isDirected;
    private final boolean isLabelled;

    public Graph(final boolean isDirected, final boolean isLabelled) {
        graph = new HashMap<>();
        this.isDirected = isDirected;
        this.isLabelled = isLabelled;
    }

    @Override
    public boolean isDirected() {
        return isDirected;
    }

    @Override
    public boolean isLabelled() {
        return this.isLabelled;
    };

    @Override
    public boolean addNode(V vertex) {
        if (vertex == null) return false;
        return graph.putIfAbsent(vertex, new HashMap<>()) == null;
    }

    @Override
    public boolean addEdge(V source, V destination, L weight) {
        if (containsEdge(source, destination)) return false;

        this.addNode(source);
        this.addNode(destination);

        graph.get(source).put(destination, weight);

        if (!isDirected) {
            graph.get(destination).put(source, weight);
        }

        return true;
    }

    @Override
    public boolean containsNode(V vertex) {
        if (vertex == null) return false;
        return graph.containsKey(vertex);
    }

    @Override
    public boolean containsEdge(V source, V destination) {
        if (source == null || destination == null || source.equals(destination)) return false;
        return graph.getOrDefault(source, Collections.emptyMap()).containsKey(destination);
    }

    @Override
    public boolean removeNode(V vertex) {
        if (!containsNode(vertex)) return false;

        graph.values().forEach((v) -> v.remove(vertex));
        graph.remove(vertex);

        return true;
    }

    @Override
    public boolean removeEdge(V source, V destination) {
        if (!containsEdge(source, destination)) return false;

        graph.get(source).remove(destination);

        if (!isDirected) {
            graph.get(destination).remove(source);
        }

        return true;
    }

    @Override
    public int numNodes() {
        return graph.size();
    }

    @Override
    public int numEdges() {
        int count = graph.keySet().stream().mapToInt(s -> graph.get(s).size()).sum();

        return isDirected ? count : count / 2;
    }

    @Override
    public AbstractCollection<V> getNodes() {
        return new HashSet<>(graph.keySet());
    }

    @Override
    public AbstractCollection<AbstractEdge<V, L>> getEdges() {
        HashSet<AbstractEdge<V, L>> edges = new HashSet<>();
        graph.forEach((s, d) -> d.forEach((v, w) -> edges.add(new Edge<>(s, v, w))));

        return edges;
    }

    @Override
    public HashSet<V> getNeighbours(V vertex) {
        if (!containsNode(vertex)) return null;
        return new HashSet<>(graph.get(vertex).keySet());
    }

    public L getLabel(V source, V destination) {
        if (!containsEdge(source, destination)) return null;
        return graph.get(source).get(destination);
    }
}
