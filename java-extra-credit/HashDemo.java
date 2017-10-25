import java.util.*;


//HERE SET IS AN INTERFACE SO YOU MUST USE THE EXTEND OPERATOR
class HashObject extends HashSet {
	
	// Find the appropriate Base class to override that include the hashCode and equals member functions.
	
	// Construction function
	public HashObject(String input) {
		element = input;
	}
	public String element;
	
	// This clas must override the following member function
	public int hashCode() {
		return element.hashCode();
	
	}	
	
    // Must override the function clear
	
	boolean equals(String inputParam) {
		if (element == inputParam) {
			return true;
		}
		return false;
	}
}

public class HashDemo {
	
	public static void main(String[] args) {
		
		HashSet<HashObject> hashSet = new HashSet<HashObject>();
		
		HashObject hashObject1 = new HashObject("Hello,");
		hashSet.add(hashObject1);
		
		HashObject hashObject2 = new HashObject("World!");
		hashSet.add(hashObject2);
		
		HashObject hashObject3 = new HashObject("Hi!");
		hashSet.add(hashObject3);
		
		
		// Iterate over the hash set
		Iterator<HashObject> iter = hashSet.iterator();
		
		while (iter.hasNext()) {
			
			hashObject1 = iter.next();
			System.out.print(hashObject1.element + " ");
			
		}
	}
}