package brandonseager.cs.wmich.edu;
/**
 * Separate Node Class is used to create points that linkedList class uses.
 */
class Node
{
	Node next;
	Object data;

	/**
	 * The Node constructor
	 */
	public Node(Object _data)
	{
		next = null;
		data = _data;
	}
	/**
	 * Returns current Data
	 */
	public Object getData()
	{
		return data;
	}
	/**
	 * Gets the next object
	 */
	public Node getNext()
	{
		return next;
	}
	/**
	 * Sets the next object.
	 */
	public void setNext(Node _next)
	{
		next = _next;
	}
}



