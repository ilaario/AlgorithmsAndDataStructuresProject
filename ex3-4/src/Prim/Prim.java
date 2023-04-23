package Prim;

import GraphLibrary.*;
import GraphLibrary.GenericPriorityQueue.GenericPriorityQueue;

import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

public class Prim<T> {
    private Graph<T> graph;
    private Set<Edge<T>> edges;
    private Set<Node<T>> nodes;

    private Set<Edge<T>> mst;
    private HashMap<Node<T>, Node<T>> parent;
    private HashMap<Node<T>, Double> distance;
    private HashMap<Node<T>, Boolean> visited;
    private double result;

    public Prim(Graph<T> graph) {
        this(graph.getNodes(), graph.getEdges());
        this.graph = graph;
    }

    public Prim(Set<Node<T>> nodes, Set<Edge<T>> edges) {
        this.edges = edges;
        this.nodes = nodes;
        this.mst = new HashSet<>();
        this.parent = new HashMap<>();
        this.distance = new HashMap<>();
        this.visited = new HashMap<>();
        this.result = 0;
    }

    public void run() {
        Comparator<Node<T>> comparator = new Comparator<Node<T>>() {
            @Override
            public int compare(Node<T> o1, Node<T> o2) {
                if (distance.get(o1) < distance.get(o2)) {
                    return 1;
                } else if (distance.get(o1) > distance.get(o2)) {
                    return -1;
                } else {
                    return 0;
                }
            }
        };
        GenericPriorityQueue<Node<T>> queue = new GenericPriorityQueue<>(comparator);
        for (Node<T> node : nodes) {
            distance.put(node, Double.POSITIVE_INFINITY);
            parent.put(node, null);
            queue.push(node);
        }
        Node<T> start = nodes.iterator().next();
        distance.put(start, 0.0);
        queue.update(start);

        while (!queue.empty()) {
            Node<T> u = queue.top();
            queue.pop();
            visited.put(u, true);
            for (Node<T> node: graph.getAdjentNodes(u)) {
                if (queue.contains(node)) {
                    if (visited.get(node) == null || !visited.get(node)) {
                        double weight = graph.getEdgeWeight(u, node);
                        if (weight < distance.get(node)) {
                            distance.put(node, weight);
                            parent.put(node, u);
                            queue.update(node);
                        }
                    }
                }
            }
        }
        for (Node<T> node : nodes) {
            if (parent.get(node) != null) {
                mst.add(new Edge<>(parent.get(node), node, graph.getEdgeWeight(parent.get(node), node)));
                result += graph.getEdgeWeight(parent.get(node), node);
            }
        }
    }

    //q: c'è qualche errore in questo algoritmo?
    //a: non è un algoritmo di Prim, ma di Kruskal

    // Returns the weight of the minimum spanning tree
    public double getResultWeight() {
        return this.result;
    }

    // Returns the edges' set of the minimum spanning tree
    public Set<Edge<T>> getMinResultEdges() {
        return this.mst;
    }

    // Returns the size of the nodes set
    public int getNodesCount() {
        return this.nodes.size();
    }

}

