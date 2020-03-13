class Thread_Revision extends Thread {

    @Override
    public void run() {
        Thread cur = Thread.currentThread();
        System.out.println(cur.getState());
        Thread t2 = new Thread() {
            public void run() {
                System.out.println("Test Run");
            }
        };
        t2.start();
        try{
            Thread.sleep(1000);
            // System.out.println(cur.getState());
        } catch (Exception e) {
            e.printStackTrace();
        }
        System.out.println(t2.getState());
    }
    public static void main(String[] args) {
        Thread t1 = new Thread_Revision();
        System.out.println(t1.getState());
        t1.start();
        System.out.println(t1.getState());
    }
}