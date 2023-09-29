package lab10_java_sync.Q1;

public class SharedNum1 {
    private int val = 0;

    void increment(){
        val++;
    }

    int getVal(){
        return val;
    }
}
