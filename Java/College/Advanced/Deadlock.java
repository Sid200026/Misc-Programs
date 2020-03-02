
public class Deadlock implements Runnable{
    Integer a = 5;
    Integer b = 6;
    @Override
    public void run() {
        synchronized(a) {
            try{
                Thread.sleep(1000);
            } catch (Exception e) {}
            synchronized(b) {

            }
        }
        synchronized(b) {
            try{
                Thread.sleep(1000);
            } catch (Exception e) {}
            synchronized(a) {

            }
        }
    }
    public static void main(String[] args) {
        Deadlock d1 = new Deadlock();
        Thread t1 = new Thread(d1);
        Deadlock d2 = new Deadlock();
        Thread t2 = new Thread(d2);
        t1.start();
        t2.start();
    }
}