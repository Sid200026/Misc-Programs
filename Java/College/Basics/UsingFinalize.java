public class UsingFinalize {
    public UsingFinalize() {
        System.out.println("Constructor Called");
    }

    public void randomFunc() {
        System.out.println("Method Called");
    }

    protected void finalize() {
        System.out.println("Finalize Called");
    }

    public static void main(String args[]) {
        if (1 > 0) {
            UsingFinalize uf = new UsingFinalize();
            uf.randomFunc();
        }
        System.gc(); // Requesting JVM to call garbage collection
        System.out.println("Hi");
    }
}