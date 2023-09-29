package lab7_thread;

import java.util.Arrays;

public class Lab_MatrixMul {
    public static void main(String[] args) {
        int[][] inputA = {{5,6,7},{4,8,9}};
        int[][] inputB = {{6,4},{5,7},{1,1}};
        MyData matA = new MyData(inputA);
        MyData matB = new MyData(inputB);
        int matC_r = matA.data.length;
        int matC_c = matB.data[0].length;
        MyData matC = new MyData(matC_r, matC_c);
        Thread[] allthread = new Thread[matC_c * matC_r];
        int idx = 0;
        for(int i = 0;i < matC_r;i++){
            for(int j = 0;j < matC_c;j++){
                allthread[idx] = new Thread(new MatrixMulThread(i, j, matA, matB, matC));
                allthread[idx].start();
                System.out.println(allthread[idx].getId());
                idx++;
            }
        }
        try{
            for(Thread t:allthread){
                System.out.println(t.getId());
                t.join();
            }
        }catch(Exception e){
            e.printStackTrace();
        }
        matC.show();
    }
}

class MatrixMulThread implements Runnable{
    int processing_row; int processing_col;
    MyData datA,datB,datC;
    MatrixMulThread(int tRow,int tcol,MyData a,MyData b,MyData c){
        processing_row = tRow;
        processing_col = tcol;
        datA = a;
        datB = b;
        datC = c;
    }
    public void run(){
        int sum = 0;
        for(int i = 0;i < datA.data[0].length;i++){
           sum += datA.data[processing_row][i] * datB.data[i][processing_col];
        }
        datC.data[processing_row][processing_col] = sum;
    }
}

class MyData{
    int[][] data;
    MyData(int[][] m){
        data = m;
    }
    MyData(int r,int c){
        data = new int[r][c];
        for(int[] aRow: data){
            Arrays.fill(aRow,0);
        }
    }
    void show(){
        System.out.println(Arrays.deepToString(data));
    }
}
