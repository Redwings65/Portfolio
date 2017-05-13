 package brandonseager.cs.wmich.edu;

/**
 * Separate Node Class is used to create points that Queue and Stack classes uses.
 */
class Node {
    public Object data;
    public Node next;
    public Node(Object data, Node next) {
        this.data = data;
        this.next = next;
    }
}