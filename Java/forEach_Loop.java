import java.util.*;
public class forEach_Loop
{
    public static void main(String args[])
    {
        // If we do not write String as the datatype then objects are created which are stored in the List
        List<String> list = new ArrayList<>();
        list.add("Siddharth");
        list.add("Sajal");
        list.add("Dahlia");
        list.add("Sachit");
        // If stored in form of objects this code will raise an error as we store a object in a string
        for (String name:list)
        {
            System.out.println(name);
        }
    }
}