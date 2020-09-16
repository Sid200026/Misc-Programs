/*

Strong number is a special number whose sum of factorial of digits is equal to the original number.
For example: 145 is strong number. Since, 1! + 4! + 5! = 145

*/

public class Strong {

    static int factorial(int num) {
        if(num == 0 || num == 1)
            return 1;
        return num * factorial(num-1);
    }

    public static void main(String[] args) {
        int num = 1415;
        int sum = 0;
        int copy = num;
        while(copy != 0) {
            int rem = copy % 10;
            copy = copy/10;
            sum += factorial(rem);
        }
        System.out.println(sum == num ? "Strong" : "Weak");
    }
}