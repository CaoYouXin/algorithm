package algorithm.threads;

import java.util.concurrent.Semaphore;

public class H2O {
    public static void main(String[] args) {
        int len = 99;

        Runnable releaseHydrogen = new Runnable() {
            private int i = 0;

            @Override
            public void run() {
                if (this.i >= len * 2 / 3)
                    throw new RuntimeException();

                System.out.print('H');
                this.i++;
            }
        };

        Runnable releaseOxygen = new Runnable() {
            private int i = 0;

            @Override
            public void run() {
                if (this.i >= len * 1 / 3)
                    throw new RuntimeException();

                System.out.print('O');
                this.i++;
            }
        };

        H2O h2o = new H2O();
        new Thread() {

            @Override
            public void run() {
                while (true)
                    try {
                        h2o.hydrogen(releaseHydrogen);
                    } catch (Exception e) {
                        break;
                    }
            }
        }.start();
        new Thread() {

            @Override
            public void run() {
                while (true)
                    try {
                        h2o.oxygen(releaseOxygen);
                    } catch (InterruptedException e) {
                        break;
                    }
            }
        }.start();
        new Thread() {

            @Override
            public void run() {
                while (true)
                    try {
                        h2o.hydrogen(releaseHydrogen);
                    } catch (InterruptedException e) {
                        break;
                    }
            }
        }.start();
    }

    private Semaphore h = new Semaphore(2);
    private Semaphore o = new Semaphore(0);

    public H2O() {
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        h.acquire();
        try {
            releaseHydrogen.run();
        } catch (Exception e) {
            throw new InterruptedException();
        } finally {
            o.release();
        }
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        o.acquire(2);
        try {
            releaseOxygen.run();
        } catch (Exception e) {
            throw new InterruptedException();
        } finally {
            h.release(2);
        }
    }
}
