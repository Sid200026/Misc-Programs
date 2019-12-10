import java.util.*; 
public class binarySum{
    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in); 
        String b1,b2,b3; 
        System.out.print("Enter the first binary number:"); 
        b1=sc.next(); 
        System.out.print("Enter the second binary number:"); 
        b2=sc.next(); 
        b3=Integer.toBinaryString((Integer.parseInt(b1,2))+(Integer.parseInt(b2,2))); 
        System.out.println("The sum of two binary numbers is "+b3); 
    }
}