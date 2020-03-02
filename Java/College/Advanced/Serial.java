import java.io.*;

class Test implements Serializable {
    int a;
    static int c;
    transient int d;
    protected Test(int a, int c, int d) {
        this.a = a;
        Test.c = c;
        this.d = d;
    }
    void print(){
        System.out.println(a+" "+c+" "+d);
    }
}

class Serial {
    public static void main(String[] args) throws FileNotFoundException, IOException, ClassNotFoundException {
        Test t = new Test(1,2,3);
        File f = new File("op.ser");
        t.print();
        // FileOutputStream fo = new FileOutputStream("op.ser");
        FileOutputStream fo = new FileOutputStream(f);
        ObjectOutputStream oo = new ObjectOutputStream(fo);
        oo.writeObject(t);
        oo.close();
        fo.close();
        FileInputStream fi = new FileInputStream("op.ser");
        Test.c = 8;
        t.a = 9;
        t.d = 11;
        ObjectInputStream oi = new ObjectInputStream(fi);
        Test t2 = (Test)oi.readObject();
        t2.print();
    }
}