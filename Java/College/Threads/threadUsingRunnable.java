class threadUsingRunnable implements Runnable {
    public void run() {
        System.out.println("Thread using runnable interface");
    }

    public static void main(String[] args) {
        threadUsingRunnable tr = new threadUsingRunnable();
        tr.run();
    }
}