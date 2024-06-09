import java.util.logging.Level;
import java.util.logging.Logger;

public class concurrencyCounter {

    private static final Logger logger = Logger.getLogger(concurrencyCounter.class.getName());
    private static final int SLEEP_DURATION = 100;
    private static final int COUNT_UP_LIMIT = 20;
    private static final int COUNT_DOWN_START = 20;
    private static final int COUNT_DOWN_END = 0;

    public static void main(String[] args) {
        // Create and name threads
        Thread countUp = new Thread(new CountUp(), "CountUpThread");
        Thread countDown = new Thread(new CountDown(), "CountDownThread");

        // Start the countUp thread
        countUp.start();

        // Wait for the countUp thread to finish
        try {
            countUp.join();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt(); // Reset the interrupt status
            logger.log(Level.SEVERE, "Main thread was interrupted while waiting for countUp.", e);
        }

        // Start the countDown thread
        countDown.start();

        // Wait for the countDown thread to finish
        try {
            countDown.join();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt(); // Reset the interrupt status
            logger.log(Level.SEVERE, "Main thread was interrupted while waiting for countDown.", e);
        }
    }

    // Runnable class that counts up from 1 to 20
    static class CountUp implements Runnable {
        @Override
        public void run() {
            try {
                for (int i = 1; i <= COUNT_UP_LIMIT; i++) { // Count up from 1 to 20
                    System.out.println("Count Up: " + i);
                    Thread.sleep(SLEEP_DURATION); // Sleep to simulate work to demonstrate concurrency
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt(); // Handle the interruption of the CountUp thread
                logger.log(Level.WARNING, "CountUp thread was interrupted.", e);
            }
        }
    }

    // Runnable class that counts down from 20 to 0
    static class CountDown implements Runnable {
        @Override
        public void run() {
            try {
                for (int i = COUNT_DOWN_START; i >= COUNT_DOWN_END; i--) { // Count down from 20 to 0
                    System.out.println("Count Down: " + i);
                    Thread.sleep(SLEEP_DURATION); // Sleep to simulate work to demonstrate concurrency
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt(); // Handle the interruption of the CountDown thread
                logger.log(Level.WARNING, "CountDown thread was interrupted.", e);
            }
        }
    }
}
