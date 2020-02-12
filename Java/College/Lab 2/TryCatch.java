import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.ArithmeticException;
import java.lang.NumberFormatException;
public class TryCatch {

    public static void getErr() throws ArrayIndexOutOfBoundsException {
        throw new ArrayIndexOutOfBoundsException();
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter some input");
        String test = br.readLine();
        try {
            int ans = Integer.parseInt(test);
            int res = 50/ans;
        }
        catch(NumberFormatException num) {
            System.out.println("Cannot convert string to number");
        }
        catch(ArithmeticException ar) {
            System.out.println("Cannot divide by 0");
        }
        System.out.println("Success");
        int[] arr = new int[40];
        try {
            int ans = arr[50];
        }
        catch(ArrayIndexOutOfBoundsException ar) {
            System.out.println("Out of bounds");
        }
        System.out.println("Enter some input");
        String check = br.readLine();
        try{
            int ans = Integer.parseInt(check);
            int res = 50/ans;
            res = arr[100];
        }
        catch(Exception e) {
            System.out.println("Error occured");
        }
        System.out.println("Enter some input");
        String mat = br.readLine();
        try{
            int ans = Integer.parseInt(check);
            try{
                int res = 50/ans;
                res = arr[100];
            }
            catch(Exception e) {
                System.out.println("Divide by 0 or out of bounds");
            }
        }
        catch(Exception e) {
            System.out.println("Cannot convert string to integer");
        }
        getErr();
    }
}