package brandonseager.cs.wmich.edu;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
	/**
	 * This is my main method that is used as the controller for the entire program.
	 * @param args
	 * @throws FileNotFoundException
	 */
	public static void main(String[] args) throws FileNotFoundException {
		makeAQueueUsingTwoStacks();
		makeAStackUsingTwoQueues();
		minValue();
	}
	/**
	 * The makeAQueueUsingTwoStacks method is used to implement a Queue using two stacks. It calls
	 * Queue and stack many times and prints out what it is doing.
	 * @throws FileNotFoundException
	 */
	public static void makeAQueueUsingTwoStacks() throws FileNotFoundException{
		Stack first = new Stack();
		Stack second = new Stack();
		String[] temp = new String[40];
		int j = 0;
		@SuppressWarnings("resource")
		Scanner fileScanner = new Scanner(new File("TestForStackAndQueue.txt"));
		System.out.println("Here are the Randomly generated numbers as they go in the first stack.");
		while (fileScanner.hasNext()){
			temp[j] = (fileScanner.next());
			System.out.print(temp[j]+" ");
			first.push(temp[j]);
			j++;
		}
		System.out.println("\n");	
		System.out.println("Here is how they come out of the first stack and get put in the second.");
		for(int i=0;i<5;i++){
			Object k = first.pop();
			System.out.print(k+" ");
			second.push(k);
		}
		System.out.println("\n");
		System.out.println("Here is the numbers being popped out of the second stack.");
		for(int i=0;i<5;i++){
			Object pop = second.pop();
			System.out.print(pop+" ");
		}
		System.out.println("\nThis is my Implementation of a Queue using two Stacks.");
	}
	/**
	 * The makeAStackUsingTwoQueues method is used to implement a Stack using
	 * two Queues and calls Queue and Stack classes many times.
	 * @throws FileNotFoundException
	 */
	public static void makeAStackUsingTwoQueues() throws FileNotFoundException{
		Queue first = new Queue();
		Queue second = new Queue();
		String[] temp = new String[40];
		int j = 0;
		System.out.println("\n\nTime to start using some queues to make a stack.\n");
		@SuppressWarnings("resource")
		Scanner fileScanner = new Scanner(new File("TestForStackAndQueue.txt"));
		System.out.println("Here is how the number go in\n");
		while (fileScanner.hasNext()){
			temp[j] = (fileScanner.next());
			System.out.print(temp[j]+" ");
			first.enqueue(temp[j]);
			j++;
		}	
		System.out.println("\n\nHere is how the numbers come out\n");
		Object top;
		for(int i = 0;i < 5;i++){	
			while(first.size() > 1){
				top = first.dequeue();
				second.enqueue(top);
			}
			System.out.print(" "+first.dequeue());
			Queue temp2 = first;
			first = second;
			second = temp2;
		}
		System.out.println("\nAnd this concludes my implementation of a Stack using two Queues\n");
	}
	/**
	 * The minValue method is a method that uses two stacks, one to keep track of the min value,
	 * and the other is used to keep track of the items that are pushed.
	 * @throws FileNotFoundException
	 */
	public static void minValue() throws FileNotFoundException{

		@SuppressWarnings("resource")
		Scanner fileScanner = new Scanner(new File("TestForMinVlue.txt"));
		Stack min = new Stack();
		Stack stack = new Stack();
		System.out.println("Here is how I found the minValue of a stack in O(1) time complexity.");
		int [] temp = new int[50];
		int minv = fileScanner.nextInt(); 
		System.out.print(fileScanner.next()+" ");
		//stack.push(fileScanner.next());
		stack.push(minv);
		min.push(minv);
		int i = 0;
		while (fileScanner.hasNextInt()){
			temp[i] = fileScanner.nextInt();
			stack.push(temp[i]);
			System.out.print(temp[i]+" ");
			if(temp[i] >= minv){
				min.push(minv);
			}
			else{
				minv = temp[i];
				min.push(minv);
			}
			i++;
		}
		System.out.print("\n");
		System.out.print("The minimum of this stack is "+min.peekABoo());
	}
}

