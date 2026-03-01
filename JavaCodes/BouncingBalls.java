import java.awt.*;
import java.awt.event.*;

public class BouncingBalls extends Frame implements Runnable {

    int x[] = {50, 100, 150, 200, 250};
    int y[] = {50, 100, 150, 200, 250};
    int dx[] = {2, 3, 4, 5, 6};
    int dy[] = {3, 4, 5, 6, 2};

    Color colors[] = {
        Color.RED, Color.BLUE, Color.GREEN, Color.ORANGE, Color.MAGENTA
    };

    public BouncingBalls() {
        setSize(500, 400);
        setTitle("Bouncing Balls using Thread");
        setVisible(true);

        Thread t = new Thread(this);
        t.start();

    }

    public void paint(Graphics g) {
        for (int i = 0; i < 5; i++) {
            g.setColor(colors[i]);
            g.fillOval(x[i], y[i], 30, 30);
        }
    }

    public void run() {
        while (true) {
            for (int i = 0; i < 5; i++) {
                x[i] += dx[i];
                y[i] += dy[i];

                if (x[i] < 0 || x[i] > 470) dx[i] = -dx[i];
                if (y[i] < 30 || y[i] > 370) dy[i] = -dy[i];
            }

            repaint();

            try {
                Thread.sleep(20);
            } catch (Exception e) {}
        }
    }

    public static void main(String[] args) {
        new BouncingBalls();
    }
}
