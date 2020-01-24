public class TwoDArray {
    public static void main(String[] args) {
        // int matrix = new int[4][5];
        int[][] matrix = { { 1, 2, 3 }, { 1, 4, 5, 0, 3 }, { 1, 4, 5, 3 }, { 2, 4, 3, 2 } };
        for (int[] row : matrix) {
            for (int ele : row) {
                System.out.print(ele + " ");
            }
            System.out.println();
        }
        System.out.println(matrix[2][3]);
        for (int ele : matrix[2]) {
            System.out.print(ele + " ");
        }
    }
}