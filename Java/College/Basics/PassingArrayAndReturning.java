public class PassingArrayAndReturning {

    // public static int[] add1ToArrayElement(int[] arr) {
    // for (int i = 0; i < arr.length; i++) {
    // arr[i]++;
    // }
    // return arr;
    // }

    public static void add1ToArrayElement(int[] sid) {
        for (int i = 0; i < sid.length; i++) {
            sid[i]++;
        }
    }

    public static void main(String[] a) {
        int[] arr = { 1, 2, 3, 4 };
        // int[] ans = PassingArrayAndReturning.add1ToArrayElement(arr);
        // for (int ele : ans) {
        // System.out.println(ele);
        // }

        // Arrays are passed by reference
        // All primitive data types are passed by value
        // All others are passed by reference
        PassingArrayAndReturning.add1ToArrayElement(arr);
        for (int ele : arr) {
            System.out.println(ele);
        }
    }
}