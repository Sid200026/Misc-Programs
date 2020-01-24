public class VariableArguments {

    // Only one variable arguments for a method
    public static int getSum(String name, int index, int age, int... arr) {
        int sum = 0;
        for (int ele : arr) {
            sum += ele;
        }
        return sum;
    }

    public static void main(String args[]) {
        System.out.println(getSum("sid", 1, 2, 3, 4, 5, 5, 6, 7, 75, 3));
    }
}