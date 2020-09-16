/*

     A
    B B
   C   C
  D     D
 E       E
F         F
 E       E
  D     D
   C   C
    B B
     A

*/

public class Alphabet {
    public static void main(String[] args) {
        char[] letter = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
            'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
            'W', 'X', 'Y', 'Z' };
        int n = 6;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n-i; j++) {
                System.out.print(" ");
            }
            System.out.print(letter[i]);
            if(i!=0) {
                for(int j=0; j<2*i-1; j++) {
                    System.out.print(" ");
                }
                System.out.print(letter[i]);
            }
            System.out.print("\n");
        }
        for(int i=n-2; i>=0; i--) {
            for(int j=0; j<n-i; j++) {
                System.out.print(" ");
            }
            System.out.print(letter[i]);
            if(i!=0) {
                for(int j=0; j<2*i-1; j++) {
                    System.out.print(" ");
                }
                System.out.print(letter[i]);
            }
            System.out.print("\n");
        }
    }
}