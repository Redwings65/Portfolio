package brandonseager.cs.wmich.edu;

/**
 * A small queue interface.  You can query the size of the queue and
 * ask whether it is empty, add and remove items, and peek at the front
 * item.
 */
public interface IQueue {

    /**
     * Adds the given item to the rear of the queue.
     */
    void enqueue(Object item);

    /**
     * Removes the front item from the queue and returns it.
     * @exception java.util.NoSuchElementException if the queue is empty.
     */
    Object dequeue();

    /**
     * Returns whether the queue is empty or not.
     */
    boolean isEmpty();
    
    /**
     * Returns the size of the Queue.
     */
    int size();
}
