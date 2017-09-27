package brandonseager.cs.wmich.edu;

import java.util.Comparator;
import java.util.Iterator;
import java.util.Stack;

public class BST <T extends Comparable<T>> implements Iterable<T>
{
	private Node<T> root;
	private Comparator<T> comparator;

	public BST()
	{
		root = null;
		comparator = null;
	}

	public BST(Comparator<T> comp)
	{
		root = null;
		comparator = comp;
	}

	private int compare(T x, T y)
	{
		if(comparator == null) return x.compareTo(y);
		else
			return comparator.compare(x,y);
	}

	public void insert(T data)
	{
		root = insert(root, data);
	}
	private Node<T> insert(Node<T> p, T toInsert)
	{
		if (p == null)
			return new Node<T>(toInsert);

		if (compare(toInsert, p.data) == 0)
			return p;

		if (compare(toInsert, p.data) < 0)
			p.left = insert(p.left, toInsert);
		else
			p.right = insert(p.right, toInsert);

		return p;
	}


	public boolean search(T toSearch)
	{
		return search(root, toSearch);
	}
	private boolean search(Node<T> p, T toSearch)
	{
		if (p == null)
			return false;
		else
			if (compare(toSearch, p.data) == 0)
				return true;
			else
				if (compare(toSearch, p.data) < 0)
					return search(p.left, toSearch);
				else
					return search(p.right, toSearch);
	}

	public void delete(T toDelete)
	{
		root = delete(root, toDelete);
	}
	private Node<T> delete(Node<T> p, T toDelete)
	{
		if (p == null) System.out.println("The item doesnt exist or has been already removed from the tree");
		else
			if (compare(toDelete, p.data) < 0)
				p.left = delete (p.left, toDelete);
			else
				if (compare(toDelete, p.data)  > 0)
					p.right = delete (p.right, toDelete);
				else
				{
					if (p.left == null) return p.right;
					else
						if (p.right == null) return p.left;
						else
						{
							// get data from the rightmost node in the left subtree
							p.data = retrieveData(p.left);
							// delete the rightmost node in the left subtree
							p.left =  delete(p.left, p.data) ;
						}
				}
		return p;
	}
	private T retrieveData(Node<T> p)
	{
		while (p.right != null) p = p.right;

		return p.data;
	}

	public String toString()
	{
		StringBuffer sb = new StringBuffer();
		for(T data : this) sb.append(data.toString());

		return sb.toString();
	}

	public void preOrderTraversal()
	{
		preOrderHelper(root);
	}
	private void preOrderHelper(Node r)
	{
		if (r != null)
		{
			System.out.print(r+" ");
			preOrderHelper(r.left);
			preOrderHelper(r.right);
		}
	}

	public void inOrderTraversal()
	{
		inOrderHelper(root);
	}
	private void inOrderHelper(Node r)
	{
		if (r != null)
		{
			inOrderHelper(r.left);
			System.out.print(r+" ");
			inOrderHelper(r.right);
		}
	}

	public void postOrderTraversal()
	{
		postOrderHelper(root);
	}
	private void postOrderHelper(Node r)
	{
		if (r != null)
		{
			postOrderHelper(r.left);
			System.out.print(r+" ");
			postOrderHelper(r.right);
		}
	}

	public Iterator<T> iterator()
	{
		return new MyIterator();
	}
	private class MyIterator implements Iterator<T>
	{
		Stack<Node<T>> stk = new Stack<Node<T>>();

		public MyIterator()
		{
			if(root != null) stk.push(root);
		}
		public boolean hasNext()
		{
			return !stk.isEmpty();
		}

		public T next()
		{
			Node<T> cur = stk.peek();
			if(cur.left != null)
			{
				stk.push(cur.left);
			}
			else
			{
				Node<T> tmp = stk.pop();
				while( tmp.right == null )
				{
					if(stk.isEmpty()) return cur.data;
					tmp = stk.pop();
				}
				stk.push(tmp.right);
			}

			return cur.data;
		}
	}
}

class MyComp1 implements Comparator<Integer>
{
	public int compare(Integer x, Integer y)
	{
		return y-x;
	}
}
