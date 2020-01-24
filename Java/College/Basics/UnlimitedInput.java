
// Import is used for importing packages
import java.util.Scanner;
import java.lang.Boolean;

class UnlimitedInput {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[500];
        int counter = 0;
        while (Boolean.TRUE) {
            int a = sc.nextInt();
            arr[counter++] = a;
            /*
             * // This will check if some other input is provided then continuing adding //
             * to arr else break // if (!sc.hasNext()) { // break; // }
             */

            // If input is not integer then break
            if (!sc.hasNextInt()) {
                break;
            }
        }
        System.out.println("Hi");
    }
}