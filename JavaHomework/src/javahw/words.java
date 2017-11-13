package javahw;

import java.io.*;
import java.util.*;

public class words {
	public static void main(String[] args) {
		
		Scanner fileScanner;
		try {
			fileScanner = new Scanner (new File("input.txt"));
			fileScanner.useDelimiter("[^A-Za-z]");
			ArrayList<String> wordsFromFile = new ArrayList<String>();
			
			while (fileScanner.hasNext()) {
				wordsFromFile.add(fileScanner.next().toLowerCase());
			}
			System.out.println("These are the words:");
			System.out.println(wordsFromFile);
			
			System.out.println("These are the frequencies of each word:");
			Set<String> wordFrequency = new HashSet<String>(wordsFromFile);
			for (String key : wordFrequency) {
			    System.out.println(key + ": " + Collections.frequency(wordsFromFile, key));
			}
			
			fileScanner.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.print("File nout found");
		}
	}
}
