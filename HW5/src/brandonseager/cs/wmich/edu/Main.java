package brandonseager.cs.wmich.edu;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws FileNotFoundException {
		readFile();
	}	
	public static void readFile() throws FileNotFoundException{
		BST<String> bst = new BST<String>();
		@SuppressWarnings("resource")
		Scanner fileScanner = new Scanner(new File("hw5cs3310F16data.txt"));
		System.out.println("Here is what is happening to the search tree:");
		while (fileScanner.hasNext()){
			String todo = fileScanner.next();
			System.out.println(todo);
			if(todo.equals("Insert:")){
				String add = fileScanner.nextLine();
				System.out.println("adding"+add);
				String[] parts = add.split(",");
				bst.insert(parts[0]);
			}
			else if(todo.equals("Delete:")){
				String delete = fileScanner.nextLine();
				System.out.println("deleteing"+delete);
				bst.delete(delete);
			}
			else if(todo.equals("Inorder")){
				bst.inOrderTraversal();
				System.out.println();
			}
			else if(todo.equals("Preorder")){
				bst.preOrderTraversal();
				System.out.println();
			}
			else if(todo.equals("Postorder")){
				bst.preOrderTraversal();
				System.out.println();
			}
			else if(todo.equals("Search:")){
				String searchThis = fileScanner.nextLine();
				System.out.println("We are searching for:"+searchThis);
				System.out.println("If found it will be True, otherwise false");
				System.out.println(bst.search(searchThis));
			}	
		}
		System.out.println();
		System.out.println("Here is the Tree so far:");
		System.out.println(bst.toString());
	}
}
