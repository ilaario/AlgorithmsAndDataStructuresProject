import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

public class Prim<L extends Comparable<L>, E extends Comparable<E>> {
    private Graph<L, E> graph;
    private HashMap<E, Double> distance;
    private HashMap<E, E> parent;
    private GenericPriorityQueue<Vertex<L,E>> queue;

    public Prim(Graph<L, E> graph) {
        this.graph = graph;
        distance = new HashMap<>();
        parent = new HashMap<>();
        Comparator<Vertex<L, E>> GenericComparator = new GenericComparator<L, E>();
        queue = new GenericPriorityQueue<>(new GenericComparator<>());
    }

    public Set<Vertex<L, E>> run(int n, L start) throws GraphException {
        Set<Vertex<L, E>> result = new HashSet<>();
        Vertex<L, E> startVertex = graph.getVertex(start);
        if (startVertex == null) {
            throw new GraphException("Vertex not found");
        }
        for (Vertex<L, E> vertex : graph.getVertices()) {
            vertex.setDistance(Double.POSITIVE_INFINITY);
            vertex.setPi(null);
            queue.push(vertex);
        }
        startVertex.setDistance(0);
        queue.push(startVertex);
        while (!queue.empty()) {
            Vertex<L, E> u = queue.top();
            queue.pop();
            result.add(u);
            if (result.size() == n) {
                break;
            }
            for (Edge<E, L> edge : u.getEdges()) {
                Vertex<L, E> v = edge.getDestination();
                if (result.contains(v)) {
                    continue;
                }
                if (edge.getWeight() < v.getDistance()) {
                    v.setDistance(edge.getWeight());
                    v.setPi(u);
                    queue.push(v);
                }
            }
        }
        return result;
    }
}

