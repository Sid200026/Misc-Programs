import java.util.regex.*;

public class Regex {
    public static void main(String[] args) {
        Pattern pattern = Pattern.compile("geeks", Pattern.CASE_INSENSITIVE); 
        String s = "Geeks for geeks";
        Matcher m = pattern.matcher(s);
        if(m.find()) {
            System.out.println(m.start() + " " + m.end());
            System.out.println(m.group());

        }
        Pattern pattern1 = Pattern.compile("ge*s");
        System.out.println(pattern1.matcher(s).find());

        Pattern pattern2 = Pattern.compile("ge*ks$", Pattern.CASE_INSENSITIVE);
        System.out.println(pattern2.matcher(s).find());

        Pattern phone = Pattern.compile("^[1-9][0-9]{9}$");
        System.out.println(phone.matcher("9830919793").find());

        /*

        n+	Matches any string that contains at least one n
        n*	Matches any string that contains zero or more occurrences of n
        n?	Matches any string that contains zero or one occurrences of n
        n{x}	Matches any string that contains a sequence of X n's
        n{x,y}	Matches any string that contains a sequence of X to Y n's
        n{x,}	Matches any string that contains a sequence of at least X n's

        */

        Pattern phone1 = Pattern.compile("^[1-9]\\d{2}-?\\d{3}-?\\d{4}$");
        System.out.println(phone1.matcher("983-091-9793").find());
        System.out.println(phone1.matcher("9830919793").find());
    }
}