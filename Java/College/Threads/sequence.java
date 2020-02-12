public class sequence extends Thread {

    public static void getEven(int start, int end) {
        if (start % 2 != 0) {
            start++;
        }
        int i = start;
        for (; i <= end; i += 2) {
            System.out.print(i + " ");
        }
    }

    public static void getOdd(int start, int end) {
        if (start % 2 == 0) {
            start++;
        }
        int i = start;
        for (; i <= end; i += 2) {
            System.out.print(i + " ");
        }
    }

    public static void getPrime(int start, int end) {
        if (start % 2 == 0) {
            start++;
        }
        int i = start;
        for (; i <= end; i += 2) {
            int j = 2;
            Boolean flag = Boolean.TRUE;
            for (; j <= Math.floor(Math.sqrt(i)); j++) {
                if (i % j == 0) {
                    flag = Boolean.FALSE;
                    break;
                }
            }
            if (flag) {
                System.out.print(i + " ");
            }
        }
    }

    // choice is 1 : even from 2 to 50
    // choice is 2 : odd from 1 to 49
    // choice is 3 : prime from 2 to 47
    public void run(int choice) {
        if (choice == 1) {
            sequence.getEven(2, 50);
        } else if (choice == 2) {
            sequence.getOdd(1, 49);
        } else if (choice == 3) {
            sequence.getPrime(2, 47);
        }
    }

    public static void main(String[] args) {
        sequence sq1 = new sequence();
        sequence sq2 = new sequence();
        sequence sq3 = new sequence();
        sq1.run(1);
        System.out.println();
        sq2.run(2);
        System.out.println();
        sq3.run(3);
    }
}