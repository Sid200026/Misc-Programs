public class MultipleInterface {
    public static void main(String[] args) {
        System.out.println("Hellooo");
        // Also since b will be static variable we can access it via
        // the classname itself
    }
}

interface parentDad {
    void eat();

    void check(int name);

    Boolean isAdult(int age);

    int a = 5;
}

interface parentMom {
    void eat();

    void isHungry();

    // This is not allowed. If both interfaces that are being extended have
    // the same method name and arguments then they cannot have different return
    // types

    // Boolean check(int age);

    void check(int year);

    Boolean isAdult(int year, int date);

    int b = 52;

    int a = 1;
}

interface child extends parentMom, parentDad {
    void temp();
}

abstract class Caller implements child {
    // This class will have the following abstract methods

    // 1. void eat() from parentDad and parentMom
    // 2. void check(int) from parentDad and parentMom
    // 3. Boolean isAdult(int) from parentDad

    // 4.void isHungry() from parentMom
    // 5. Boolean isAdult(int, int) from parentMom

    // Here the static variables are

    // 1. b

    // However variable a is ambiguous and will raise an error since
    // it is in both interface parentMom and parentDad

    // void eat() is not ambiguous since in both interfaces it means the same
    // thing
    // You need to override void eat()
    // Hence the call is not ambiguous

}

// Interfaces can be saved in different files even
// Suppose we have

// sports.java
// public interface sports {
// void playerAge();
// }

// football.java
// public interface football extends sports {
// void footballer();
// }