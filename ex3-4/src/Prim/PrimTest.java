package Prim;

import java.util.Comparator;
import java.util.Set;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import GraphLibrary.Edge;
import GraphLibrary.Graph;
import GraphLibrary.NotOrientedGraph;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
public class PrimTest {
    private Graph<String> graph;
    private Set<Edge<String>> edges;
    private String start = "a";
    @Before
    public void createGraph(){
        edges = new readCSV("/Users/ilaario/Desktop/Progetti/laboratorio-algoritmi-2022-2023/ex3-4/input/test.csv").getEdges();
        graph = new NotOrientedGraph<>(edges);
    }

    @Test
    public void testPrim(){
        Prim<String> prim = new Prim<>(graph);
        prim.run(this.start);
        assertEquals(37.0, prim.getResultWeight(), 0.0);
    }

    @Test
    public void creationTest(){
        Prim<String> prim = new Prim<>(graph);
        assertEquals(9, prim.getNodesCount());
        assertEquals(14, prim.getEdgesCount());
    }

    @Test
    public void removeTest(){
        graph.removeEdge(new Edge<>("a", "b", 4.0));
        Prim<String> prim = new Prim<>(graph);
        prim.run(start);
        assertEquals(41.0, prim.getResultWeight(), 0.0);
    }
}
