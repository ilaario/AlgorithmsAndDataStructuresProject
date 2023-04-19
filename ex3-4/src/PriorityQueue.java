import java.util.Comparator;

public class PriorityQueue<E> implements AbstractQueue<E> {
    private Object[] heap;
    private int size;
    private Comparator<E> comparator;

    public PriorityQueue(Comparator<E> comparator) {
        this.heap = new Object[10];
        this.size = 0;
        this.comparator = comparator;
    }

    public boolean empty() {
        return size == 0;
    }

    public boolean push(E e) {
        if (size == heap.length) {
            grow();
        }
        heap[size] = e;
        size++;
        siftUp(size - 1);
        return true;
    }

    public E top() {
        if (empty()) {
            return null;
        }
        return (E) heap[0];
    }

    public void pop() {
        if (empty()) {
            return;
        }
        size--;
        heap[0] = heap[size];
        heap[size] = null;
        siftDown(0);
    }

    private void grow() {
        Object[] newHeap = new Object[heap.length * 2];
        System.arraycopy(heap, 0, newHeap, 0, heap.length);
        heap = newHeap;
    }

    private void siftUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (compare(heap[i], heap[parent]) > 0) {
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
            if (left < size && compare(heap[left], heap[max]) > 0) {
                max = left;
            }
            if (right < size && compare(heap[right], heap[max]) > 0) {
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

    private int compare(Object o1, Object o2) {
        if (comparator != null) {
            return comparator.compare((E) o1, (E) o2);
        } else {
            return ((Comparable<? super E>) o1).compareTo((E) o2);
        }
    }

    private void swap(int i, int j) {
        Object temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
}
