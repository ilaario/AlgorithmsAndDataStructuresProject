package Graph;

import java.util.Objects;

public class Edge<V,L extends Comparable<L>> implements AbstractEdge<V,L>{
    private V start;
    private V end;
    private L label;

    public Edge(V start, V end, L label) {
        this.start = start;
        this.end = end;
        this.label = label;
    }

    public V getStart() {
        return this.start;
    }

    public V getEnd() {
        return this.end;
    }

    public L getLabel() {
        return this.label;
    }

    @Override
    public String toString() {
        return "Edge {start: \"" + start + "\" destination: \"" + end + "\" weight: \"" + label + "\"}";
    }

    public int compareTo(Edge<V, L> o) {
        return label.compareTo(o.label);
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Edge<?, ?> edge)) return false;
        return start.equals(edge.start) && end.equals(edge.end);
    }

    public int hashCode() {
        return Objects.hash(start, end);
    }
}
