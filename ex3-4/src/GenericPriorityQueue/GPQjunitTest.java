package GenericPriorityQueue;

import static org.junit.Assert.*;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import java.util.Comparator;

public class GPQjunitTest {
    private PriorityQueue<Integer> gpq;
    private Integer i1, i2, i3;

    @Before
    public void setUp() {
        gpq = new PriorityQueue<Integer>(Comparator.naturalOrder());
        i1 = 1;
        i2 = 2;
        i3 = 3;
    }

    @Test
    public void testEmpty() {
        assertTrue(gpq.empty());
    }

    @Test
    public void testPush() {
        gpq.push(i1);
        assertFalse(gpq.empty());
    }

    @Test
    public void testTop() {
        gpq.push(i1);
        gpq.push(i2);
        gpq.push(i3);
        assertEquals(i1, gpq.top());
    }

    @Test
    public void testPop() {
        gpq.push(i1);
        gpq.push(i2);
        gpq.push(i3);
        gpq.pop();
        assertEquals(i2, gpq.top());
    }

    @Test
    public void testNaturalOrder() {
        gpq.push(i1);
        gpq.push(i2);
        gpq.push(i3);
        assertEquals(i1, gpq.top());
        gpq.pop();
        assertEquals(i2, gpq.top());
        gpq.pop();
        assertEquals(i3, gpq.top());
    }

    @Test
    public void testReverseOrder() {
        gpq = new PriorityQueue<Integer>(Comparator.reverseOrder());
        gpq.push(i1);
        gpq.push(i2);
        gpq.push(i3);
        assertEquals(i3, gpq.top());
        gpq.pop();
        assertEquals(i2, gpq.top());
        gpq.pop();
        assertEquals(i1, gpq.top());
    }

    @Test
    public void testNaturalOrderString() {
        PriorityQueue<String> gpq = new PriorityQueue<String>(Comparator.naturalOrder());
        gpq.push("a");
        gpq.push("b");
        gpq.push("c");
        assertEquals("a", gpq.top());
        gpq.pop();
        assertEquals("b", gpq.top());
        gpq.pop();
        assertEquals("c", gpq.top());
    }

    @Test
    public void testReverseOrderString() {
        PriorityQueue<String> gpq = new PriorityQueue<String>(Comparator.reverseOrder());
        gpq.push("a");
        gpq.push("b");
        gpq.push("c");
        assertEquals("c", gpq.top());
        gpq.pop();
        assertEquals("b", gpq.top());
        gpq.pop();
        assertEquals("a", gpq.top());
    }

    @Test
    public void testContains() {
        gpq.push(i1);
        gpq.push(i2);
        gpq.push(i3);
        assertTrue(gpq.contains(i1));
        assertTrue(gpq.contains(i2));
        assertTrue(gpq.contains(i3));
    }

    @Test
    public void testIncreasePriority() {
        gpq.push(i1);
        gpq.push(i2);
        gpq.push(i3);
        gpq.increasePriority(i3, i1);
        assertEquals(i1, gpq.top());
        gpq.pop();
        assertEquals(i1, gpq.top());
        gpq.pop();
        assertEquals(i2, gpq.top());
    }

    @Test
    public void testIncreasePriorityString() {
        PriorityQueue<String> gpq = new PriorityQueue<String>(Comparator.naturalOrder());
        gpq.push("a");
        gpq.push("b");
        gpq.push("c");
        gpq.increasePriority("c", "a");
        assertEquals("a", gpq.top());
        gpq.pop();
        assertEquals("a", gpq.top());
        gpq.pop();
        assertEquals("b", gpq.top());
    }
}
