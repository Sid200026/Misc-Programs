import java.util.HashMap;
import java.util.Map;
import java.util.Set;

class Hash {
    public static void main(String[] args) {
        HashMap<String,Integer> map= new HashMap<>();
        map.put("Sid", 19);
        map.put("Rosy", 20);
        map.put("Roy", 18);
        map.put("Test",20);
        System.out.println(map);
        if(map.containsKey("Sid")) {
            System.out.println(map.get("Sid"));
        }
        if(map.containsValue(18)) {
            System.out.println("18 is present");
        }
        System.out.println("Size of map is:- "+ map.size()); 
        map.replace("Rosy", 19);
        System.out.println(map);
        map.putIfAbsent("Sid", 100);
        System.out.println(map);
        System.out.println(map.entrySet()); // Converts map to set
        System.out.println(map.keySet());
        Set< Map.Entry< String,Integer> > st = map.entrySet();    
        for (Map.Entry< String,Integer> me:st) 
        { 
            System.out.print(me.getKey()+":"); 
            System.out.println(me.getValue()); 
        } 
        map.clear();
        System.out.println(map.isEmpty());
    }
}