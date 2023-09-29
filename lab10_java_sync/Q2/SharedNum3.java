package lab10_java_sync.Q2;

public class SharedNum3 {
    private int val = 0;

    synchronized void increment(){
        val++;
    }

    int getVal(){return val;}
}
