public class fibonacci{
    public static void main(String args[]){
        int first = 0;
        int second = 1;
        int sum = 0;
        System.out.println(first);
        System.out.println(second);
        for(int i=0; i<=8;i++){
            sum = first + second;
            first = second;
            second = sum;
            System.out.println(sum);
        }
    }
}