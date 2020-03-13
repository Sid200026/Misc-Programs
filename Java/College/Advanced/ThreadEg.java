public class ThreadEg extends Thread {



    // @Override
    // public void run() {
    //     Thread cur = currentThread();
    //     System.out.println(cur.getState());
    //     cur.setName("Siddharth");
    //     try{
    //         Thread.sleep(1000);
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
    //     System.out.println(currentThread());
    //     for(int i = 0; i<3;i++) {
    //         // ThreadEg t = new ThreadEg();
    //         Thread t = new ThreadEg();
    //         System.out.println("Starting : "+t.getState());
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
    //     }
    // }





    static Integer a = 5;
    static Integer b = 6;

    // public static synchronized void incrementA() {
    //     a++;
    // }




    public static void incrementA() {
        synchronized(a) { // cannot use int a, we need reference (Integer)
            synchronized(b) {
                a++;
                b++;
            }
        }
    }




    @Override
    public void run() {
        // Never join current thread
        System.out.println("Thread started" + currentThread().getId());
        try{
            Thread.sleep(1000);
        } catch (Exception e) {
            e.printStackTrace();
        }




        // synchronized(a) { // cannot use int a, we need reference (Integer)
        //     synchronized(b) {
        //         a++;
        //         b++;
        //     }
        // }




        // Instead of writing a and b, this method allows us to pass the current object instance
        // as parameter to this. This gives us the flexibility of not writing Integer a,b
        // synchronized(this) {
        //     this.a+=this.b;
        // }



        ThreadEg.incrementA();



        System.out.println(a+" "+b);
    }
    public static void main(String[] args) {
        for(int i = 0; i<5;i++) {
            Thread t = new ThreadEg();
            t.start();
            } 
        }
    }