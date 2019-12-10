import java.util.*;

public class swap {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = a;
        a = b;
        b = c;
        System.out.println("Swapped Numbers are " + a + " and " + b);
        sc.close();
    }
}