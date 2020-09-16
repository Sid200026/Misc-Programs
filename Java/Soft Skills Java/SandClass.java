/*

* * * * * 
 * * * * 
  * * * 
   * * 
    * 
    * 
   * * 
  * * * 
 * * * * 
* * * * * 

*/

public class SandClass {
    public static void main(String[] args) {
        int n = 5;
        int maxima = n*2 + 1;
        for(int j=n-1; j>=0; j--) {
            int num = 2*j + 1;
            int spaces_required = (maxima - num)/2;
            for(int i=0; i<spaces_required; i++) {
                System.out.print(" ");
            }
            for(int i=0; i<num; i++) {
                System.out.print("*");
            }
            for(int i=0; i<spaces_required; i++) {
                System.out.print(" ");
            }
            System.out.print("\n");
        }
        for(int j=0; j<n; j++) {
            int num = 2*j + 1;
            int spaces_required = (maxima - num)/2;
            for(int i=0; i<spaces_required; i++) {
                System.out.print(" ");
            }
            for(int i=0; i<num; i++) {
                System.out.print("*");
            }
            for(int i=0; i<spaces_required; i++) {
                System.out.print(" ");
            }
            System.out.print("\n");
        }
    }
}