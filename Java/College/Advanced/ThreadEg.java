public class ThreadEg extends Thread {

    // @Override
    // public void run() {
    //     Thread cur = currentThread();
    //     System.out.println(cur.getState());
    //     try{
    //         Thread.sleep(5000);
    //     } catch (Exception e) {
    //         e.printStackTrace();
    //     }
    //     for(int i = 0; i<5; i++) {
    //         System.out.println(i+" "+cur.getName());
    //         // cur.setName("Siddharth");
    //         System.out.println(cur.getState());
    //     }
    // }
    // public static void main(String[] args) {
    //     for(int i = 0; i<3;i++) {
    //         Thread t = new ThreadEg();
    //         t.start();
    //     }
    // }

    // @Override
    // public void run() {
    //     // Never join current thread
    //     System.out.println("Thread started" + currentThread().getId());
    //     try{
    //         Thread.sleep(1010);
    //     } catch (Exception e) {
    //         e.printStackTrace();
    //     }
    //     System.out.println("Thread ended" + currentThread().getId());
    // }
    // public static void main(String[] args) {
    //     for(int i = 0; i<3;i++) {
    //         Thread t = new ThreadEg();
    //         t.start();
    //         try{
    //             t.join();
    //         } catch (Exception e) {
    //             e.printStackTrace();
    //         }
    //     }
    // }
    // static int a = 5;
    // @Override
    // public void run() {
    //     // Never join current thread
    //     System.out.println("Thread started" + currentThread().getId());
    //     try{
    //         Thread.sleep(1000);
    //     } catch (Exception e) {
    //         e.printStackTrace();
    //     }
    //     a++;
    //     System.out.println(a);
    // }
    // public static void main(String[] args) {
    //     for(int i = 0; i<5;i++) {
    //         Thread t = new ThreadEg();
    //         t.start();
    //         try{
    //             t.join();
    //         } catch (Exception e) {}
    //         }
    //     }
    // }

    static Integer a = 5;

    // public synchronized void incrementA() {
    //     a++;
    // }

    // public synchronized void incrementA() {
    //     a++;
    // }

    public void incrementA() {
        synchronized(a){
            a++;
        }
    }

    public void run() {
        // Never join current thread
        System.out.println("Thread started" + currentThread().getId());
        // try{
        //     Thread.sleep(1000);
        // } catch (Exception e) {
        //     e.printStackTrace();
        // }
        // synchronized(a){ // cannot use int a, we need reference (Integer)
        //     a++;
        // }
        incrementA();
        System.out.println(a);
    }
    public static void main(String[] args) {
        for(int i = 0; i<5;i++) {
            Thread t = new ThreadEg();
            t.start();
            }
        }
    }
// }