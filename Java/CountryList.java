import java.util.*;
public class CountryList
{
    public static void main(String args[])
    {
        List<String> myList = new ArrayList<>();
        myList.add("India");
        myList.add("USA");
        myList.add("Austria");
        System.out.println(myList.toString());
        myList.remove(0);
        System.out.println(myList.toString());
    }
}