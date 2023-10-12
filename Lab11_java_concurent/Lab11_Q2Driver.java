package Lab11_java_concurent;

public class Lab11_Q2Driver {
    public static void main(String[] args){
        int numP = 2; int numC= 15 * numP;
        Lab11_Q2Producer[] producers = new Lab11_Q2Producer[numP];
        Lab11_Q2Consumer[] consumers = new Lab11_Q2Consumer[numC];
        Lab11_AdxBlockingQueue<Element> syncQ = new Lab11_AdxBlockingQueue<>(10);

        for(int i = 0;i < numP;i++){
            producers[i] = new Lab11_Q2Producer(i, syncQ);
            producers[i].start();
        }
        for(int j = 2;j < numC + 2;j++){
            consumers[j - 2] = new Lab11_Q2Consumer(j, syncQ);
            consumers[j - 2].start();
        }
        try{
            for(int i = 0;i < numP;i++){
                producers[i].join();
            }
        }catch(InterruptedException ie){}
        try{
            for(int j = 2;j < numC + 2;j++)
                consumers[j - 2].join();
        }catch(InterruptedException ie){
            for(int i = 0;i < numP;i++){
                System.out.printf("chief no. %d cooks %d\n",producers[i].id, producers[i].numCook);
            }
            System.out.println("bye");
        }
    }
}
