import java.io.*;

public class FileHandling {
    public static void main(String[] args) throws IOException {
        String a = "Hi this is Java.\n";
        String b = "Name is Siddharth\n";
        String c = "Hii there";
        FileWriter fw = new FileWriter("output.txt");
        fw.write(a);
        fw.write(b);
        for(int i=0;i<c.length();i++) {
            fw.write(c.charAt(i));
        }
        fw.close();
        FileReader fr = null;
        try{
            fr = new FileReader("output.txt");
        } catch(FileNotFoundException fe) {
            fe.printStackTrace();
        }
        int ch = fr.read();
        while(ch != -1) {
            System.out.print((char)ch);
            ch = fr.read();
        }
        fr.close();
    }
}