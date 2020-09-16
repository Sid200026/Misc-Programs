/*

           * 
         * * 
       * * * 
     * * * * 
   * * * * * 

*/

public class LeftTriangle {
    public static void main(String[] args) {
        int num = 5;
        for(int j=0; j<num; j++) {
            for(int i=num-1; i>j; i--) {
                System.out.print(" ");
            }
            for(int i=0; i<=j; i++)
                System.out.print("*");
            System.out.print("\n");
        }
    }
}