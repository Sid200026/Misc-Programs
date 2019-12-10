import java.util.*; 
class read 
{ 
    public static void main(String a[]) 
    { 
        Scanner sc=new Scanner(System.in); 
        int number; 
        double number1; 
        String s; 
        System.out.print("Enter an integer value:"); 
        number=sc.nextInt(); 
        System.out.print("Enter a double value:"); 
        number1=sc.nextDouble(); 
        sc.nextLine(); 
        System.out.print("Enter a string value:"); 
        s=sc.nextLine(); 
        System.out.println("Print String:"+s+".\nPrint Double:"+number1+".\nPrint Int:"+number); 
    } 
} 
