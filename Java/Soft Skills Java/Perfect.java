import java.lang.Math;

class Perfect {
    public static void main(String[] args) {
        int n=26;
        int sqrt = (int)Math.sqrt(n);
        if(sqrt * sqrt == n)
            System.out.print("Perfect Number");
    }
}