import java.util.*; 
class weird 
{ 
    public static void main(String a[]) 
    { 
        Scanner sc=new Scanner(System.in); 
        System.out.print("Enter an integer value:"); 
        int number; 
        number=sc.nextInt(); 
        if(number%2!=0) 
        { 
            System.out.println("Weird."); 
        } 
        else 
        { 
            if((number>=2 && number<=5) || number>20) 
            { 
                System.out.println("Not Weird."); 
            } 
            else 
            { 
                System.out.println("Weird."); 
            } 
        } 
    } 
} 