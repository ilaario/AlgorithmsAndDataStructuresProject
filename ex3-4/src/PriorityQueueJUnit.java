import java.util.Comparator;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import org.junit.Before;
import org.junit.Test;

public class PriorityQueueJUnit {
    private Integer i1,i2,i3;
    private GenericPriorityQueue<Integer> PriorityQueue;

    @Before
    public void createOrderedArray() throws PriorityQueueException{
        i1 = -12;
        i2 = 0;
        i3 = 4;
        PriorityQueue = new GenericPriorityQueue<Integer>(Comparator.reverseOrder());
    }


    @Test
    public void testIsEmptyZeroEl(){
        assertTrue(PriorityQueue.empty());
    }

    @Test
    public void testIsEmptyOneEl() throws Exception{
        PriorityQueue.push(i1);
        assertFalse(PriorityQueue.empty());
    }


    @Test
    public void testSizeZeroEl() throws Exception{
        assertEquals(0,PriorityQueue.size());
    }

    @Test
    public void testSizeOneEl() throws Exception{
        PriorityQueue.push(i1);
        assertEquals(1,PriorityQueue.size());
    }

    @Test
    public void testSizeTwoEl() throws Exception{
        PriorityQueue.push(i1);
        PriorityQueue.push(i2);
        assertEquals(2,PriorityQueue.size());
    }

    @Test
    //It directly accesses the OrderedArray instance variable orderedArray.array
    public void testAddOneEl() throws Exception{
        PriorityQueue.push(i1);
        assertEquals(i1, PriorityQueue.top());
    }

    @Test
    //It directly accesses the OrderedArray instance variable orderedArray.array
    public void testAddThreeElAddedInOrder() throws Exception{
        Integer[] expectedArray = {i1,i2,i3};
        PriorityQueue.push(i1);
        PriorityQueue.push(i2);
        PriorityQueue.push(i3);
        assertArrayEquals(expectedArray, PriorityQueue.toArray());
    }

    @Test
    //It directly accesses the OrderedArray instance variable orderedArray.array
    public void testAddThreeElTwoEqual() throws Exception{
        Integer[] expectedArray = {i2,i2,i3};
        PriorityQueue.push(i2);
        PriorityQueue.push(i2);
        PriorityQueue.push(i3);
        assertArrayEquals(expectedArray, PriorityQueue.toArray());
    }

    @Test
    //It directly accesses the OrderedArray instance variable orderedArray.array
    public void testAddThreeElAllEqual() throws Exception{
        Integer[] expectedArray = {i2,i2,i2};
        PriorityQueue.push(i2);
        PriorityQueue.push(i2);
        PriorityQueue.push(i2);
        assertArrayEquals(expectedArray, PriorityQueue.toArray());
    }

    @Test
    public void testAddGetOneEl() throws Exception{
        PriorityQueue.push(i1);
        assertEquals(i1,PriorityQueue.top());
    }

    @Test
    public void testAddGetThreeElFirst() throws Exception{
        PriorityQueue.push(i2);
        PriorityQueue.push(i1);
        PriorityQueue.push(i3);
        assertEquals(i1,PriorityQueue.top());
    }

    @Test
    public void testAddGetThreeElSecond() throws Exception{
        PriorityQueue.push(i2);
        PriorityQueue.push(i1);
        PriorityQueue.push(i3);
        PriorityQueue.pop();
        assertEquals(i2,PriorityQueue.top());
    }

    @Test
    public void testAddGetThreeElThird() throws Exception{
        PriorityQueue.push(i2);
        PriorityQueue.push(i1);
        PriorityQueue.push(i3);
        PriorityQueue.pop();
        PriorityQueue.pop();
        assertEquals(i3,PriorityQueue.top());
    }

}
