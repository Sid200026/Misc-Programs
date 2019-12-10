import java.util.*;

class multiples {
    public static void main(String a[]) {
        Scanner sc = new Scanner(System.in);
        int number;
        System.out.print("Enter a number:");
        number = sc.nextInt();
        System.out.println("The first ten multiples of the number " + number + " are:");
        for (int i = 1; i <= 10; i++) {
            System.out.printf("%d*%02d=%d\n", number, i, (number * i));
        }
        sc.close();
    }
}
