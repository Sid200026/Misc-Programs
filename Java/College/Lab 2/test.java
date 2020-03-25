import java.util.*;
class test
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int test = sc.nextInt();
        //int max=0;
        int lmax =0;
        int sum=0;
        int a,b;
        for(int i=1;i<=test;i++)
        {
            a = sc.nextInt();
            b = sc.nextInt();
            int arr[] = new int[a];
            for(int j=0;j<a;j++)
            {
                arr[j]=sc.nextInt();
            }
            Arrays.sort(arr);
            for(int x=0;x<a;x++)
            {
                if((b-arr[x])>=0)
                {
                    b=b-arr[x];
                        lmax++;
                }
            }
            System.out.println("Case #"+i+": "+(lmax));
            sum=0;
            //max=0;
            lmax=0;
        }
    }
}