import ConsoleColors.ConsoleColors;
import GraphLibrary.*;
import Prim.Prim;

import java.io.*;
import java.util.*;

public class PrimMain {

    // Reads all lines from the CSV file and returns a set
    public static Set<Edge<String>> readCSV(String fileName) {
        Set<Edge<String>> retValue = null;

        File f = new File(fileName);
        try (BufferedReader br = new BufferedReader(new FileReader(f))) {
            String line;
            retValue = new HashSet<>();

            while ((line = br.readLine()) != null) {
                String params[] = line.split(",");
                Edge<String> edgeToAdd = new Edge<>(params[0], params[1], Double.parseDouble(params[2]));
                retValue.add(edgeToAdd);
            }
            System.out.println("Read from file " + fileName + " successfully");
        } catch (Exception e) {
            System.err.println(e.toString());
        }

        return retValue;
    }

    public static void main(String[] args) {
        if (args.length != 2) {
            System.err.println("Invalid parameter. Required .csv filepath as first argument and starting node as second argument");
            System.exit(1);
        }

        Set<Edge<String>> edges = readCSV(args[0]);
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

