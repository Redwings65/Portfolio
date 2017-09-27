package brandonseager.cs.wmich.edu;

/**
 * A small stack interface.  You can see the size of the stack and
 * ask whether it is empty, push and pop items, and peek at the front
 * item.
 */
public interface IStack {

    /**
     * Adds the given item to the top of the stack.
     */
    void push(Object item);

    /**
     * Removes the top item from the stack and returns it.
     * @exception java.util.NoSuchElementException if the stack is empty.
     */
    Object pop();
    
    /**
     * Sees what is at the top of the stack.
     */
    Object peekABoo();
    
    /**
     * Returns whether the stack is empty or not.
     */
    boolean isEmpty();
}
