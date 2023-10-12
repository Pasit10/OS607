package Lab11_java_concurent;

public class Lab11_Q2Producer extends Thread{
    int id;
    protected Lab11_AdxBlockingQueue<Element> queue;
    int numCook = 0;

    Lab11_Q2Producer(int x,Lab11_AdxBlockingQueue<Element> q){
        id = x;
        queue = q;
    }

    public void run(){
        if(id % 2 == 0){
            int i = -1;
            while(i < 30){
                i += 2;
                try{
                    queue.put(new Element(i));
                    numCook++;
                    System.out.println("put " + i + " size = " + queue.size());
                }catch(InterruptedException ie){
                    System.out.println("Diner INTERRUPTED");
                }
            }
        }else{
            int i = 0;
            while(i < 29){
                i += 2;
                try{
                    queue.put(new Element(i));
                    numCook++;
                    System.out.println("put " + i + " size = " + queue.size());
                }catch(InterruptedException ie){
                    System.out.println("Diner INTERRUPTED");
                }
            }
        }
    }
}
