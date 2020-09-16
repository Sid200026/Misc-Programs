/*

             1
           1   1
         1   2   1
       1   3   3   1
     1   4   6   4   1

*/

public class Pascal {
    public static void main(String[] args) {
        int n = 5;
        for (int i = 0; i < n; i++) {
            int number = 1;
            for(int j=0; j<(n-i)*2; j++)
                System.out.print(" ");
            for (int j = 0; j <= i; j++) {
                System.out.print(number + "   ");
                number = number * (i - j) / (j + 1);
            }
            System.out.println();
        }
    }
}