import java.util.*;

abstract class Themepark {
    final int adult = 500;
    final int child = 300;

    abstract int getCost(int m, int n);

    abstract void playGame(int inp);

}

class Queensland extends Themepark {

    int[] game = new int[30];
    final int size = 30;

    @Override
    public int getCost(int m, int n) {
        return n * adult + m * child;
    }

    @Override
    public void playGame(int inp) {
        if (game[inp] != 0) {
            System.out.println("Game already played");
        } else {
            game[inp] = 1;
            System.out.println("Play Game");
        }
    }
}

class Wonderla extends Themepark {

    int[] game = new int[40];
    final int size = 40;
    int repeatCount = 0;

    @Override
    public int getCost(int m, int n) {
        return n * adult + m * child;
    }

    @Override
    public void playGame(int inp) {
        if (game[inp] != 0) {
            repeatCount++;
        } else {
            game[inp] = 1;
        }
        System.out.println("Play Game");
    }

    public int getReplayed() {
        return repeatCount;
    }

    public int left() {
        int count = 0;
        for(int gm:game) {
            if(gm!=0) {
                count++;
            }
        }
        return size - count;
    }
}

public class Park {
    public static void main(String[] args) {
        System.out.println("Enter quit to exit");
        Scanner sc = new Scanner(System.in);
        System.out.println("Number of adults");
        int adult = sc.nextInt();
        System.out.println("Number of children");
        int child = sc.nextInt();
        System.out.println("\n-------Queensland------\n");
        Queensland q = new Queensland();
        System.out.println("Cost : "+q.getCost(child, adult));
        System.out.println();
        while(true) {
            System.out.println("Enter game code");
            String in = sc.next();
            if(in.equalsIgnoreCase("quit")) {
                break;
            }
            int inp = Integer.parseInt(in);
            q.playGame(inp);
            System.out.println();
        }
        System.out.println("\n-------Wonderla------\n");
        Wonderla w = new Wonderla();
        System.out.println("Cost : "+w.getCost(child, adult));
        while(true) {
            System.out.println("Enter game code");
            String in = sc.next();
            if(in.equalsIgnoreCase("quit")) {
                break;
            }
            int inp = Integer.parseInt(in);
            w.playGame(inp);
            System.out.println();
        }
        System.out.println("Games Replayed : "+w.getReplayed());
        System.out.println("Games left : "+w.left());
    }
}