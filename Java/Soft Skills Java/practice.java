public class practice {

    static boolean check(String s) {
        for (int i = 0; i < s.length()-2; i++) {
            if (s.charAt(i) != s.charAt(i + 2)) {
                return false;
            }
        }
        return !(s.charAt(0) == s.charAt(1));
    }
    public static void main(String[] args) {
        String s = "ABABABABC";
        System.out.println(check(s) ? "Yes" : "No");
    }
}