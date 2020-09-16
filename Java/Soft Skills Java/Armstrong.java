/*
In case of an Armstrong number of 3 digits, the sum of cubes of each digit is equal to the 
number itself. For example: 153 = 1*1*1 + 5*5*5 + 3*3*3 // 153 is an Armstrong number.
*/

public class Armstrong {

    public static void main(String[] args) {
        int num = 153;
        int sum = 0;
        int copy = num;
        while(copy != 0) {
            int rem = copy % 10;
            copy = copy/10;
            sum += rem*rem*rem;
        }
        System.out.println(sum == num ? "ArmStrong" : "ArmWeak");
    }
}