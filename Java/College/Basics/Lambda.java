interface Interface1 { 
    void fun();
}

interface Interface2 { 
    void fun(int a);
}

interface Interface3 { 
    void fun(int a, int b);
}


interface Interface4 { 
    int fun(int a);
}

class Lambda {
    public static void main(String[] args) {
        Interface1 i1 = () -> System.out.println("No params");
        Interface2 i2 = (int a) -> System.out.println(a);
        Interface3 i3 = (int a, int b) -> System.out.println(a+" "+b);
        Interface4 i4 = (int a) -> a+1;
        i1.fun();
        i2.fun(Integer.parseInt(args[0]));
        i3.fun(Integer.parseInt(args[1]), Integer.parseInt(args[2]));
        System.out.println(i4.fun(Integer.parseInt(args[3])));
    }
}