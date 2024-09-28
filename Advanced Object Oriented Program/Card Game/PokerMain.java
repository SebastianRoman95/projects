import java.util.Scanner;

public class PokerMain {
    public static void main(String[] args){
        deckcards myDeck = new deckcards();
        myDeck.shuffle();

        //print the cards
        for(int i=1; i <=52;i++){
            System.out.printf("%-19s", myDeck.dealCard());
            if(i%4==0){
                System.out.println();
            }
        }

        int numP1= myDeck.winP1();
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

        myDeck.shuffle();
        //player one vs player two
        int num= myDeck.winP1(), num2=myDeck.winP2(); 
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

        myDeck.shuffle();
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
            num= myDeck.HiddenDealer(drawingHiddenCard);//grab user input
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
            num= myDeck.HiddenDealer(drawingHiddenCard);
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
    }
}
