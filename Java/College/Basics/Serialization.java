import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

public class Serialization implements Serializable {
    int a;
    transient int b;
    public Serialization(int a, int b) {
        this.a = a;
        this.b = b;
    }
    public static void main(String[] args) {
        Serialization sr = new Serialization(1, 2);
        try{
            FileOutputStream fo = new FileOutputStream("output.ser");
            ObjectOutputStream oo = new ObjectOutputStream(fo);
            oo.writeObject(sr);
            oo.close();
            fo.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        try{
            FileInputStream fi = new FileInputStream("output.ser");
            ObjectInputStream oi = new ObjectInputStream(fi);
            Serialization s = (Serialization)oi.readObject();
            System.out.println(s.a+" "+s.b);
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}