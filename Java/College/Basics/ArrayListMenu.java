import java.io.*;
import java.util.*;

class ArrayListMenu {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> arr = new ArrayList<Integer>(); 
        while(true) {
            System.out.println("1. Insert an element");
            System.out.println("2. Retrieve an element");
            System.out.println("3. Update an element");
            System.out.println("4. Remove an element");
            System.out.println("5. Search an element");
            System.out.println("6. Sort the arraylist");
            System.out.println("7. Exit");
            System.out.println("Enter your choice");
            int command = sc.nextInt();
            switch (command) {
                case 1:
                    System.out.println("Enter the element");
                    int ele = sc.nextInt();
                    arr.add(ele);
                    break;
                case 2:
                    System.out.println("Enter the index");
                    int index = sc.nextInt();
                    try{
                        System.out.println(arr.get(index));
                    } catch (IndexOutOfBoundsException e){
                        e.printStackTrace();
                    }
                    break;
                case 3:
                    System.out.println("Enter the index");
                    index = sc.nextInt();
                    System.out.println("Enter the new value");
                    ele = sc.nextInt();
                    try{
                        arr.set(index, ele);
                        System.out.println(arr);
                    } catch (IndexOutOfBoundsException e) {
                        e.printStackTrace();
                    }
                    break;
                case 4:
                    System.out.println("Enter the index");
                    index = sc.nextInt();
                    try {
                        arr.remove(index);
                    } catch (IndexOutOfBoundsException e) {
                        e.printStackTrace();
                    }
                    break;
                case 5:
                    System.out.println("Enter the value");
                    int value = sc.nextInt();
                    if(arr.contains(value)) {
                        System.out.println("Present");
                    } else {
                        System.out.println("Absent");
                    }
                    break;
                case 6:
                    Collections.sort(arr); 
                    System.out.println(arr);
                    break;
                case 7:
                    System.exit(0);
                default:
                    System.exit(-1);
            }
        }
    }
}