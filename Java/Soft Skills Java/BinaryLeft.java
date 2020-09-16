/*

1
10
101
1010
10101

*/

public class BinaryLeft {
    public static void main(String[] args) {
        int n = 5;
        for(int i=0; i<n; i++) {
            boolean cat = true;
            for(int j=0; j<=i; j++) {
                System.out.print(cat ? "1" : "0");
                cat = !cat;
            }
            System.out.print("\n");
        }
    }
}