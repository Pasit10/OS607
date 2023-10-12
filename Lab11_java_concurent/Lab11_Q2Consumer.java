package Lab11_java_concurent;

public class Lab11_Q2Consumer extends Thread {
    int id;

    Lab11_AdxBlockingQueue<Element> queue;

    Lab11_Q2Consumer(int x,Lab11_AdxBlockingQueue<Element> q){
        id = x;
        queue = q;
    }

    public void run(){
        try{
            Element e = queue.take();
            System.out.println(id + " takes " + e.getVal());
        }catch(InterruptedException ie){ }
    }
}
