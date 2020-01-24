import java.util.*;

public class PolyMorph {
    int t;

    // if a>b then true
    // else false

    public static Boolean MinFunc(int a, int b) {
        return a > b;
    }

    public static Boolean MinFunc(float a, float b) {
        return a > b;
    }

    public static Boolean MinFunc(double a, double b) {
        System.out.println("A");
        return a > b;
    }

    public static Boolean MinFunc(double a, int b) {
        System.out.println("C");
        return a > b;
    }

    public static Boolean MinFunc(int a, double b) {
        System.out.println("B");
        return a > b;
    }

    public PolyMorph() {
        System.out.println("Default Constructor");
    }

    public static void main(String[] args) {
        // System.out.println(MinFunc(21, 5));
        System.out.println(MinFunc(2.2, 5));
        // System.out.println(MinFunc(2.4f, 5.1f));
        System.out.println(MinFunc(2, 5.2));
        PolyMorph pm = new PolyMorph();
        System.out.println(pm.t);
    }
}