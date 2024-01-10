package Prim;

import GenericPriorityQueue.*;
import Graph.*;

import java.io.*;

public class Prim {

    public static Graph<String, Double> readCSV(String fileName, boolean directed, boolean labelled) {
        Graph<String, Double> graph = new Graph<String, Double>(false, true);

        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] data = line.split(",");
                String start = data[0];
                String end = data[1];
                Double label = Double.parseDouble(data[2]);
                graph.addEdge(start, end, label);
            }
        } catch (FileNotFoundException e) {
            System.out.println("File not found");
        } catch (IOException e) {
            e.printStackTrace();
        }
        return graph;
    }

    public static Graph<String, Double> prim(Graph<String, Double> graph) {
        if (!graph.isLabelled()) throw new RuntimeException("Prim's algorithm can't be applied to unlabelled graphs");
        if (graph.isDirected()) throw new RuntimeException("Prim's algorithm can't be applied to oriented graphs");
        if (graph.numNodes() < 3) return graph;

        record Node (String start, String end, double priority) implements Comparable<Node> {
            @Override
            public int hashCode() {
                return end.hashCode();
            }

            @Override
            public int compareTo(Node o) {
                return Double.compare(priority, o.priority);
            }

            @Override
            public boolean equals(Object o) {
                if (this == o) return true;
                if (!(o instanceof Node node)) return false;
                return end.equals(node.end);
            }
        }

        Graph<String, Double> mst = new Graph<String, Double>(false, true);
        PriorityQueue<Node> pq = new PriorityQueue<>();

        graph.getNodes().forEach(node -> pq.push(new Node(null, node, Double.POSITIVE_INFINITY)));

        while (!pq.empty()) {
            Node node = pq.top();
            pq.pop();
            if (node.start != null){
                mst.addEdge(node.start, node.end, node.priority);
            } else mst.addNode(node.end);

            if(pq.empty()) break;

            for(String u : graph.getNeighbours(node.end)) {
               if(!mst.containsNode(u) &&
                       graph.getLabel(node.end, u) < pq.get(new Node(null, u, -1)).priority) {
                    pq.increasePriority(new Node(null, u, -1), new Node(node.end, u, graph.getLabel(node.end, u)));
               }
            }
        }
        return mst;
    }



    public static void main(String[] args) {
        Graph<String, Double> graph = readCSV(args[0], false, true);
        long start = System.nanoTime();
        Graph<String, Double> mst = prim(graph);
        long end = System.nanoTime();

        double weight = 0;

        for(AbstractEdge<String, Double> edge : mst.getEdges()) {
            weight += edge.getLabel();
        }

        System.out.println("============= Graph Info ===============");

        System.out.println("Original graph nodes:   " + graph.getNodes().size());
        System.out.println("Original graph edges:   " + graph.getEdges().size() / 2);
        System.out.println("\n============ Prim Results ==============");

        System.out.println("Prim's graph nodes:     " + mst.getNodes().size());
        System.out.println("Prim's graph edges:     " + mst.getEdges().size() / 2);
        System.out.printf("Prim's graph weight:    %5.3f\n", (weight / 2 / 1000));
        System.out.println("Prim's graph time:      " + ((end - start) / 1000000) + "ms");

    }
}
