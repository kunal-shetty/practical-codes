public class RunnableDemo implements Runnable {

    public void run() {
        for(int i = 1; i <= 5; i++) {
            System.out.println("Runnable Thread: " + i);
            try {
                Thread.sleep(400);
            } catch(Exception e) {}
        }
    }

    public static void main(String[] args) {

        RunnableDemo obj = new RunnableDemo();
        Thread t1 = new Thread(obj);
        t1.start();

        for(int i = 1; i <= 5; i++) {
            System.out.println("Main Thread: " + i);
        }
    }
}