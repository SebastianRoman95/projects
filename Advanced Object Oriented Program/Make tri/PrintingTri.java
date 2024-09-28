import java.util.Scanner;

import java.io.*;
public class PrintingTri {
    public static void main(String args[]){
        int col=5;

        for(int c =0; c < col;c++){
            //System.out.println("/");
            //System.out.println("");
            for(int r =0; r <= c;r++){
                System.out.println("* ");   
            }
            System.out.println();   
        }
    }
}

