import java.util.*;

public class prime {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        for (int i = 2; i < a; i++) {
            boolean flag = false;
            int num = i;
            for (int j = 2; j < num / 2; j++) {
                if (num % j == 0) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                System.out.println(i);
            }
        }
        sc.close();
    }
}