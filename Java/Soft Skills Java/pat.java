import java.util.Scanner;

public class pat {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();
        for(int i=0; i<n;i++) {
            int number = n;
            int count = 0;
            for(int j=0; j<=i; j++) {
                if(i==j) {
                    for(int k=0; k < n-i-1; k++) {
                        System.out.print(number);
                        count++;
                    }
                    break;
                }
                System.out.print(number);
                number--;
            }
            for(int u=0; u<=count; u++) {
                System.out.print(number);
            }
            for(int j=count; j<n-1; j++) {
                number++;
                System.out.print(number);
            }
            System.out.println();
        }

        for(int i=n-1; i>=0;i--) {
            int number = n;
            int count = 0;
            for(int j=0; j<=i; j++) {
                if(i==j) {
                    for(int k=0; k < n-i-1; k++) {
                        System.out.print(number);
                        count++;
                    }
                    break;
                }
                System.out.print(number);
                number--;
            }
            for(int u=0; u<=count; u++) {
                System.out.print(number);
            }
            for(int j=count; j<n-1; j++) {
                number++;
                System.out.print(number);
            }
            System.out.println();
        }
    }
}
