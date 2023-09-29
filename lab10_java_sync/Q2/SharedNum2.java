package lab10_java_sync.Q2;

import java.util.concurrent.Semaphore;

public class SharedNum2 {
    private int val = 0;
    private Semaphore mutex;

    SharedNum2(){
        mutex = new Semaphore(1);
        val = 0;
    }

    void increment(){
        try{
            mutex.acquire();
            val++;
            mutex.release();
        }catch(InterruptedException ie){}
    }

    int getVal(){return val;}
}
