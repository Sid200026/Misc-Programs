import java.lang.*;
import java.io.*;
class Person{
    protected String name;
    protected final int age;
    public Person(String name, int age) {
        System.out.println("Parent Default");
        this.name = name;
        this.age = age;
    }
    public Boolean isAdult() {
        return age>18;
    }

    public void print(int a) {
        System.out.println(a);
    }

    public void print(int a, int b) {
        System.out.println(a);
        System.out.println(b);
    }
}

// This means that every Inheritance is a person
public class Inheritance extends Person{
    int regno;
    // This variable overrides Person's age variable
    int age = 6;
    public Inheritance(String name, int age, int regno) {
        super(name, age);
        System.out.println("Child Default");
        this.regno = regno;
    }

    // This method overrides the parent isAdult
    public Boolean isAdult() {
        // super.isAdult(); // Returns true or false
        System.out.println(super.name);
        return super.age>10;
    }

    public void print(int a, int b, int c) {
        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
    }

    // private void print(int a) { // Cannot override by providing lesser access than parent
    //     System.out.println(a);
    // }

    public static void main(String[] args) {
        Inheritance vit = new Inheritance("Siddharth",19, 15556);
        System.out.println(vit.isAdult());
        System.out.println(vit.name);
        // Cannot access private data
        // vit.age = 20;
        // System.out.println(vit.isAdult());
        vit.print(4);
        final int temp = 4;
        // temp = 5;
        AbsClass abs = new TempClass();
        System.out.println(abs.a);
        abs.fun();
        abs.dispatch();
        abs.fun3();
        ChampClass t = new ChampClass();
        t.fun();
        t.fun1();
        t.fun2();
        System.out.println(Inf.a);
        ChampClass1 a = new Tester();
        a.fun3();
        a.fun();
        a.fun1();
        a.fun2();
    }
}

// Abstract class cannot be instantiated
// It can only be inherited
abstract class AbsClass {
    int a;
    abstract void fun();
    final void dispatch() {
        System.out.println("Dispatch");
    }
    void fun3(){a = 6;}
    // abstract void test();
}

class TempClass extends AbsClass {
    void fun() {
        System.out.println("Overrided fun");
    }
    // Cannot override dispatch since it is final
}

interface Inf {
    void fun(); // All of these are abstracts
    void fun1();
    Boolean fun2();
    int a = 5; // Variables here is final and static. Cannot be overriden.
}

class ChampClass implements Inf {
    public void fun(){System.out.println("fun");}
    public void fun1(){System.out.println("fun1");}
    public Boolean fun2(){System.out.println("fun2");
        return Boolean.TRUE;
    }
}

interface Inf2 extends Inf{
    void fun3();
}

abstract class ChampClass1 implements Inf2 {
    // public void fun(){System.out.println("fun");}
    // public void fun1(){System.out.println("fun1");}
    // abstract void fun();
    // abstract void fun1();
    public final Boolean fun2(){System.out.println("fun2");
        return Boolean.TRUE;
    }
    public void fun3(){System.out.println("fun3");}
}

class Tester extends ChampClass1 {
    public void fun(){System.out.println("fun");}
    public void fun1(){System.out.println("fun1");}
    // Not required but overriding fun3
    public void fun3(){System.out.println("fun3 form Tester");}
}