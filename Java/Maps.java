import java.util.*;
public class Maps
{
    public static void main(String args[])
    {
        Map<String,String> map = new HashMap<>();
        map.put("Name","Siddharth");
        map.put("Age","Nineteen");
        map.put("Title","Welcome to my sextape");
        System.out.println(map.toString());
        System.out.println(map.get("Name"));
        map.remove("Title");
        System.out.println(map.toString());
    }
}