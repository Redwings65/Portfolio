package brandonseager.cs.wmich.edu;

import java.io.File;
import java.io.FileNotFoundException;
import java.text.Collator;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Scanner;
/**
 * Homework Assignment #4
 * @author brandonseager
 *
 */
public class Main {
	/**
	 * This is my main to control the entire program
	 * @param args
	 * @throws FileNotFoundException
	 */
	public static void main(String[] args) throws FileNotFoundException {
		LinkedList<String>list = new LinkedList<String>();
		@SuppressWarnings("resource")
		Scanner fileScanner = new Scanner(new File("NameList.txt"));
		System.out.println("Here are the Names as they get added to the LinkedList");
		int i = 0;
		while (fileScanner.hasNext()){
			list.add(i, fileScanner.next());
			i++;
		}
		System.out.println("Here is the Linkedlist before being sorted: ");
		System.out.println(list);
		System.out.println("");
		
		list = sortBubble(list);
		System.out.println("Here is the Linkedlist after being sorted using bubble sort: ");
		System.out.println(list);
		System.out.println("");
		LinkedList<String>list1 = new LinkedList<String>();
		@SuppressWarnings("resource")
		Scanner fileScanner1 = new Scanner(new File("NameList.txt"));
		System.out.println("Here are the Names before they get sorted using a LinkedList");
		int i1 = 0;
		while (fileScanner1.hasNext()){
			list1.add(i1, fileScanner1.next());
			i1++;
		}
		System.out.println(list1);
		System.out.println("");
		list1 = sortBubble(list1);
		System.out.println("Here is the Linkedlist after being sorted using incertion sort: ");
		System.out.println(list1);
		
		LinkedList<String>list2 = new LinkedList<String>();
		@SuppressWarnings("resource")
		Scanner fileScanner2 = new Scanner(new File("NameList.txt"));
		System.out.println("Here are the Names before they get sorted using a LinkedList");
		int i2 = 0;
		while (fileScanner2.hasNext()){
			list2.add(i2, fileScanner2.next());
			i2++;
		}
		System.out.println(list2);
		System.out.println("");
		list1 = sortBubble(list2);
		System.out.println("Here is the Linkedlist after being sorted using selection sort: ");
		System.out.println(list2);
		LinkedList<String>list3 = new LinkedList<String>();
		@SuppressWarnings("resource")
		Scanner fileScanner3 = new Scanner(new File("NameList.txt"));
		System.out.println("Here are the Names before they get sorted using a LinkedList");
		int i3 = 0;
		while (fileScanner3.hasNext()){
			list3.add(i3, fileScanner3.next());
			i3++;
		}
		System.out.println("");
		System.out.println(list3);
		System.out.println("");
		list1 = sortBubble(list3);
		System.out.println("Here is the Linkedlist after being sorted using merge sort: ");
		System.out.println(list3);
		System.out.println("");
		System.out.println("Here are the Names as they get added to the Array");
		Scanner input = new Scanner(new File("NameList.txt"));
		String[] arrayList = new String[list.size()];
		int k = 0;
		while (input.hasNext()){
			arrayList[k] = input.nextLine();
			System.out.print(arrayList[k]+" ");
			k++;
		}
		System.out.println("");
		System.out.println("\nHere is the ArrayList after being sorted using bubble sort: ");
		arrayList = sortStringBubble(arrayList);//sorts using bubble sort
		for(int u = 0;u < arrayList.length;u++){
			System.out.print(arrayList[u]+" ");
		}
		System.out.println("");
		System.out.println("\nHere is the ArrayList before being sorted again: ");
		@SuppressWarnings("resource")
		Scanner input2 = new Scanner(new File("NameList.txt"));
		String[] arrayList1 = new String[arrayList.length];
		int k1 = 0;
		while (input2.hasNext()){
			arrayList1[k1] = input2.nextLine();
			System.out.print(arrayList1[k1]+" ");
			k1++;
		}
		System.out.println("");
		System.out.println("\nHere is the ArrayList after being sorted using incertion sort: ");
		arrayList1 = sortIncertionSort(arrayList);//sorts using bubble sort
		for(int p = 0;p < arrayList1.length;p++){
			System.out.print(arrayList1[p]+" ");
		}
		System.out.println("");
		System.out.println("\nHere is the ArrayList before being sorted again: ");
		@SuppressWarnings("resource")
		Scanner input3 = new Scanner(new File("NameList.txt"));
		String[] arrayList2 = new String[arrayList.length];
		int k2 = 0;
		while (input3.hasNext()){
			arrayList2[k2] = input3.nextLine();
			System.out.print(arrayList2[k2]+" ");
			k2++;
		}
		System.out.println("");
		System.out.println("\nHere is the ArrayList after being sorted using selection sort: ");
		arrayList2 = selectionSort(arrayList2);
		for(int p = 0;p < arrayList2.length;p++){
			System.out.print(arrayList2[p]+" ");
		}
		System.out.println("");
		System.out.println("\nHere is the ArrayList before being sorted again: ");
		@SuppressWarnings("resource")
		Scanner input4 = new Scanner(new File("NameList.txt"));
		String[] arrayList3 = new String[arrayList.length];
		int k3 = 0;
		while (input4.hasNext()){
			arrayList3[k3] = input4.nextLine();
			System.out.print(arrayList3[k3]+" ");
			k3++;
		}
		System.out.println("");
		arrayList3 = MergeSort.mergeSort(arrayList3);
		System.out.println("\nHere is the ArrayList after being sorted using merge sort: ");
		for(int p = 0;p < arrayList3.length;p++){
			System.out.print(arrayList3[p]+" ");
		}
		System.out.println("\n");
		System.out.println("\nThis concludes the sorting of all of my Lists");
		input.close();
	}

	public static LinkedList<String> sortBubble(LinkedList<String> sortedList){
		Collections.sort(sortedList);
		return sortedList;
	}
	public static String[] sortStringBubble(String  x[ ]){
		int j;
		boolean flag = true;
		String temp;
		while (flag){
			flag = false;
			for ( j = 0;  j < x.length - 1;  j++ ){
				if ( x [ j ].compareToIgnoreCase( x [ j+1 ] ) > 0 ){
					temp = x [j];
					x [j] = x [j+1];
					x [j+1] = temp;
					flag = true;
				}
			}
		}
		return x;
	}
	public static String[] sortIncertionSort(String [] inputArray){
		String key;
		int i;
		for (int j = 1; j < inputArray.length; j++) {
			key = inputArray[j];
			i = j - 1;
			while (i >= 0) {
				if (key.compareTo(inputArray[i]) > 0) {
					break;
				}
				inputArray[i + 1] = inputArray[i];
				i--;
			}
			inputArray[i + 1] = key;
		}
		return inputArray;
	}
	public static String[] selectionSort(String[] array){
		for (int i = 1; i < array.length; i++) {
			int s = i-1;
			for (int j = i; j < array.length; j++) {
				if (array[j].compareTo(array[s]) < 0) {
					s = j;
				}
			}
			String temp = array[i-1];
			array[i-1] = array[s];
			array[s] = temp;
		}
		return array;
	}
}
