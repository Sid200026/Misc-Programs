public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello World");
        // Here we are directly accessing the method without instantating the objecy
        System.out.println(Check.z);
        System.out.println(Check.info());
        System.out.println(Check.checker());
        System.out.println(Check.DEPARTMENT);
        // Creating an object
        Check ch = new Check();
        // This is an object method
        System.out.println(ch.test());

        // Command line arguments
        for (int i = 0; i < args.length; i++) {
            System.out.println(args[i]);
        }

        // Objects of the class
        Person rosy = new Person();
        rosy.assignName("Rosy");
        Person sid = new Person();
        sid.assignName("Sid");
        System.out.println(Person.isAdult(5));
        System.out.println(Person.info);
        // System.out.println("Hi I\"m Rosy");
    }
}
// Static means you can call it with the classname
// You do not need to create an object
// static defines a method or variable to be class variable or method

class Check {
    // Class variable
    static int z = 7;
    int y = 8;
    public static final String DEPARTMENT = "Development ";

    // class method
    // Accessing object/instance variables or methods inside a static method
    // can only be done by creating an object of that class
    public static String info() {
        Check c = new Check();
        System.out.println(checker());
        System.out.println(c.test());
        System.out.println("Z is " + z);
        return "This is a check class " + c.y;
    }

    public static int checker() {
        return 5;
    }

    // Object method or instance methods
    public int test() {
        return 6 - y;
    }
}

class Person {
    static String info = "This is a person class";
    String name;

    public void assignName(String nm) {
        name = nm;
    }

    public String getName() {
        return name;
    }

    public static Boolean isAdult(int age) {
        return age >= 18;
    }
}