import java.util.*; 
class StringMultiple 
{ 
    public static void main(String ar[]) 
    { 
        Scanner sc=new Scanner(System.in); 
        System.out.println("Enter the number of strings:"); 
        int n=sc.nextInt(); 
        String s; 
        int j; 
        String a[]=new String[10]; 
        int b[]=new int[10]; 
        for(int i=0;i<n;i++) 
        { 
            System.out.println("Enter a string followed by a number:"); 
            s=sc.next(); 
            int l=s.length(); 
            for(j=0;j<s.length();j++) 
            { 
                if(s.charAt(j)>48 && s.charAt(j)<58) 
                { 
                    break; 
                } 
            } 
            a[i]=s.substring(0,(j)); 
            b[i]=Integer.parseInt(s.substring(j,(s.length()))); 
        } 
        for(int i=0;i<n;i++) 
        { 
            System.out.printf("%-10s%03d\n",a[i],b[i]); 
        } 
    } 
} 
