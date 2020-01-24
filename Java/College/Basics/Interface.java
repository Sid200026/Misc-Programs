public class Interface {
    public static void main(String[] args) {
        OverrideSome cs = new MainClass();
        // The below three lines mean the same

        // SecondaryClass cs = new MainClass();
        // PrimaryClass cs = new MainClass();
        // MainClass cs = new MainClass();

        cs.eat();
        cs.woof(5);
        cs.bark();

        // I cannot use the other classes for calling the above methods
        // Since the other classes are abstract

        // Even this is not allowed
        // parent1Inf = new MainClass();
    }
}

// All methods in an interface are public
// So when we override these we need to write public in the methods
// else we get an error since we are not allowed to reduce the access specifier

// So whenever you implement an interface always have the methods as public.
interface parent1Inf {
    void bark();

    // The parameter name can be changed to any other name we like.
    // However we need to take an int as an argument
    void woof(int age);

    void eat();

    int a = 5;
}

// This class will override some of the interfaces methods
// Since it cannot override all of them, it needs to be declared as abstract
abstract class OverrideSome implements parent1Inf {
    // Here the final keyword is to show this method cannot be overriden
    public final void bark() {
        System.out.println("Bark");
    }
}
// Since OverrideSome class does not override all the classes, we have to
// declare it as abstract

// Since it is abstract we can only inherit it

// Even this class does not override all the abstract methods.
// So we declare it as abstract
abstract class SecondaryClass extends OverrideSome {
    public void eat() {
        System.out.println("Eat");
    }
}
// Again we need to extend the class

// Here all the methods have been overriden.
// Still I can declare it as abstract ( although it is not necessary )
// Since this is abstract it cannot be instantiated. It can only be inherited
abstract class PrimaryClass extends SecondaryClass {
    public void woof(int program) {
        System.out.println("Woof");
    }

    // Although it is not necessary, we can still do it
    public void eat() {
        System.out.println("Eat from PrimaryClass");
    }
}

class MainClass extends PrimaryClass {
    // This class will do nothing
}