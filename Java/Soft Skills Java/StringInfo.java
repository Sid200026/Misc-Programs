import java.util.StringTokenizer;

class StringInfo {
    public static void main(String[] args) {
        String s = "Sid";
        s = s.concat("dharth");
        System.out.println(s);
        String another = "Siddharth";
        if(s.compareTo(another) == 0)
            System.out.print("Same\n");
        else
            System.out.print("Different\n");
        String s1 = s;
        String s2 = "Siddharth";
        String s3 = new String("Siddharth");
        System.out.println(s1==s2);
        System.out.println(s1==s3);
        System.out.println(s1.compareTo(s2));
        System.out.println(s1.compareTo(s2));
        String s4 = "SiddHARTH";
        System.out.println(s1.equals(s4));
        System.out.println(s1.equalsIgnoreCase(s4));
        String s5 = 50 + 30 + "Sid" + 40 + 40; // 80Sid4040
        System.out.println(s5);
        String sid = "Siddharth Singha Roy";
        String firstname = sid.substring(0,9);
        String middlename = sid.substring(10,16);
        String lastname = sid.substring(17);
        System.out.println(firstname + " " + middlename + " " + lastname);
        System.out.println(firstname.toUpperCase());
        System.out.println(firstname.toLowerCase());
        System.out.println(firstname+lastname);
        System.out.println(String.join(" ",firstname,lastname));
        System.out.println(firstname.startsWith("Si"));
        System.out.println(firstname.endsWith("Si"));
        System.out.println(firstname.contains("id"));
        char[] temp = {'s', 'i', 'd'};
        String yo = new String(temp);
        System.out.println(yo);
        char temp2[] = yo.toCharArray();
        // Replace all s in String sid = "Siddharth Singha Roy";
        System.out.println(sid.replace("S", "s"));
        // Replace first
        System.out.println(sid.replaceFirst("S", "s"));
        // ReplaceAll is slower than replace. Both do the same thing. However replaceAll does a regular expression based
        // comparison.
        /*

        Objects of String are immutable, and objects of StringBuffer and StringBuilder are mutable.
        StringBuffer and StringBuilder are similar, but StringBuilder is faster and preferred over 
        StringBuffer for single threaded program. If thread safety is needed, then StringBuffer is used.

        Initial Capacity is 16

        */
        StringBuilder sb=new StringBuilder("SMART "); 
        System.out.println(sb);
        sb.reverse();
        System.out.println(sb);
        sb.insert(0, "Siddharth is ");
        System.out.println(sb);
        sb.delete(0,6);
        System.out.println(sb);
        StringBuffer sbuf=new StringBuffer("SMART "); 
        System.out.println(sbuf);
        StringTokenizer tok = new StringTokenizer("Siddharth Singha Roy", " ");
        while(tok.hasMoreTokens()) {
            System.out.println(tok.nextToken());
        }

    }
}