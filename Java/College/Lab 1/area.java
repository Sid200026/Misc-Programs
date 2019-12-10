import java.lang.*; 
import java.util.*; 
public class area 
{ 
    public static void main(String a[]) 
    { 
        Scanner sc=new Scanner(System.in); 
        float area,radius; 
        System.out.print("Enter the Area of circle:"); 
        area=sc.nextFloat(); 
        radius=(float)(Math.sqrt((float)area/Math.PI)); 
        System.out.println("The Diameter of circle is "+2*radius); 
        System.out.println("The Perimeter of circle is "+2*Math.PI*radius); 
    } 
} 