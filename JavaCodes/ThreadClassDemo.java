public class ThreadClassDemo extends Thread {

    public void run() {
        for(int i = 1; i <= 5; i++) {
            System.out.println("Child Thread: " + i);
            try {
                Thread.sleep(500);
            } catch(Exception e) {}
        }
    }

    public static void main(String[] args) {

        ThreadClassDemo t1 = new ThreadClassDemo();
        t1.start();

        for(int i = 1; i <= 5; i++) {
            System.out.println("Main Thread: " + i);
            try {
                Thread.sleep(500);
            } catch(Exception e) {}
        }
    }
}