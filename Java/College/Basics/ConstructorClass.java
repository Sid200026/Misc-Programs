public class ConstructorClass {
    public static void main(String args[]) {
        new Check();
        new Check(1);
        new Check(1, 2);
        new Check(1, 2, 3);
    }
}

class Check {
    public Check() {
        System.out.println("Default Constuctor");
    }

    public Check(int a) {
        System.out.println("Param Constuctor with 1 arg");
    }

    public Check(int a, int b) {
        System.out.println("Param Constuctor with 2 arg");
    }

    public Check(int a, int b, int c) {
        System.out.println("Param Constuctor with 2 arg and 1 string");
    }
}