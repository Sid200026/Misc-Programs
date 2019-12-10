import java.util.*;
public class factorial{
        public static void main(String args[]) {
            Scanner sc = new Scanner(System.in);
            int a = sc.nextInt();
            int prod = 1;
            while(a!=1) {
                prod*=a--;
            }
            System.out.println("Factorial is "+prod);
            sc.close();
        }
}