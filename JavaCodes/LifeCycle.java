public class LifeCycle extends Thread {

    public void run() {
        System.out.println("Running State");

        try {
            Thread.sleep(1000);
            System.out.println("Timed Waiting State");
        } catch (Exception e) {
        }

        System.out.println("Running State again");
    }

    public static void main(String[] args) throws Exception {

        LifeCycle t = new LifeCycle();

        System.out.println("New State");

        t.start();
        System.out.println("Runnable State");

        t.join();

        System.out.println("Terminated State");
    }
}
