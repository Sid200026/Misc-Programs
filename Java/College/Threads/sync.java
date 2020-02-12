class wait {
    public void run() {
        System.out.println("Start");
        try {
            Thread.sleep(1000);
        } catch (Exception e) {
            System.out.println("Thread  interrupted.");
        }
        System.out.println("End");
    }

    public synchronized void resume() {
        System.out.println("Pause");
        try {
            Thread.sleep(1000);
        } catch (Exception e) {
            System.out.println("Thread  interrupted.");
        }
        System.out.println("Resume");
    }

    public static synchronized void stop() {
        System.out.println("Stopping");
        try {
            Thread.sleep(1000);
        } catch (Exception e) {
            System.out.println("Thread  interrupted.");
        }
        System.out.println("Stopped");
    }
}

public class sync extends Thread {

    public void run() {
        wait w = new wait();
        synchronized (w) {
            w.run();
        }
    }

    public void play() {
        wait w = new wait();
        w.resume();
    }

    public void stopped() {
        wait.stop();
    }

    public static void main(String[] args) {
        for (int i = 0; i < 3; i++) {
            sync s = new sync();
            s.run();
            s.play();
            s.stopped();
        }
    }
}