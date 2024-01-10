package GenericPriorityQueue;

import java.util.*;

public class PriorityQueue<E extends Comparable<? super E>> implements AbstractQueue<E> {
    private final ArrayList<E> queue;
    private final Map<E, Integer> map;
    private final Comparator<? super E> comparator;

    public PriorityQueue(Comparator<? super E> comparator) {
        queue = new ArrayList<>();
        map = new HashMap<>();
        if (comparator == null) throw new IllegalArgumentException("Comparator cannot be null");
        this.comparator = comparator;
    }

    public PriorityQueue() {
        this(Comparator.naturalOrder());
    }

    public PriorityQueue(Collection<? extends E> collection, Comparator<? super E> comparator) {
        this(comparator);
        if (collection == null) throw new IllegalArgumentException("Collection cannot be null");
        collection.forEach((e) -> {
            if (e == null) throw new NullPointerException("Collection cannot contain null elements");
            this.push(e);
        });
    }

    @SuppressWarnings("unchecked")
    public PriorityQueue(Collection<? extends E> collection) {
        this(collection, collection instanceof SortedSet<?> sortedSet ?
                (Comparator<? super E>) sortedSet.comparator() : Comparator.naturalOrder());
    }

    @Override
    public boolean empty() {
        return queue.isEmpty();
    }

    @Override
    public boolean push(E e) {
        if (e == null || map.containsKey(e)) return false;
        queue.add(e);
        siftUp(queue.size() - 1);
        return true;
    }

    private void swap(int i /* 3 */, int j /* 7 */) {
        E tmp = queue.get(i);
        queue.set(i, queue.get(j));
        queue.set(j, tmp);
        map.replace(queue.get(i), i);
        map.replace(queue.get(j), j);
    }

    @Override
    public E top() {
        return queue.isEmpty() ? null : queue.get(0);
    }

    @Override
    public void pop() {
        if (queue.isEmpty()) return;

        if (queue.size() == 1) {
            map.remove(queue.get(0));
            queue.remove(0);
            return;
        }

        map.remove(queue.get(0));
        map.replace(queue.get(queue.size() - 1), 0);
        queue.set(0, queue.get(queue.size() - 1));
        queue.remove(queue.size() - 1);
        siftDown(0);
    }

    private void siftUp(int index) {
        if (index < 0 || index >= queue.size()) throw new IndexOutOfBoundsException("Index out of bounds");
        if (index == 0) {
            map.put(queue.get(0), 0);
            return;
        }

        int parent = (index - 1) / 2;
        if (comparator.compare(queue.get(parent), queue.get(index)) <= 0) {
            map.put(queue.get(index), index);
            return;
        }

        swap(parent, index);
        siftUp(parent);
    }

    private void siftDown(int index) {
        if (index < 0) throw new IndexOutOfBoundsException("Index cannot be negative");
        if (index >= queue.size() / 2) {
            map.put(queue.get(index), index);
            return;
        }

        int left = index * 2 + 1;
        int right = left + 1;
        int max = index;

        if (left < queue.size() && comparator.compare(queue.get(left), queue.get(max)) < 0) max = left;
        if (right < queue.size() && comparator.compare(queue.get(right), queue.get(max)) < 0) max = right;

        if (max == index) {
            map.put(queue.get(index), index);
            return;
        }

        swap(max, index);
        siftDown(max);
    }

    public E get(E neighbor) {
        if (!map.containsKey(neighbor)) return null;
        return queue.get(map.get(neighbor));
    }

    public boolean contains(E e) {
        return map.containsKey(e);
    }

    public boolean increasePriority(E e, E newKey) {
        if (!map.containsKey(e) || newKey == null || e == null || comparator.compare(newKey, queue.get(map.get(e))) > 0) return false;
        int index = map.remove(e);
        queue.set(index, newKey);
        map.put(newKey, index);
        siftUp(index);
        return true;
    }

    @Override
    public boolean remove(E e) {
        if (!map.containsKey(e)) return false;

        if (queue.size() == 1) {
            map.remove(queue.get(0));
            queue.remove(0);
            return true;
        }

        int index = map.get(e);
        swap(index, queue.size() - 1);
        map.remove(e);
        queue.remove(queue.size() - 1);
        siftDown(index);
        return true;
    }

    @Override
    public String toString() {
        return queue.toString();
    }
}
