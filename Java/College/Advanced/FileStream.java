import java.io.*;
class FileStream {
    // FileReader, FileWriter
    // // FileInputStream, FileOutputStream
    // public static void main(String[] args)throws IOException{
    //    String s1 = "Text1";
    //    String s2 = "Text12";
    //    int num = 5;
    //    String path = "Revision/output.txt";
    //    FileOutputStream fos = null;
    //    FileOutputStream fos1 = null;
    //    try{
    //    fos = new FileOutputStream(path); 
    //    } catch (FileNotFoundException e) {e.printStackTrace();}
    //    File f = new File("output1.txt");
    //    try{
    //    fos1 = new FileOutputStream(f);
    //    } catch(FileNotFoundException e) {e.printStackTrace();}
    //    byte[] o1 = s1.getBytes();
    //    byte[] o2 = s2.getBytes();
    //    byte[] o3 = Integer.toString(num).getBytes();
    //    fos.write(o1);
    //    fos.write("\n".getBytes());
    //    fos.write(o1);
    //    fos.write("\n".getBytes());
    //    fos.write(o3);
    //    fos.close();
    //    fos1.write(o2);
    //    fos1.close();
    // }






    
    // public static void main(String[] args) throws IOException {
    //     FileInputStream fis = null;
    //     FileInputStream fis1 = null;
    //     try{
    //         fis = new FileInputStream("Revision/output.txt");
    //     } catch(FileNotFoundException fe) {fe.printStackTrace();}
    //     try{
    //         File f = new File("output1.txt");
    //         fis1 = new FileInputStream(f);
    //     } catch(FileNotFoundException fe){fe.printStackTrace();}
    //     String op1 = "";
    //     int ch = fis.read();
    //     while(ch!=-1) {
    //         op1 += (char)ch;
    //         ch = fis.read();
    //     }
    //     String op2 = "";
    //     int ch1 = fis1.read();
    //     while(ch1!=-1) {
    //         op2 += (char)ch1;
    //         ch1 = fis1.read();
    //     }
    //     System.out.println(op1);
    //     System.out.println(op2);
    // }







    // public static void main(String[] args) throws IOException {
    //     FileWriter fw = new FileWriter("test.txt");
    //     String s = "Hi\n";
    //     String s1 = "Bye\n";
    //     String s3 = "Checker";
    //     fw.write(s);
    //     fw.write(s1);
    //     fw.write(s3);
    //     fw.close();
    // }








    // public static void main(String[] args) {
    //     File file = new File("test.txt");
    //     File f = new File(".");
    //     File[] farr = f.listFiles();
    //     int[] arr = {1,2,3,4};
    //     for(File fi:farr) {
    //         System.out.println(fi.getName());
    //     }
    //     String fname = file.getName();
    //     String s = fname.substring(fname.lastIndexOf(".")+1);
    //     System.out.println(s);
    //     if(s.compareTo("txt") == 0) {
    //         System.out.println("Text Fileeee!!!!");
    //     }
    //     System.out.println(file.getName());
    //     System.out.println(file.getAbsolutePath());
    //     FileReader fr = null;
    //     try{
    //      fr = new FileReader(file);
    //     } catch(IOException e) {e.printStackTrace();}
    //     String op = "";
    //     try{
    //     int ch = fr.read();
    //     while(ch!=-1) {
    //         op += (char)ch;
    //         ch = fr.read();
    //     }
    //     } catch(Exception e) {e.printStackTrace();}
    //     System.out.println(op);
    // }
}