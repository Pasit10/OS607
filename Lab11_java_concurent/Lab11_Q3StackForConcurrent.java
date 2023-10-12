package Lab11_java_concurent;

public class Lab11_Q3StackForConcurrent {
    Node top;
    int size;

    public Lab11_Q3StackForConcurrent(){
        top = null;
        size = 0;
    }

    synchronized void push(int n){
        top = new Node(n, top);
        size++;
        if(top.next == null){
            notifyAll();
        }
    }

    synchronized int pop(){
        try{
            while(top == null){
                System.out.println("empty stack");
                wait();
            }
        }catch(InterruptedException ie){
                System.out.println("error");
                return 1;
        }
        size--; /* Q4.2 */
        int n = top.val;
        top = top.next;
        return n;
    }
}

class Node{
    int val;
    Node next;

    Node(int v){
        val = v;
    }

    Node(int v,Node n){
        val = v;
        this.next = n;
    }

    int getVal(){
        return val;
    }
}