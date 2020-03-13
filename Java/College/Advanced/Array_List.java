// import java.util.*;
// class Array_List {
//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         ArrayList<Integer> arr = new ArrayList<>();
//         arr.add(5);
//         arr.add(6);
//         arr.add(11);
//         arr.add(1, 7);
//         System.out.println(arr);
//         ArrayList<Integer> arr1 = new ArrayList<>();
//         for(int i = 0; i<5;i++) {
//             int n = sc.nextInt();
//             arr1.add(n);
//         }
//         System.out.println(arr1);
//         // Iterator iter = arr1.iterator();
//         // while(iter.hasNext()) {
//         //     System.out.println(iter.next());
//         // }
//         // arr.addAll(arr1);
//         // System.out.println(arr);
//         arr.addAll(arr1);
//         System.out.println(arr);
//         Collections.sort(arr1, Collections.reverseOrder());
//         // Collections.reverse(arr);
//         arr.set(0, 10);
//         System.out.println(arr);
//         sc.close();
//     }
// }












import java.util.*;
class Array_List {
    private class Test implements Comparable<Test> {
        int id;
        String name;
        int total_marks;
        public Test(int id, String name, int total_marks) {
            this.id = id;
            this.name = name;
            this.total_marks = total_marks;
        }
        public void print() {
            System.out.println(id+" "+name);
        }
        @Override
        public String toString() { // For printing
            return id+" "+name+" "+total_marks;
        }
        @Override
        public boolean equals(Object o) {
            if(o == null) {
                return false;
            }
            if(this == (Test)o) {
                return true;
            }
            return this.total_marks == ((Test)o).total_marks;
        }
        @Override
        public int hashCode() {
            return id;
        }
        @Override
        public int compareTo(Test b){ // Sorts in ascending
            if(this.total_marks > b.total_marks) {
                return 1;
            } else if(this.total_marks == b.total_marks) {
                return  0;
            } else {
                return -1;
            }
        } 

    }
    public static void main(String[] args) {
        Array_List al = new Array_List();
        Test t1 = al.new Test(18, "Siddharth", 99);
        Test t2 = al.new Test(12, "Rosy", 100);
        Test t3 = al.new Test(13, "Divvyam", 0);
        Test t4 = al.new Test(41, "Jayit", -10);
        ArrayList<Test> arr = new ArrayList<>();
        arr.add(t1);
        arr.add(0,t2);
        arr.add(t3);
        arr.add(t4);
        System.out.println(arr);
        Test t5 = al.new Test(1, "Siddharths", 99);
        System.out.println(arr.indexOf(t5)); // t1.equals(t5)  | t2.equals(t5)
        Collections.sort(arr);
        System.out.println(arr);
        // int a = 5;
        int b = 6;
        Integer a = new Integer(5); // int a = 5;
        System.out.println(a.hashCode());
        Iterator iter = arr.iterator();
        while(iter.hasNext()) {
            System.out.println(iter.next());
        }
        Iterator iter1 = arr.iterator();
        while(iter1.hasNext()) {
            Test t = (Test)iter1.next();
            System.out.println(t.id+ " "+t.name);
        }
        boolean status = arr.contains(t3);
        System.out.println(status);
    }
}
// // t1 , t5
// // if t1.hashcode == t2.hashcode then go for t1.equals(t5)
// // else not equal