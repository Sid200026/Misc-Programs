/*

     A 
    A B 
   A B C 
  A B C D 
 A B C D E 
A B C D E F
 

*/

public class CharacterTriangular {
    public static void main(String[] args) {
        char[] letter = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
            'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
            'W', 'X', 'Y', 'Z' };
        int n = 6;
        for(int i=0; i<n; i++) {
            for(int j=0; j < n-1-i; j++) {
                System.out.print(" ");
            }
            for(int j=0; j<=i; j++) {
                System.out.print(letter[j] + " ");
            }
            System.out.print("\n");
        }
    }
}