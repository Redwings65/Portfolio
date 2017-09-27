package brandonseager.cs.wmich.edu;

import java.util.NoSuchElementException;

/**
 * An implementation of a queue using singly linked nodes.  The
 * queue itself maintains links to both the head and the tail
 * node, so that both enqueuing and dequeueing are O(1).
 */
public class Queue implements IQueue {

	private Node head = null;
	private Node tail = null;
	/**
	 * The enqueue method simply inserts a element in the rear of the Queue.
	 */
	public void enqueue(Object item) {
		Node newNode = new Node(item, null);
		if (isEmpty()){
			head = newNode;
		} 
		else{
			tail.next = newNode;
		}
		tail = newNode;
	}
	/**
	 * The dequeue method simply dequeues a element in the front of the Queue.
	 */
	public Object dequeue() {
		if (isEmpty()){
			throw new NoSuchElementException();
		}
		Object item = head.data;
		if (tail == head){
			tail = null;
		}
		head = head.next;
		return item;
	}
	/**
	 * The isEmpty method checks to see if the Queue is empty.
	 */
	public boolean isEmpty() {
		return head == null;
	}
	/**
	 * The size method checks and returns the size of the called Queue.
	 */
	public int size() {
		int count = 0;
		for (Node node = head; node != null; node = node.next) {
			count++;
		}
		return count;
	}
}
