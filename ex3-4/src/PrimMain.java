import ConsoleColors.ConsoleColors;
import GraphLibrary.Graph;
import GraphLibrary.GraphException;
import GraphLibrary.Vertex;
import Prim.Prim;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Set;

public class PrimMain {

    private static final Charset ENCODING = StandardCharsets.UTF_8;

    private static void loadGraph(String filepath, Graph<String, String> graph)
            throws IOException, GraphException {
        System.out.format("\n%sLoading data from file...%s\n", ConsoleColors.YELLOW, ConsoleColors.RESET);

        Path inputFilePath = Paths.get(filepath);

        /* ADD ALL VERTICES */
        try (BufferedReader fileInputReader = Files.newBufferedReader(inputFilePath, ENCODING)) {
            String line = null;
            while ((line = fileInputReader.readLine()) != null) {
                String[] lineElements = line.split(",");

                graph.addVertex(lineElements[0]);
                graph.addVertex(lineElements[1]);
            }
        }

        /* ADD ALL EDGES + WEIGHTS */
        try (BufferedReader fileInputReader = Files.newBufferedReader(inputFilePath,
                ENCODING)) {
            String line = null;
            while ((line = fileInputReader.readLine()) != null) {
                String[] lineElements = line.split(",");

                try {
                    graph.addEdge(lineElements[0], lineElements[1], lineElements[0] + "-" +
                            lineElements[1]);
                    graph.addEdge(lineElements[1], lineElements[0], lineElements[1] + "-" +
                            lineElements[0]);

                    graph.getEdge(lineElements[0],
                            lineElements[1]).setWeight(Double.parseDouble(lineElements[2]));

                    graph.getEdge(lineElements[1],
                            lineElements[0]).setWeight(Double.parseDouble(lineElements[2]));
                } catch (Exception e) {
                    e.printStackTrace(System.err);
                }
            }
        }
        System.out.format("%sData loaded%s\n\n", ConsoleColors.YELLOW, ConsoleColors.RESET);
    }

    public static void main(String[] args) {
        Graph<String, String> graph = new Graph<>();
        try {
            loadGraph(args[0], graph);

            String srcLabel = "torino";
            String dstLabel = "catania";

            long nanoTime1 = System.nanoTime();
            Set<Vertex<String, String>> ris = new Prim<String, String>(graph).run(graph.getNumberVertices(), srcLabel);
            long nanoTime2 = System.nanoTime();

            long runTimeInNanoSeconds = (nanoTime2 - nanoTime1);
            System.out
                    .format("%sTime taken by Prim.Prim:%s %.2f milliseconds%s\n\n", ConsoleColors.CYAN,
                            ConsoleColors.GREEN_BOLD_BRIGHT, (double) (runTimeInNanoSeconds) / 1000000,
                            ConsoleColors.RESET);

            print_info(ris, srcLabel, dstLabel);
        } catch (Exception e) {
            e.printStackTrace(System.err);
        }
    }

    public static void print_info(Set<Vertex<String, String>> ris, String srcLabel, String dstLabel) {
        System.out.format("%sPrinting info...%s \n", ConsoleColors.YELLOW, ConsoleColors.RESET);
        System.out.format("%sNumber of vertices:%s %d%s \n", ConsoleColors.CYAN,
                ConsoleColors.GREEN_BOLD_BRIGHT, ris.size(), ConsoleColors.RESET);
        System.out.format("%sNumber of edges:%s %d%s \n", ConsoleColors.CYAN, ConsoleColors.GREEN_BOLD_BRIGHT,
                ris.size() - 1, ConsoleColors.RESET);
        System.out.format("%sSource:%s %s%s \n", ConsoleColors.CYAN, ConsoleColors.GREEN_BOLD_BRIGHT, srcLabel,
                ConsoleColors.RESET);
        System.out.format("%sDestination:%s %s%s \n", ConsoleColors.CYAN, ConsoleColors.GREEN_BOLD_BRIGHT, dstLabel,
                ConsoleColors.RESET);
        double distance = ris.size();
        System.out.printf("%sTotal distance:%s %.2f Km%s \n", ConsoleColors.CYAN, ConsoleColors.GREEN_BOLD_BRIGHT,
                distance / 1000, ConsoleColors.RESET);
    }
}
