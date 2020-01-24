public class InnerClass { // This class is actually called the outer class
    int a = 5;

    // Inner Class improves the security
    // The class InClass cannot be inherited by any other classes

    private class InClass { // This class is called inner class
        InClass() {
            System.out.println("In Class Default Constructor");
        }

        public void info() {
            System.out.println("Hi");
        }

        public int getA() {
            return a;
        }

        public void setA(int num) {
            a = num;
        }
    }

    // If we declared InClass as static then we would not be able to access a from
    // inside the class
    // This is because non-static methods/variables cannot be accessed by the static
    // class

    public static void main(String[] args) {

        // Since we do not have a static class we need to instantiate the object
        InnerClass in = new InnerClass();
        InnerClass.InClass i = in.new InClass();
        i.info();
        i.setA(1);
        System.out.println(i.getA());
    }
}