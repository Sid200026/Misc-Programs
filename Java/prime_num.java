import java.util.*;

public class prime_num
{
    public static void main(String args[])
    {
/*         int prime_nums[] = {2,3,5,7,11,13,17,19,23,29};
        System.out.println(prime_nums[2]);
        System.out.println(prime_nums.length); */
        List<Integer> list = new ArrayList<>();
        list.add(2);
        list.add(3);
        list.add(5);
        list.remove(1);
        System.out.println(list.toString());
    }
}