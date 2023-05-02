package Prim;

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
                } else if (Double.compare(d1,d2)  < 0) {
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
        for (Node<T> node : graph.getNodes()) {
            if(node.getValue().equals(start)){
                graph.setNodeDistance(node, 0);
                node.setDistance(0);
                distance.replace(node, 0.0);
                queue.push(node);
            } else {
                graph.setNodeDistance(node, Double.MAX_VALUE);
                node.setDistance(Double.MAX_VALUE);
                distance.replace(node, Double.MAX_VALUE);
                queue.push(node);
            }
            parent.put(node, null);
        }


        int iter = 0;
        while (!queue.empty()) {
            /*/Controlli vari
            GenericPriorityQueue<Node<T>> queue1 = queue.copy();
            System.out.println("//------------- Prority Queue before Prim ---------------//");
            System.out.println("iter: " + iter++ + " - popping node: " + queue.top());
            while (!queue1.empty()) {
                Node<T> node = queue1.top();
                queue1.pop();
                System.out.println("node: " + node + " distance from distance.get(" + distance.get(node) + ") - ("+ node +".getDistance(): " + node.getDistance() + ")");
            }
            System.out.println();

            System.out.println("//---------------- Nodes before Prim ------------------//");
            for (Node<T> node : graph.getNodes()) {
                System.out.println("node: " + node + " distance: " + distance.get(node));
            }
            System.out.println();
            //----------------------------------------------------------------------------------------------------*/
            Node<T> u = queue.top();
            //System.out.println("cheching node u: " + u);
            queue.pop();
            for (Node<T> node: graph.getAdjentNodes(u)) {
                //System.out.println("  looking for node: " + node + " visited: " + visited.get(node));
                if (visited.get(node) == null) {
                    double weight = graph.getEdgeWeight(u, node);
                    //System.out.println("    weight of Edge(" + u + "," + node + "): " + weight + " distance from distance.get(" + distance.get(node) + ") - ("+ node +".getDistance(): " + node.getDistance() + ")");
                    if (Double.compare(weight, graph.getNodeWeight(node)) < 0) {
                        //System.out.println("      se mi chiami e non rispondo, sto switchando\n      switching node " + node + " distance: " + distance.get(node) + " with node distance: " + weight + " in the node distance");
                        distance.replace(node, weight);
                        node.setDistance(weight);
                        graph.setNodeDistance(node, weight);
                        parent.replace(node, u);
                        //System.out.println("      node attuale: " + node + " distance: " + distance.get(node));
                        queue.push(node);
                    }
                }
            }
            visited.put(u, true);
        }
        for (Node<T> node : nodes) {
            if (parent.get(node) != null) {
                //System.out.println("adding edge: " + parent.get(node) + " - " + node + " weight: " + graph.getEdgeWeight(parent.get(node), node));
                mst.add(new Edge<>(parent.get(node), node, graph.getNodeWeight(node)));
                result += distance.get(node);
                //System.out.println("result: " + result);
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
}

