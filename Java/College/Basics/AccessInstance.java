public class AccessInstance {

    // These are object variables
    int a = 5;
    int b = 6;
    // c is a class variable
    static int c = 7;

    public int setA(int num) {
        a = num;
        return num;
    }

    public static int getRandomNumber() {
        // k is a local variable
        int k;
        k = 9;
        return 5 + k;
    }

    public AccessInstance() {
        System.out.print("Default Constructor");
    }

    public static void main(String[] args) {
        AccessInstance ai = new AccessInstance();
        // Accessing instance/object methods and variables
        System.out.println(ai.a);
        System.out.println(ai.b);
        System.out.println(ai.setA(4));
        // Accessing class methods and variables
        System.out.println(AccessInstance.c);
        System.out.println(AccessInstance.getRandomNumber());
    }
}