package brandonseager.cs.wmich.edu;

import java.util.Random;
import java.util.Scanner;
/**
 * Linked Lists and Arrays
 * Program By: Brandon Seager
 */

public class Main {
	
	static LinkedList list = new LinkedList();
	/**
	 * Linked List initialized below the class to use in multiple methods.
	 */
	public static void main(String[] args) {
		/**
		 * Created a Scanner to ask for n value.
		 */
		Scanner kbd = new Scanner(System.in);
		System.out.println("How Many Numbers do you wish to "
				+ "randomly generate? This value will be m...");
		int numbers = kbd.nextInt();
		System.out.println("Please give me the r value for how many runs you wish todo?");
		int r = kbd.nextInt();
		
		for(int y = 0;y < r;y++){
			list = new LinkedList();
			int max = 100;
			int min = 0;
			Main k = new Main();
			int[] array = new int[numbers+1];
		/**
		 * Created for loop to generate random values and store them to a linked list and 
		 * array for later use.
		 */
			for(int i=0;i<numbers;i++){
				Random random = new Random();
				int num = random.nextInt(max - min + 1) + min;
				array[i] = num;
				list = k.addToLinkedList(num);
			}
			list.add(10, list.size()); 
			array[array.length-1] = 10;
		/**
		 * Send the linked list to a separate method for handling.
		 */
			list = k.countAndSortLinkedList(list);
			System.out.println("\n\nThis is my Finished Linked List");
			System.out.println(list.toString());
		/**
		 * Print out the linked list after it is finished.
		 */
		/**
		 * Start handling the array with the random values that were put into it from above.
		 */
			array = k.countAndSortArray(array);
		/**
		 * After the array is sent to a method for handling, bring it back to print it out.
		 */
			System.out.println("\nThis is my Finished Array");
			for(int i = 0;i < array.length;i++){
				System.out.print(array[i]+" ");
			}
		}
	}
	
	public LinkedList countAndSortLinkedList(LinkedList list){
		/**
		 * This method is for counting and sorting, adding the value 10 and deleting the value 
		 * Necessary.
		 */
		int counter = 0;
		for(int i = 0;i < list.size()+1;i++){
			if(list.get(i) >= 50){	
				counter++;
			}
		}
		/**
		 * Counter is created to see how many values are above 50.
		 */
		boolean yup;
		if(counter > 5){
			yup = false;
			for(int k = 0;k < list.size();k++){
				for(int i = 1;i < list.size();i++){
					if(list.get(i) > list.get(i+1)){
						int l = list.get(i+1);
						list.add(l,i);
						list.remove(i+2);
					}
				}
			}
			list.remove(5);
			/**
			 * Sorts the list in the specific order and deletes the 5th value.
			 */
		}
		else{
			for(int k = 0;k < list.size();k++){
				for(int i = 1;i < list.size();i++){
					if(list.get(i) < list.get(i+1)){
						int l = list.get(i+1);
						list.add(l,i);
						list.remove(i+2);
					}
				}
			}
			list.remove(2);
			/**
			 * Sorts the list in the specific order and deletes the 2nd value.
			 * Then at the end of the method it returns the list.
			 */
		}
		return list;
	}
	@SuppressWarnings("null")
	public int[] countAndSortArray(int [] array){
		int counter = 0;
		for(int i = 0;i < array.length;i++){
			if(array[i] >= 50){	
				counter++;
			}
		}
		/**
		 * A counter for the array class that counts how many values are above 50.
		 */
		if(counter > 5){
			boolean swapped = true;
		    int j = 0;
		    int tmp;
		    while (swapped) {
		        swapped = false;
		        j++;
		        for (int i = 0; i < array.length - j; i++) {
		            if (array[i] > array[i + 1]) {
		                tmp = array[i];
		                array[i] = array[i + 1];
		                array[i + 1] = tmp;
		                swapped = true;
		            }
		        }
		    }
		    /**
			 * Sorts the array and deletes the 5th value.
			 */
		    array[4] = 0;
		}
		else{
			boolean swapped = true;
		    int j = 0;
		    int tmp;
		    while (swapped) {
		        swapped = false;
		        j++;
		        for (int i = 0; i < array.length - j; i++) {
		            if (array[i] < array[i + 1]) {
		                tmp = array[i];
		                array[i] = array[i + 1];
		                array[i + 1] = tmp;
		                swapped = true;
		            }
		        }
		    }
		    /**
			 * Sorts the array in the specific order and deletes the 2nd value. Then
			 * returns the array back to main.
			 */
		    array[1] = 0;
		}	
		return array;
	}
	/**
	 * This method simply adds the random value to the linked list.
	 */
	public LinkedList addToLinkedList(int storeNum){
		list.add(storeNum);
		return list;
	}
}
