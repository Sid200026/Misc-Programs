public class ForOfLoop {
    public static void main(String args[]) {
        int[] arr = new int[20]; // Array initialisation
        int arr1[] = { 1, 5, 3, 4 };
        arr[0] = 1;
        arr[1] = 2;
        for (int num : arr1) {
            System.out.print(num);
        }
    }
}