package Graph;
import GenericPriorityQueue.PriorityQueue;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;

public class GraphJUnitTest {
    private Graph<String, Integer> g;
    private record Node (String start, String end, int priority) implements Comparable<Node> {
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

    @Before
    public void setUp() {
        g = new Graph<String, Integer>(false, true);
        g.addEdge("A", "B", 4);
        g.addEdge("A", "H", 8);
        g.addEdge("B", "C", 8);
        g.addEdge("B", "H", 11);
        g.addEdge("C", "D", 7);
        g.addEdge("C", "F", 4);
        g.addEdge("C", "I", 2);
        g.addEdge("D", "E", 9);
        g.addEdge("D", "F", 14);
        g.addEdge("E", "F", 10);
        g.addEdge("F", "G", 2);
        g.addEdge("G", "H", 1);
        g.addEdge("G", "I", 6);
        g.addEdge("H", "I", 7);
    }

    @Test
    public void testPrim() {
        Graph<String, Integer> mst = new Graph<String, Integer>(false, true);
        PriorityQueue<Node> pq = new PriorityQueue<>();
        g.getNodes().forEach(node -> pq.push(new Node(null, node, Integer.MAX_VALUE)));

        while (!pq.empty()) {
            Node node = pq.top();
            pq.pop();
            if (node.start != null){
                mst.addEdge(node.start, node.end, node.priority);
            } else mst.addNode(node.end);

            if(pq.empty()) break;

            for(String u : g.getNeighbours(node.end)) {
                if(!mst.containsNode(u) &&
                        g.getLabel(node.end, u) < pq.get(new Node(null, u, -1)).priority) {
                    pq.increasePriority(new Node(null, u, -1), new Node(node.end, u, g.getLabel(node.end, u)));
                }
            }
        }
        assertEquals(mst.getNodes().size(), 9);
        assertEquals(mst.getEdges().size() / 2, 8);

        double weight = 0;

        for(AbstractEdge<String, Integer> edge : mst.getEdges()) {
            weight += edge.getLabel();
        }

        assertEquals(37, weight / 2, 0.0001);
    }

    @Test
    public void testAddNode() {
        g.addNode("J");
        assertTrue(g.containsNode("J"));
    }

    @Test
    public void testAddEdge() {
        g.addEdge("A", "J", 1);
        assertTrue(g.containsEdge("A", "J"));
    }

    @Test
    public void testContainsNode() {
        assertTrue(g.containsNode("A"));
    }

    @Test
    public void testContainsEdge() {
        assertTrue(g.containsEdge("A", "B"));
    }

    @Test
    public void testNumNodes() {
        assertEquals(g.numNodes(), 9);
    }

    @Test
    public void testNumEdges() {
        assertEquals(g.numEdges(), 14);
    }

    @Test
    public void testGetNodes() {
        assertEquals(g.getNodes().size(), 9);
    }

    @Test
    public void testGetEdges() {
        assertEquals(g.getEdges().size(), 28);
    }

    @Test
    public void testGetNeighbours() {
        assertEquals(g.getNeighbours("A").size(), 2);
    }

    @Test
    public void testGetLabel() {
        assertEquals((Integer)4, g.getLabel("A", "B"));
    }

    @Test
    public void testRemoveNode() {
        g.removeNode("A");
        assertFalse(g.containsNode("A"));
    }

    @Test
    public void testRemoveEdge() {
        g.removeEdge("A", "B");
        assertFalse(g.containsEdge("A", "B"));
    }


}
