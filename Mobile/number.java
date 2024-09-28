import java.io.*;
public class number {
    public static void main(String args[]){
    //declare
        int[] arr = new int[10];
        //int[] arrUse = new int[10];

        for(int i =0; i < arr.length;i++){
            Scanner s=new Scanner(System.in);
            int num = s.nextInt();
            arr[i]=num;
        }
    
        //compare
        System.out.println("First index:" + "\t" + "First index number:" + "\t" + "Second index:" + "\t" + "Second index number:" + "\t" + "If they are the same:" + "\n");
        for(int i =0; i < arr.length;i++){
            for(int k=i+1; k<arr.length;k++){
                if(arr[i]!=arr[k]){
                    System.out.println(i + "\t" + arr[i] + "\t" + k + "\t" + arr[k] + "\t" + "No" + "\n");
                }
                else{
                    System.out.println(i + "\t" + arr[i] + "\t" + k + "\t" + arr[k] + "\t" + "Yes" + "\n");
                }
            }
        }
    }
}

