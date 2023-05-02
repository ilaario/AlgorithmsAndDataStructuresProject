/* package Prim;

import GraphLibrary.*;
import GraphLibrary.GenericPriorityQueue.GenericPriorityQueue;

import java.util.*;

public class Prim<T> {
    private Graph<T> graph;
    private HashMap<Edge<T>, Double> edges;
    private Set<Node<T>> nodes;

    private Set<Edge<T>> mst;
    private HashMap<Node<T>, Node<T>> parent;
    private HashMap<Node<T>, Boolean> visited;
    private HashMap<Node<T>, Double> distance;
    private double result;

    public Prim(Graph<T> graph) {
        this(graph.getNodes(), graph.getEdges());
        this.graph = graph;
    }

    public Prim(Set<Node<T>> nodes, Set<Edge<T>> edges) {
        this.edges = new HashMap<>();
        for (Edge<T> e : edges) {
            this.edges.put(e, e.getWeight());
        }
        this.nodes = nodes;
        this.mst = new HashSet<>();
        this.parent = new HashMap<>();
        this.visited = new HashMap<>();
        this.distance = new HashMap<>();
        for (Node<T> n : nodes) {
            this.distance.put(n, Double.MAX_VALUE);
        }
        this.result = 0;
    }

    public void run(String start) {
        Comparator<Node<T>> comparator = new Comparator<Node<T>>() {
            @Override
            public int compare(Node<T> o1, Node<T> o2) {
                double d1 = o1.getDistance();
                double d2 = o2.getDistance();
                if (Double.compare(d1,d2) > 0) {
                    //System.out.println("o1: " + o1 + " - " + d1 + " > o2: " + o2 + " - " + d2);
                    return 1;
                } else if (Double.compare(d1,d2) < 0) {
                    //System.out.println("o1: " + o1 + " - " + d1 + " < o2: " + o2 + " - " + d2);
                    return -1;
                } else {
                    //System.out.println("o1: " + o1 + " - " + d1 + " = o2: " + o2 + " - " + d2);
                    //return (o1.getValue().toString().compareTo(o2.getValue().toString()));
                    return Long.compare(o1.getId(), o2.getId());
                }
            }
        };
        GenericPriorityQueue<Node<T>> queue = new GenericPriorityQueue<>(comparator);
        for (Node<T> node : nodes) {
            if (node.getValue().toString().equals(start)) {
                node.setDistance(0.0);
                distance.put(node, 0.0);
                parent.put(node, null);
                queue.push(node);
            } else {
                node.setDistance(Double.POSITIVE_INFINITY);
                distance.put(node, Double.POSITIVE_INFINITY);
                parent.put(node, null);
                queue.push(node);
            }

        }

        while (!queue.empty()) {
            Node<T> u = queue.top();
            queue.pop();
            visited.put(u, true);
            for (Node<T> node: graph.getAdjentNodes(u)) {
                if (queue.contains(node)) {
                    if (visited.get(node) == null || !visited.get(node)) {
                        double weight = graph.getEdgeWeight(u, node);
                        if (weight < distance.get(node)) {
                            Node <T> oldNode = node;
                            distance.put(node, weight);
                            parent.put(node, u);
                            queue.update(oldNode, node);
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

    // Returns the weight of the minimum spanning tree
    public double getResultWeight() {
        return this.result;
    }

    // Returns the edges' set of the minimum spanning tree
    public Set<Edge<T>> getMinResultEdges() {
        return this.mst;
    }

    public int getMSTEdgesCount() {
        return this.mst.size();
    }

    // Returns the size of the nodes set
    public int getNodesCount() {
        return this.nodes.size();
    }

    public void printMST() {
        for (Edge<T> edge : mst) {
            System.out.println(edge);
        }
    }

    public int getEdgesCount() {
        return (this.edges.size()/2);
    }
} */

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

    public void run(String start) {
        Comparator<Node<T>> comparator = new Comparator<Node<T>>() {
            @Override
            public int compare(Node<T> o1, Node<T> o2) {
                if (distance.get(o1) > distance.get(o2)) {
                    return 1;
                } else if (distance.get(o1) < distance.get(o2)) {
                    return -1;
                } else {
                    return 0;
                }
            }
        };
        GenericPriorityQueue<Node<T>> queue = new GenericPriorityQueue<>(comparator);
        for (Node<T> node : nodes) {
            if (node.getValue().toString().equals(start)) {
                node.setDistance(0.0);
                distance.put(node, 0.0);
                parent.put(node, null);
                queue.push(node);
            } else {
                node.setDistance(Double.POSITIVE_INFINITY);
                distance.put(node, Double.POSITIVE_INFINITY);
                parent.put(node, null);
                queue.push(node);
            }
        }
;

        while (!queue.empty()) {
            Node<T> u = queue.top();
            queue.pop();
            visited.put(u, true);
            for (Node<T> node: graph.getAdjentNodes(u)) {
                if (queue.contains(node)) {
                    if (visited.get(node) == null || !visited.get(node)) {
                        double weight = graph.getEdgeWeight(u, node);
                        if (weight < distance.get(node)) {
                            Node <T> oldNode = node;
                            distance.put(node, weight);
                            parent.put(node, u);
                            queue.update(oldNode, node);
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

    public int getEdgesCount() {
        return (this.edges.size()/2);
    }

    public void removeEdge(Edge<T> stringEdge) {
        this.edges.remove(stringEdge);
    }
}

