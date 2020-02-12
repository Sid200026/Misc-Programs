import java.util.*;
class Exceptionthrow
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        String regno=new String();
        String number=new String();
        System.out.println("Enter your registration number : ");
        regno=sc.next();
        System.out.println("Enter your mobile number : ");
        number=sc.next();        
        int lenregno=regno.length();
        int lennumber=number.length();
        if(lenregno!=9 || lennumber!=10)
        {
            throw new IllegalArgumentException("Illegal Argument Exception");
        }
        if(!number.matches("\\d{10}"))
        {
            throw new NumberFormatException("Number Format Exception");
        }
        if(!regno.matches("\\w{9}"))
        {
            throw new NoSuchElementException("No Such Element Exception");
        }
    }
}