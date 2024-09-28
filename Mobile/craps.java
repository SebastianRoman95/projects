import java.security.SecureRandom;

public class craps {
    public static void main(String args[]){
        //declare
        SecureRandom randNumbers =SecureRandom();
        int[]turnsL=new int[20];
        int[]turns=new int[20];
        int dice1=0;
        int dice2=0;
        int score=0;
        int point;
        int total=0;
        int avg;
        

        for(int roll=1;roll<=1000;roll++){
            //rolls
            dice1=1+randomNumbers.nextInt(6);
            dice2=1+randomNumbers.nextInt(6);
            score=dice1+dice2;
            int turn=1;

            //win
            if(score==11||score==7){
                ++turns[turn];
            } //lost
            else if(score==2||score==3||score==12){
                ++turnsL[turn];
            } //if you win or lose
            else{
                point=score;
                boolean b==false;

                while(b==true){
                    //rolls
                    dice1=1+randomNumbers.nextInt(6);
                    dice2=1+randomNumbers.nextInt(6);
                    score=dice1+dice2;
                    ++turn; //counter

                    //win
                    if(score==point){
                        if(turn>20){
                            turn=20;
                        }
                        turns[turn];
                        b==true;
                        break;
                    } //lost
                    else if(score==7){
                        if(turn>20){
                            turn=20;
                        }
                        turnsL[turn];
                        b==true;
                        break;
                    }
                }
            }
        }

        //print
        for(int n=1;n < turns.length;n++){
            System.out.printf(turns[n] + "\tgames won and \t" + turnsL[n] + "\t games lost on roll \t" + n + "\n");
            total+=turns[n];
        }
        avg=total/1000;
        System.out.printf("The chances of winning is " + total + "\n the average is " + avg + "\n")
    } 
}