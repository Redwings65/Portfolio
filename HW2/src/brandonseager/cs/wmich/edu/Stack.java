package brandonseager.cs.wmich.edu;

import java.util.NoSuchElementException;

public class Stack implements IStack {

	private Node top = null;
	/**
	 * The push method pushes something into the top of the stack.
	 */
	public void push(Object item) {
		top = new Node(item, top);
	}
	/**
	 * The pop method is simply to pull whatever element is on top of the stack out.
	 */
	public Object pop() {
		Object item = peekABoo();
		top = top.next;
		return item;
	}
	/**
	 * The peek method is used to view what is on top of the stack.
	 */
	public Object peekABoo() {
		if (top == null) {
			throw new NoSuchElementException();
		}
		return top.data;
	}
	/**
	 * The isEmpty method is used to simply see if the stack is empty or not.
	 */
	public boolean isEmpty() {
		return top == null;
	}
}
