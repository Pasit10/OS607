package lab10_java_sync.Q3;

public class Q3WaitNotifyDriver {
    public static void main(String[] args) {
        SharedNum5 sn = new SharedNum5();
        (new Thread(new Runnable() {
            @Override public void run(){
                System.out.println("got " + sn.getVal());
            }
        })).start();
        try{
            Thread.sleep(2); // main
        }catch(InterruptedException ie){}
        (new Thread(new Runnable() {
                @Override public void run(){
                    sn.setVal(2021);
                }
        })).start();
        System.out.println("from main");
    }
}
