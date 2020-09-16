/*

    *
   * *
  *   *
 *     *
*********


*/

public class Triangle {
    public static void main(String[] args) {
        int n = 5;
        int maxima = 2*n - 1;
        for(int i=0; i<n-1; i++) {
            int spaces = (maxima - 2*i - 1)/2;
            for(int j=0; j<spaces; j++) {
                System.out.print(" ");
            }
            if(i==0) {
                System.out.print("* ");
            } else {
                System.out.print("*");
                for(int j=0; j<2*i-1; j++) {
                    System.out.print(" ");
                }
                System.out.print("* ");
            }
            for(int j=0; j<spaces-1; j++) {
                System.out.print(" ");
            }
            System.out.print("\n");
        }
        for(int i=0; i<maxima; i++)
            System.out.print("*");
    }
}