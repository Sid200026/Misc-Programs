class deadlock {

    public static void main(String[] args) {
        final String a = "a";
        final String b = "b";
        Thread d1 = new Thread() {
            public void run() {
                synchronized (a) {
                    System.out.println(" d1 Locked a");
                    try {
                        Thread.sleep(1000);
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                    synchronized (b) {
                        System.out.println("d1 Locked b");
                    }
                }
            }
        };
        Thread d2 = new Thread() {
            public void run() {
                synchronized (b) {
                    System.out.println(" d2 Locked b");
                    try {
                        Thread.sleep(1000);
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                    synchronized (a) {
                        System.out.println("d2 Locked a");
                    }
                }
            }
        };
        d1.start();
        d2.start();
    }
}