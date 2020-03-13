// Java program to demonstrate working of Map interface 
import java.util.*; 
class HashMapDemo 
{ 
public static void main(String args[]) 
{ 
	Map< String,Integer> hm = 
						new HashMap<>(); 
	hm.put("a", new Integer(100)); 
	hm.put("b", new Integer(200)); 
	hm.put("c", new Integer(300)); 
	hm.put("d", new Integer(400)); 
  	hm.putIfAbsent("e",100);
  	hm.replace("d",2000);
  if(hm.containsKey("d")) {
    System.out.println(hm.get("d"));
  }
  System.out.println(hm.get("ff")); // returns null

	// Returns Set view	 
	Set< Map.Entry< String,Integer> > st = hm.entrySet(); 

	for (Map.Entry< String,Integer> me:st) 
	{ 
		System.out.print(me.getKey()+":"); 
		System.out.println(me.getValue()); 
	} 
  
  	Set<String> keys = hm.keySet();
  	System.out.println(keys);
} 
} 
