package Graph;

import java.util.AbstractCollection;

public interface AbstractGraph<V,L> {
    public boolean isDirected(); // dice se il grafo è diretto o meno -- O(1)
    public boolean isLabelled(); // dice se il grafo è etichettato o meno -- O(1)
    public boolean addNode(V a); // aggiunge un nodo -- O(1)
    public boolean addEdge(V a, V b, L l); // aggiunge un arco dati estremi ed etichetta -- O(1)
    public boolean containsNode(V a); // controlla se un nodo è nel grafo -- O(1)
    public boolean containsEdge(V a, V b); // controlla se un arco è nel grafo -- O(1) (*)
    public boolean removeNode(V a); // rimuove un nodo dal grafo -- O(N)
    public boolean removeEdge(V a, V b); // rimuove un arco dal grafo -- O(1) (*)
    public int numNodes(); // numero di nodi -- O(1)
    public int numEdges(); // numero di archi -- O(N)
    public AbstractCollection<V> getNodes(); // recupero dei nodi del grafo -- O(N)
    public AbstractCollection<AbstractEdge<V,L>> getEdges(); // recupero degli archi del grafo -- O(N)
    public AbstractCollection<V> getNeighbours(V a); // recupero dei nodi adiacenti ad un dato nodo -- O(1) (*)
    public L getLabel(V a, V b); // recupero dell'etichetta di un arco -- O(1) (*)
}
