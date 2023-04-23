import ConsoleColors.ConsoleColors;
import GraphLibrary.*;
import Prim.Prim;
import Prim.readCSV;

import java.io.*;
import java.util.*;

public class PrimMain {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.err.println("Invalid parameter. Required .csv filepath as first argument and starting node as second argument");
            System.exit(1);
        }

        Set<Edge<String>> edges = new readCSV(args[0]).getEdges();
        if (edges == null) {
            System.err.println("Empty edges. Something went wrong when parsing the csv file");
            System.exit(1);
        }

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
        primAlgNotOrientedGraph.run();


        System.out.println("Results for Prim algorithm:");

        System.out.println("Number of Nodes are: " + primAlgNotOrientedGraph.getNodesCount());
        System.out.println("Number of Not oriented edges are: " + (primAlgNotOrientedGraph.getMinResultEdges().size()));

        System.out.println("Shortest path of the graph: " + Math.round(primAlgNotOrientedGraph.getResultWeight()) + " km");

    }
}

