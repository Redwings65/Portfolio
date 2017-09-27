package brandonseager.cs.wmich.edu;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws IOException {
		System.out.println("Welcome to My Encryption tool Application");
		System.out.println("When you Add a new Student the hashTable will be Recreated");
		optionMenu();
	}
	public static void optionMenu() throws IOException{
		@SuppressWarnings("resource")
		Scanner kbd = new Scanner(System.in);
		int answer = 0;
		String[] store = new String[20];//this is what will change the mod number!!! SUPER IMPORTANT
		do{
			System.out.println("What would you like todo next?\nAdd a student(1), Find a Student(2), Delete a Student(3), "
					+ "Show all information(4), Exit the Application(5) ");
			answer = kbd.nextInt();
			if(answer == 1){
				store = addAStudent(store);
			}
			else if(answer == 2){
				findAStudent();
			}
			else if(answer == 3){
				store = deleteAStudent(store);
			}
			else if(answer == 4){
				showAllInformation();
			}
			else if(answer == 5){
				System.out.println("You have exited the Application");
				System.out.println("Any Names Created on this Run will show up in a Array Below");
				break;
			}
		}while(answer != 5);
		System.out.println("Here is the Students Orginized the the array in its Hash Order");
		System.out.println();
		for(int i = 0;i<store.length;i++){//this is me printing off the array, only went to store.length
			System.out.println(store[i]);
		}
	}
	public static String[] addAStudent(String[] store) throws IOException{
		@SuppressWarnings("resource")
		Scanner take = new Scanner(System.in);
		File outFile = new File ("hashTable.txt");
		FileWriter write = new FileWriter (outFile);
		PrintWriter pWriter = new PrintWriter (write);
		String yes;
		do{
			System.out.println("What name would you like to encrypt?");
			String str = take.nextLine();
			pWriter.print (str+" ");
			int hash = 7;//default hashcode??
			int hashValue = 0;
			for (int i = 0; i < str.length(); i++) {
				hash = hash^str.charAt(i);
				hashValue = +hash;
			}
			System.out.println();
			hashValue = hashValue % store.length;//this is the sum mod the tablesize
			store[hashValue] = str; 
			System.out.println("The Name was Encrypted with the hash value of "+hashValue);
			pWriter.print(hashValue+"\n");
			System.out.println();
			System.out.println("Would you like to add anymore names?");
			yes = take.nextLine();
		}while(yes.equals("yes"));
		System.out.println("Successfully written name and hashcode to the file\n");
		pWriter.close();
		return store;
	}

	public static void findAStudent() throws FileNotFoundException{
		@SuppressWarnings("resource")
		Scanner kbd = new Scanner(System.in);
		System.out.println("How would you like to search? by Hash or by Name?");
		System.out.println("AKA If a first and last name was entered then search by the last name...");
		String here = kbd.nextLine();
		if(here.equals("Hash") || here.equals("hash")){
			System.out.println("What is the HashNumber you are Searching For?");
			String hashSearch = kbd.nextLine();
			@SuppressWarnings("resource")
			Scanner fileScanner = new Scanner(new File("hashTable.txt"));
			while (fileScanner.hasNext()){
				String name = fileScanner.next();
				if(fileScanner.next().equals(hashSearch)){
					System.out.println(hashSearch+" was found with the Name of "+name);
				}
			}
		}
		else if(here.equals("Name") || here.equals("name")){
			@SuppressWarnings("resource")
			Scanner kbd1 = new Scanner(System.in);
			System.out.println("What is the Name you are Searching For?");
			String nameSearch = kbd1.nextLine();
			//File in = new File("hashTable.txt");
			@SuppressWarnings("resource")
			Scanner fileScanner = new Scanner(new File("hashTable.txt"));
			while (fileScanner.hasNext()){
				if(fileScanner.next().equals(nameSearch)){
					System.out.println(nameSearch+" was found with the hash value of "+fileScanner.next());
				}
			}
		}
	}
	public static String[] deleteAStudent(String[] store) throws IOException{
		@SuppressWarnings("resource")
		Scanner kbd = new Scanner(System.in);
		System.out.println("How would you like to Search and Delete? by Hash or by Name?");
		String here = kbd.nextLine();
		if(here.equals("Hash")){
			System.out.println("What is the HashNumber you are Searching For?");
			int hashSearch = kbd.nextInt();
			@SuppressWarnings("resource")
			Scanner fileScanner = new Scanner(new File("hashTable.txt"));
			while (fileScanner.hasNext()){
				String name = fileScanner.next();
				if(fileScanner.next().equals(hashSearch)){
					System.out.println(hashSearch+" was found with the hash value of "+name);
					System.out.println("The Student was deleted");
					store[hashSearch] = "null";
				}
			}
		}
		else if(here.equals("Name")){
			@SuppressWarnings("resource")
			Scanner kbd1 = new Scanner(System.in);
			System.out.println("What is the Name you are Searching For?");
			String nameSearch = kbd1.nextLine();
			@SuppressWarnings("resource")
			Scanner fileScanner = new Scanner(new File("hashTable.txt"));
			while (fileScanner.hasNext()){
				if(fileScanner.next().equals(nameSearch)){
					int alright = Integer.parseInt(fileScanner.next());
					System.out.println(nameSearch+" was found with the hash value of "+alright);
					System.out.println("The Student was deleted");
					store[alright] = "null";
				}
			}
		}
		return store;
	}
	public static void showAllInformation() throws FileNotFoundException{
		File in = new File("hashTable.txt");
		@SuppressWarnings("resource")
		Scanner into = new Scanner(in);
		while(into.hasNextLine()){
			String line = into.nextLine();
			System.out.println(line);
		}
		System.out.println("The HashTable has Successfully been printed");
	}
}
