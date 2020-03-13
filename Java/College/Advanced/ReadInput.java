import java.io.*;
class ReadInput {
    public static void main(String[] args) {
        File file = new File("test.txt");
        FileReader fr = null;
        try{
         fr = new FileReader(file);
        } catch(IOException e) {e.printStackTrace();}
        String op = "";
        try{
        int ch = fr.read();
        while(ch!=-1) {
            op += (char)ch;
            ch = fr.read();
        }
        } catch(Exception e) {e.printStackTrace();}
        String[] arr = op.split("\n");
        int sum = 0;
        for(String ele:arr) {
            sum+=Integer.parseInt(ele);
        }
        System.out.println(sum);
    }
}