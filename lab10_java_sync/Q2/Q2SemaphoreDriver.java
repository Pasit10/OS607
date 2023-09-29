package lab10_java_sync.Q2;

public class Q2SemaphoreDriver {
    public static void main(String[] args) {
        int nThread = 100000;
        SharedNum2 sn = new SharedNum2();
        //SharedNum3 sn = new SharedNum3();
        //SharedNum4 sn = new SharedNum4();
        Thread[] thr = new Thread[nThread];
        for(int i = 0;i < nThread;i++){
            thr[i] = new Thread(new Runnable() {
                @Override public void run(){
                    sn.increment();
                }
            });
            thr[i].start();
        }
        for(int i = 0;i < nThread;i++){
            try{
                thr[i].join();
            }catch(InterruptedException ie){}
        }
        if(sn.getVal() < nThread){
            System.out.println("v0 val = " + sn.getVal() + " Not 100,000");
        }else{
            System.out.println("v0 good job! val = " + sn.getVal());
        }
    }
}
