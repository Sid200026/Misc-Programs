// interface Test{
//     void fun();
//     // default int sbd() {
//     //     return 5;
//     // };
// }

// class Lambda {
//     public static void main(String[] args) {
//         Test obj = ()-> System.out.println("Hi");
//         obj.fun();
//     }
// }








// interface Test{
//     int fun();
// }

// class Lambda {
//     public static void main(String[] args) {
//         Test obj = ()->{return 10;};
//         Test obj1 = ()->5+5;
//         System.out.println(obj1.fun());
//     }
// }








// interface Test{
//     int fun(int a);
// }

// class Lambda {
//     public static void main(String[] args) {
//         Test obj = (a)->a+5;
//         System.out.println(obj.fun(11));
//     }
// }








// interface Test{
//     int fun(int a, int b);
// }

// class Lambda {
//     public static void main(String[] args) {
//         Test obj = (a,b)-> {
//             int sum = 0;
//             if(a%2==0) {
//                 sum+=a;
//             } else {
//                 sum+=b;
//             }
//             if(sum%2==0) {
//                 sum = sum*2;
//             }
//             return sum;
//         };
//         System.out.println(obj.fun(11,14));
//     }
// }











// interface Test<T> {
//     T fun(T a, T b);
// }

// class Lambda{
//     public static void main(String[] args) {
//         Test<Integer> obj = (a,b)-> {
//             int sum = 0;
//             if(a%2==0) {
//                 sum+=a;
//             } else {
//                 sum+=b;
//             }
//             if(sum%2==0) {
//                 sum = sum*2;
//             }
//             return sum;
//         };
//         System.out.println(obj.fun(11,14));
//         Test<Float> obj1 = (a,b)-> {
//             float sum = 0;
//             if(a%2==0) {
//                 sum+=a;
//             } else {
//                 sum+=b;
//             }
//             if(sum%2==0) {
//                 sum = sum*2;
//             }
//             return sum;
//         };
//         System.out.println(obj1.fun(11.4f,14.44f));
//     }
// }