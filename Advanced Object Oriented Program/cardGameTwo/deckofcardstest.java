import java.util.Scanner;
public class deckofcardstest {
    public static void main(String[]args){
        deckofcards mydeckofcards = new deckofcards();
        mydeckofcards.shuffle();

        card[]hand=new card[5];
        System.out.println("*******************************************************************************************************");
        //shuffle
        for(int i=1; i <=52;i++){
            System.out.printf("%-19s", mydeckofcards.dealCard());
            if(i%4==0){
                System.out.println();
            }
        }

        //player one
        int numP1= mydeckofcards.winP1();
        if(numP1==6){
            System.out.println("Straight Flush");
        }
        else if(numP1==5){
            System.out.println("Four of a Kind");
        }
        else if(numP1==4){
            System.out.println("Flush");
        }
        else if(numP1==3){
            System.out.println("Three of a Kind");
        }
        else if(numP1==2){
            System.out.println("Two Pairs");
        }
        else if(numP1==1){
            System.out.println("Pair");
        }
        else if(numP1==0){
            System.out.println("You Lose");
        }  

        //player one vs player two
        mydeckofcards.shuffle();
        int num= mydeckofcards.winP1(), num2=mydeckofcards.winP2(); 
        //System.out.println("P1 "+num+" P2"+num2);
        if(num>num2){
            System.out.println("Player one wins!");
        }
        else if(num<num2){
            System.out.println("Player two  wins!");
        }
        else{
            System.out.println("Tie!");
        }

        System.out.println("*******************************************************************************************************");
        mydeckofcards.shuffle();
        Scanner input = new Scanner(System.in);
        System.out.println("Would you like to draw an another card? If so please type yes. If not type no.");
        String answer = input.nextLine();
        int drawingHiddenCard=5;
        
        //grab user input 
        if(answer.equals("yes")){
            while(answer.equals("yes")){        
                System.out.println("Would you like to draw an another card? If so please type yes. If not type no.");
                answer = input.nextLine();
                drawingHiddenCard++;
            }
            num= mydeckofcards.HiddenDealer(drawingHiddenCard);//grab user input
            if(num==6){
                System.out.println("Straight Flush");
            }
            else if(num==5){
                System.out.println("Four of a Kind");
            }
            else if(num==4){
                System.out.println("Flush");
            }
            else if(num==3){
                System.out.println("Three of a Kind");
            }
            else if(num==2){
                System.out.println("Two Pairs");
            }
            else if(num==1){
                System.out.println("Pair");
            }
            else if(num==0){
                System.out.println("You Lose");
            }         
        }else if (answer.equals("no")){    
            num= mydeckofcards.HiddenDealer(drawingHiddenCard);
            if(num==6){
                System.out.println("Straight Flush");
            }
            else if(num==5){
                System.out.println("Four of a Kind");
            }
            else if(num==4){
                System.out.println("Flush");
            }
            else if(num==3){
                System.out.println("Three of a Kind");
            }
            else if(num==2){
                System.out.println("Two Pairs");
            }
            else if(num==1){
                System.out.println("Pair");
            }
            else if(num==0){
                System.out.println("You Lose");
            }  
        }

        //p1 vs cup
        for(int p=1;p<=20;p++){
            int numb1=0, numb2=0, numb3=0;
            mydeckofcards.shuffle();
            //need to add show hand function
            System.out.println("*******************************************************************************************************");
            System.out.println("Would you like to change your hand? yes or no?");
            String YorN = input.nextLine();
            if(YorN.equals("yes")){
                System.out.println("what cards would you like to remove from your hand 1-5. If none then enter any number");
                numb1 = input.nextInt();
                numb2 = input.nextInt();
                numb3 = input.nextInt();
            }
            num= mydeckofcards.POneVSCup(YorN, numb1, numb2, numb3);
            if(num==1){
                System.out.println("Original hand wins");
            }
            else if(num==2){
                System.out.println("New hand wins");
            }
            else{
                if(num==1){
                    System.out.println("Computer wins");
                }
            }
        }
        
        

        //fish yates
        System.out.println("*******************************************************************************************************");
        System.out.println("Fisher yates shuffle");
        mydeckofcards.FishShuffle();
        for(int i=1; i <=52;i++){
            System.out.printf("%-19s", mydeckofcards.dealCard());
            if(i%4==0){
                System.out.println();
            }
        }
        System.out.println("*******************************************************************************************************");

    }   
}
