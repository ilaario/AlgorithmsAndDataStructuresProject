package Prim;

import GraphLibrary.*;
import Prim.Prim;
import Prim.readCSV;

import java.io.*;
import java.util.*;

public class PrimMain {
    public static void main(String[] args) {
        if (args.length != 3) {
            System.err.println("Invalid parameter. Required .csv filepath as first argument, starting node as second argument and oriented or not as third argument");
            System.exit(1);
        }

        Set<Edge<String>> edges = new readCSV(args[0]).getEdges();
        if (edges == null) {
            System.err.println("Empty edges. Something went wrong when parsing the csv file");
            System.exit(1);
        }

        if (args[2].equals("oriented")) {
            Graph<String> OrientedGraph = new DirectedGraph<>(edges);
            double totalWeight = 0;
            for (Edge<String> e : edges) {
                totalWeight += e.getWeight();
            }
            System.out.println("Data Set Contains: " + OrientedGraph.getNodeSize() + " nodes and " + OrientedGraph.getEdgeSize() + " oriented edges " +
                    "(Total weight: " + Math.round(totalWeight) + " km)");

            Prim<String> primAlgOrientedGraph = new Prim<>(OrientedGraph);
            String start = args[1];
            System.out.println("Calculate Prim starting from " + start + "...");
            long nanoTime1 = System.nanoTime();
            primAlgOrientedGraph.run(start);
            long nanoTime2 = System.nanoTime();
            System.out.println("Results for Prim algorithm:");
            System.out.println("Time elapsed: " + (nanoTime2 - nanoTime1) / 1000000 + " ms");
            System.out.println("Number of Nodes are: " + primAlgOrientedGraph.getNodesCount());
            System.out.println("Number of oriented edges are: " + (primAlgOrientedGraph.getEdgesCount() - primAlgOrientedGraph.getNodesCount()));

            System.out.println("Shortest path of the graph: " + (((double)Math.round(primAlgOrientedGraph.getResultWeight())) / 1000) + " km");

        } else if (args[2].equals("notoriented")) {
            Graph<String> NotOrientedGraph = new NotOrientedGraph<>(edges);
            double totalWeight = 0;
            for (Edge<String> e : edges) {
                totalWeight += e.getWeight();
            }
            System.out.println("Data Set Contains: " + NotOrientedGraph.getNodeSize() + " nodes and " + NotOrientedGraph.getEdgeSize() + " not oriented edges " +
                    "(Total weight: " + Math.round(totalWeight) + " km)");

            Prim<String> primAlgNotOrientedGraph = new Prim<>(NotOrientedGraph);
            String start = args[1];
            System.out.println("Calculate Prim starting from " + start + "...");
            long nanoTime1 = System.nanoTime();
            primAlgNotOrientedGraph.run(start);
            long nanoTime2 = System.nanoTime();

            System.out.println("Results for Prim algorithm:");
            System.out.println("Time elapsed: " + (nanoTime2 - nanoTime1) / 1000000 + " ms");
            System.out.println("Number of Nodes are: " + primAlgNotOrientedGraph.getNodesCount());
            System.out.println("Number of Not oriented edges are: " + (primAlgNotOrientedGraph.getMinResultEdges().size()));

            System.out.println("Shortest path of the graph: " + (((double)Math.round(primAlgNotOrientedGraph.getResultWeight())) / 1000) + " km");

        } else {
            System.err.println("Invalid parameter. Required .csv filepath as first argument, starting node as second argument and oriented or not as third argument");
            System.exit(1);
        }






    }
}



