import java.io.*;
public class Longest_Shortest {

    public static String getLongest() throws IOException {
        String longest = "";
        FileReader fr = null;
        try{
            fr = new FileReader("siddharth.txt");
        } catch(FileNotFoundException fe) {
            fe.printStackTrace();
            return longest;
        }
        String word = "";
        int ch = fr.read();
        while(ch != -1) {
            if((char)ch == ' ') {
                // When we encounter a space, that makes a word
                if(word.length() > longest.length()) {
                    longest = word;
                }
                word = "";
            } else {
                word += (char)ch;
            }
            ch = fr.read();
        }
        // Checking for the last word
        if(word.length() > longest.length()) {
            longest = word;
        }
        fr.close();
        return longest;
    }

    public static String getShortest(String longest_word) throws IOException {
        String shortest = longest_word;
        FileReader fr = null;
        try{
            fr = new FileReader("siddharth.txt");
        } catch(FileNotFoundException fe) {
            fe.printStackTrace();
            return shortest;
        }
        String word = "";
        int ch = fr.read();
        while(ch != -1) {
            if((char)ch == ' ') {
                // When we encounter a space, that makes a word
                if(word.length() < shortest.length()) {
                    shortest = word;
                }
                word = "";
            } else {
                word += (char)ch;
            }
            ch = fr.read();
        }
        // Checking for the last word
        if(word.length() < shortest.length()) {
            shortest = word;
        }
        fr.close();
        return shortest;
    }

    public static void main(String[] args)throws IOException {
        String longest_word = Longest_Shortest.getLongest();
        String smallest_word = Longest_Shortest.getShortest(longest_word);
        System.out.println("Shortest Word : "+smallest_word);
        System.out.println("Longest Word : "+longest_word);
    }
}