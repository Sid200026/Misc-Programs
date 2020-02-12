class thread_creation extends Thread {

    public void startNew() {
        System.out.println("Starting a new thread");
    }

    public static void main(String[] args) {
        thread_creation tc = new thread_creation();
        tc.startNew();
    }
}