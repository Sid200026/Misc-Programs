import java.util.Scanner;

public class Switch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char ch = sc.next().charAt(0);
        switch(ch) {
            case 'A':
                System.out.println("Case : A");
                break;
            case 'B':
                System.out.println("Case : B");
                break;
            default:
                System.out.println("Default");
        }
    }
}