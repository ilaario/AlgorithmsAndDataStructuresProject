package GraphLibrary.GenericPriorityQueue;

import java.util.ArrayList;
import java.util.Comparator;

public class GenericPriorityQueue<E extends Comparable<E>> implements AbstractQueue<E> {
    final private ArrayList<E> heap;
    private int size;
    final private Comparator<E> comparator;

    public GenericPriorityQueue(Comparator<E> comparator) {
        this.heap = new ArrayList<>(10);
        this.size = 0;
        this.comparator = comparator;
    }

    public boolean empty() {
        return size == 0;
    }

    public boolean push(E e) {
        heap.add(e);
        size++;
        siftUp(size - 1);
        return true;
    }

    public E top() {
        if (empty()) {
            return null;
        }
        return heap.get(0);
    }

    public void pop() {
        if (empty()) {
            return;
        }

        heap.set(0, heap.get(--size));
        heap.remove(size);
        siftDown(0);
    }

    private void siftUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (compare(heap.get(i), heap.get(parent)) < 0) {
                swap(i, parent);
                i = parent;
            } else {
                break;
            }
        }
    }

    private void siftDown(int i) {
        while (i < size) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int max = i;
            if (left < size && compare(heap.get(left), heap.get(max)) < 0) {
                max = left;
            }
            if (right < size && compare(heap.get(right), heap.get(max)) < 0) {
                max = right;
            }
            if (max != i) {
                swap(i, max);
                i = max;
            } else {
                break;
            }
        }
    }

    private int compare(E o1, E o2) {
        return comparator.compare(o1, o2);
    }

    private void swap(int i, int j) {
        E temp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, temp);
    }

    public int size() {
        return size;
    }

    public Object[] toArray() {
        return heap.toArray();
    }

    public GenericPriorityQueue<E> copy() {
        GenericPriorityQueue<E> queue = new GenericPriorityQueue<>(comparator);
        for (int i = 0; i < size; i++) {
            queue.heap.add(heap.get(i));
        }
        queue.size = size;
        return queue;
    }
}

