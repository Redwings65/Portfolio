package brandonseager.cs.wmich.edu;
/**
 * Linked Lists and Arrays
 * Program By: Brandon Seager
 */
public class LinkedList
{
	/**
	 * This is where I make a node point and initialize listCount.
	 */
	private Node node;
	private int listCount;
	
	/**
	 * Linked List Constructor
	 */
	public LinkedList()
	{
		/**
		 * Current node is set with no data in it. And list count now contains value.
		 */
		node = new Node(null);
		listCount = 0;
	}
	/**
	 * The add method adds the data Object to the current list.
	 */
	public void add(Object data)
	{
		Node temp = new Node(data);
		Node current = node;
		/**
		 * While loop is used to go through the list.
		 */
		while(current.getNext() != null)
		{
			current = current.getNext();
		}
		current.setNext(temp);
		listCount++;
	}
	/**
	 * The next method does the same thing as above except we can now add the value at a given
	 * index.
	 */
	public void add(Object data, int index)
	{
		Node temp = new Node(data);
		Node current = node;
		for(int i = 1; i < index && current.getNext() != null; i++)
		{
			current = current.getNext();
		}
		temp.setNext(current.getNext());
		current.setNext(temp);
		listCount++;
	}
	/**
	 * The get method is used to return the element at the given index.
	 */
	public int get(int index){
		if(index <= 0)
			return 0;
		Node current = node.getNext();
		for(int i = 1; i < index; i++){
			if(current.getNext() == null)
				return 0;
			current = current.getNext();
		}
		return (int) current.getData();
	}
	/**
	 * This method removes the object at the given index.
	 */
	public boolean remove(int index)
	{
		if(index < 1 || index > size())
			return false;
		
		Node current = node;
		for(int i = 1; i < index; i++)
		{
			if(current.getNext() == null)
				return false;	
			current = current.getNext();
		}
		current.setNext(current.getNext().getNext());
		listCount--;
		return true;
	}
	/**
	 * Size method returns the list current size.
	 */
	public int size()
	{
		return listCount;
	}
	/**
	 * The toString() method is used to make a string from the array list.
	 */
	public String toString()
	{
		Node current = node.getNext();
		String output = "";
		while(current != null)
		{
			output += "[" + current.getData().toString() + "]";
			current = current.getNext();
		}
		return output;
	}
}
