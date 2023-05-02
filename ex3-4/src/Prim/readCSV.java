package Prim;

import GraphLibrary.Edge;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.HashSet;
import java.util.Set;

public class readCSV {
    private Set<Edge<String>> edges;
    public readCSV(String arg) {
        edges = readCSV(arg);
    }

    public static Set<Edge<String>> readCSV(String fileName) {
        Set<Edge<String>> retValue = null;

        File f = new File(fileName);
        try (BufferedReader br = new BufferedReader(new FileReader(f))) {
            String line;
            retValue = new HashSet<>();

            while ((line = br.readLine()) != null) {
                String params[] = line.split(",");
                Edge<String> edgeToAdd1 = new Edge<>(params[0], params[1], Double.parseDouble(params[2]));
                //System.out.println("Adding edge: " + edgeToAdd1);
                retValue.add(edgeToAdd1);
            }
            System.out.println("Read from file " + fileName + " successfully");
        } catch (Exception e) {
            System.err.println(e.toString());
        }

        return retValue;
    }

    public Set<Edge<String>> getEdges() {
        return edges;
    }
}
