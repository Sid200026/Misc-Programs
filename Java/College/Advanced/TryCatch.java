import java.util.*;
public class TryCatch {
    public static void main(String[] args){
        for(String a:args) {
            System.out.println(a);
        }
        int a = 5;
        try{
            int b = a/0;
        // } catch (Exception e) {
        } catch(ArithmeticException e) {
            e.printStackTrace();
            System.out.println("Error");
        } finally {
            System.out.println("Always executed");
        }
        // int c = 5/0;



        

        int[] arr = {1,3,4,6};
        try{
            int b = arr[3];
            int c1 = arr[b];
            System.out.println("Does not come here");
            int c = b/0;
            throw new IndexOutOfBoundsException("Hi exception");
        } catch (IndexOutOfBoundsException e) {
            int a = 5/0;
            e.printStackTrace();
        } catch (ArithmeticException e) {
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            System.out.println("Done");
        }
    }
}