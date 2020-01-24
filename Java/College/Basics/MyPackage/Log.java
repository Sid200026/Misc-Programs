package MyPackage;

public class Log {
    // Using log will require an instance
    public double log(int a) {
        return Math.log(a);
    }

    // Using getInfo can be done via the class name
    public static void getInfo() {
        System.out.println("The log function can be used to get the logarithmic value");
    }
}