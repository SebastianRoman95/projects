import java.util.*;
import java.security.SecureRandom;
public class deckofcards {
    private static final String[]faces={"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    private static final String[] suits= {"Heart", "Diamond", "Club", "Spade"};
    private static final Random randomNumbers = new Random();
    private static final int NUMBER_OF_CARDS = 52;

    private card[]deck;
    private int currentCard;

    public deckofcards(){
        deck=new card[NUMBER_OF_CARDS];
        currentCard=0;

        for(int count=0;count<deck.length;count++){
            deck[count]= new card(faces[count%13],suits[count/13]);
        }
    }

    //shuffle
    public void shuffle(){
        currentCard=0;

        for(int first =0; first < deck.length; first++){
            int second = randomNumbers.nextInt(NUMBER_OF_CARDS);
            card temp = deck[first];
            deck[first]=deck[second];
            deck[second]=temp;
        }
    }

    //deal
    public card dealCard(){
        if(currentCard<deck.length){
            return deck[currentCard++];
        }
        else{
            return null;
        }
    }


    public int winP1(){
        //player 1
        String[] playerFaceHand = new String[5];
        String[] playerSuitHand= new String[5];
        int[] playerFaceHandNum = new int[5];
        int score=0;   
        System.out.println("*******************************************************************************************************");
        System.out.println("Hand of Player 1");    
        for(int countHand =0; countHand < 5;countHand++){
            //face
            playerFaceHand[countHand]= deck[countHand].getFace();
            //suit
            playerSuitHand[countHand] = deck[countHand].getSuit();
            System.out.println(playerFaceHand[countHand] + " of " + playerSuitHand[countHand]);
            //change the string to int
            if(playerFaceHand[countHand]=="Ace"){
                playerFaceHandNum[countHand]=1;
            }
            else if(playerFaceHand[countHand]=="Deuce"){
                playerFaceHandNum[countHand]=2;
            }
            else if(playerFaceHand[countHand]=="Three"){
                playerFaceHandNum[countHand]=3;
            }
            else if(playerFaceHand[countHand]=="Four"){
                playerFaceHandNum[countHand]=4;
            }
            else if(playerFaceHand[countHand]=="Five"){
                playerFaceHandNum[countHand]=5;
            }
            else if(playerFaceHand[countHand]=="Six"){
                playerFaceHandNum[countHand]=6;
            }
            else if(playerFaceHand[countHand]=="Seven"){
                playerFaceHandNum[countHand]=7;
            }
            else if(playerFaceHand[countHand]=="Eight"){
                playerFaceHandNum[countHand]=8;
            }
            else if(playerFaceHand[countHand]=="Nine"){
                playerFaceHandNum[countHand]=9;
            }
            else if(playerFaceHand[countHand]=="Ten"){
                playerFaceHandNum[countHand]=10;
            }
            else if(playerFaceHand[countHand]=="Jack"){
                playerFaceHandNum[countHand]=11;
            }
            else if(playerFaceHand[countHand]=="Queen"){
                playerFaceHandNum[countHand]=12;
            }
            else if(playerFaceHand[countHand]=="King"){
                playerFaceHandNum[countHand]=13;
            }
        }

        //sort to find the flushes
        Arrays.sort(playerFaceHandNum);
        //check if they are by each other
        int num=0;
        for(int i =0; i < 4;i++){
            if(playerFaceHandNum[i+1]==10&&playerFaceHandNum[i]==1&&playerFaceHandNum[4]==13){//edge case for ace
                num++;
            }
            else if(playerFaceHandNum[i+1]-playerFaceHandNum[i]==1){
                num++;
            }
            else{
                break;
            }
        }
        //check if they are a straight flush or flush
        if(num==5){
            for(int i =0; i < 4;i++){
                if(playerSuitHand[i+1]==playerSuitHand[i]){
                    score=6;
                }
                else{
                    score=4;
                    break;
                }
            }
        }
        
        //checking the dupe numbers for kinds and pairs
        Map<Integer, Integer> count = new HashMap<Integer, Integer>();
        for(int i =0; i < 4;i++){
            if(playerFaceHandNum[i]==playerFaceHandNum[i+1]){
                num++;
                count.put(playerFaceHandNum[i],num);
            }
            else{
                num=1;
            }
        }

        //grabbing the highest dupe
        int dupe=0, dupe2=0;
        for(Integer value:count.values()){
            //System.out.println("val 1:" + value);
            if(value>dupe){
                dupe=value;
                //System.out.println("set dupe val 1:" + value);
            }
            else if(value==dupe){
                dupe2=value;
            }
        }
        //scores for kinds and pairs
        //System.out.println("player 1" + dupe);
        if(dupe==0&&dupe2==0){
            dupe2=-1;
        }
        if(dupe==4){//4 of a kind
            if(score<6){
                score=5;
            }  
        }
        else if(dupe==3){//3 of a kind
            if(score<4){
                score=3;
            }
        }
        else if(dupe==dupe2){//2 pairs
            if(score<4){
                score=2;
            }
        }
        else if(dupe==2){
            if(score<4){
                score=1;
            } 
        }
        //System.out.println("player 1 score" + score);
        return score;
    }

    
    //player 2
    public int winP2(){
        //player 2
        String[] playerFaceHand = new String[5];
        String[] playerSuitHand= new String[5];
        int[] playerFaceHandNum = new int[5];
        int score=0;       
        System.out.println("*******************************************************************************************************");
        System.out.println("Hand of PLayer 2");
        for(int countHand =0; countHand < 5;countHand++){
            //face
            playerFaceHand[countHand]= deck[countHand+5].getFace();
            //suit
            playerSuitHand[countHand] = deck[countHand+5].getSuit();
            System.out.println(playerFaceHand[countHand] + " of " + playerSuitHand[countHand]);
            //change the string to int
            if(playerFaceHand[countHand]=="Ace"){
                playerFaceHandNum[countHand]=1;
            }
            else if(playerFaceHand[countHand]=="Deuce"){
                playerFaceHandNum[countHand]=2;
            }
            else if(playerFaceHand[countHand]=="Three"){
                playerFaceHandNum[countHand]=3;
            }
            else if(playerFaceHand[countHand]=="Four"){
                playerFaceHandNum[countHand]=4;
            }
            else if(playerFaceHand[countHand]=="Five"){
                playerFaceHandNum[countHand]=5;
            }
            else if(playerFaceHand[countHand]=="Six"){
                playerFaceHandNum[countHand]=6;
            }
            else if(playerFaceHand[countHand]=="Seven"){
                playerFaceHandNum[countHand]=7;
            }
            else if(playerFaceHand[countHand]=="Eight"){
                playerFaceHandNum[countHand]=8;
            }
            else if(playerFaceHand[countHand]=="Nine"){
                playerFaceHandNum[countHand]=9;
            }
            else if(playerFaceHand[countHand]=="Ten"){
                playerFaceHandNum[countHand]=10;
            }
            else if(playerFaceHand[countHand]=="Jack"){
                playerFaceHandNum[countHand]=11;
            }
            else if(playerFaceHand[countHand]=="Queen"){
                playerFaceHandNum[countHand]=12;
            }
            else if(playerFaceHand[countHand]=="King"){
                playerFaceHandNum[countHand]=13;
            }
        }

        //sort to find the flushes
        Arrays.sort(playerFaceHandNum);
        //check if they are by each other
        int num=0;
        for(int i =0; i < 4;i++){
            if(playerFaceHandNum[i+1]==10&&playerFaceHandNum[i]==1&&playerFaceHandNum[4]==13){//edge case for ace
                num++;
            }
            else if(playerFaceHandNum[i+1]-playerFaceHandNum[i]==1){
                num++;
            }
            else{
                break;
            }
        }
        //check if they are a straight flush or flush
        if(num==5){
            for(int i =0; i < 4;i++){
                if(playerSuitHand[i+1]==playerSuitHand[i]){
                    score=6;
                }
                else{
                    score=4;
                    break;
                }
            }
        }
        
        //checking the dupe numbers for kinds and pairs
        Map<Integer, Integer> count = new HashMap<Integer, Integer>();
        for(int i =0; i < 4;i++){
            if(playerFaceHandNum[i]==playerFaceHandNum[i+1]){
                num++;
                count.put(playerFaceHandNum[i],num);
            }
            else{
                num=1;
            }
        }

        //grabbing the highest dupe
        int dupe=0, dupe2=0;
        for(Integer value:count.values()){
            //System.out.println("val 2:" + value);
            if(value>dupe){
                dupe=value;
               // System.out.println("set val 2:" + value);
            }
            else if(value==dupe){
                dupe2=value;
            }
        }
        //System.out.println("player 2" + dupe);
        //scores for kinds and pairs
        if(dupe==0&&dupe2==0){
            dupe2=-1;
        }
        if(dupe==4){//4 of a kind
            if(score<6){
                score=5;
            }  
        }
        else if(dupe==3){//3 of a kind
            if(score<4){
                score=3;
            }
        }
        else if(dupe==dupe2){//2 pairs
            if(score<4){
                score=2;
            }
        }
        else if(dupe==2){
            if(score<4){
                score=1;
            } 
        }
        //System.out.println("player 2 score" + score);
        return score;
    }

    //dealers
    public int HiddenDealer(int userInput){//take user input her
        String[] playerFaceHand = new String[userInput];
        String[] playerSuitHand= new String[userInput];
        int[] playerFaceHandNum = new int[userInput];
        int score=0;    
        //System.out.println("Dealer");   
        for(int countHand =0; countHand < userInput;countHand++){
            //face
            playerFaceHand[countHand]= deck[countHand].getFace();
            //suit
            playerSuitHand[countHand] = deck[countHand].getSuit();
            //System.out.println(playerFaceHand[countHand] + " of " + playerSuitHand[countHand]);
            //change the string to int
            if(playerFaceHand[countHand]=="Ace"){
                playerFaceHandNum[countHand]=1;
            }
            else if(playerFaceHand[countHand]=="Deuce"){
                playerFaceHandNum[countHand]=2;
            }
            else if(playerFaceHand[countHand]=="Three"){
                playerFaceHandNum[countHand]=3;
            }
            else if(playerFaceHand[countHand]=="Four"){
                playerFaceHandNum[countHand]=4;
            }
            else if(playerFaceHand[countHand]=="Five"){
                playerFaceHandNum[countHand]=5;
            }
            else if(playerFaceHand[countHand]=="Six"){
                playerFaceHandNum[countHand]=6;
            }
            else if(playerFaceHand[countHand]=="Seven"){
                playerFaceHandNum[countHand]=7;
            }
            else if(playerFaceHand[countHand]=="Eight"){
                playerFaceHandNum[countHand]=8;
            }
            else if(playerFaceHand[countHand]=="Nine"){
                playerFaceHandNum[countHand]=9;
            }
            else if(playerFaceHand[countHand]=="Ten"){
                playerFaceHandNum[countHand]=10;
            }
            else if(playerFaceHand[countHand]=="Jack"){
                playerFaceHandNum[countHand]=11;
            }
            else if(playerFaceHand[countHand]=="Queen"){
                playerFaceHandNum[countHand]=12;
            }
            else if(playerFaceHand[countHand]=="King"){
                playerFaceHandNum[countHand]=13;
            }
        }

        //sort to find the flushes
        //add an array that will get sorted
        //add an array that will sort the num
        int[] NewHandNum = playerFaceHandNum;
        Arrays.sort(NewHandNum);
        String[] NewSuitHand= new String[userInput];
        Set<Integer> NewFaceHandNum = new HashSet<Integer>();
        
        //check if they are by each other
        int num=0, UserSize=userInput-1;
        for(int i =0; i < UserSize;i++){
            //put this in the map so you do not have to deal with dupes of ten
            if(NewHandNum[0]==1&&NewHandNum[i]==10&&NewHandNum[UserSize]==13){//edge case for ace
                num+=2;
                NewFaceHandNum.add(NewHandNum[0]);
                NewFaceHandNum.add(NewHandNum[i]);
                NewFaceHandNum.add(NewHandNum[UserSize]);
            }
            else if(NewHandNum[i+1]-NewHandNum[i]==1){
                num+=2;
                NewFaceHandNum.add(NewHandNum[i+1]);
                NewFaceHandNum.add(NewHandNum[i]);
            }
            else if (NewHandNum[i+1]-NewHandNum[i]>1){
                if(num<8){
                    num=0;
                }
            }
        }
        /*
        for(Integer value:NewFaceHandNum){
            System.out.print(value+", ");
        }*/
        //check if they are a straight flush or flush
        if(num>=8){
            for(int i =0; i < 4;i++){
                if(playerSuitHand[i+1]==playerSuitHand[i]){//you might need to do pairs 
                    score=6;
                }
                else{
                    score=4;
                    break;
                }
            }
        }
        
        //checking the dupe numbers for kinds and pairs
        Map<Integer, Integer> count = new HashMap<Integer, Integer>();
        for(int i =0; i < UserSize;i++){
            if(playerFaceHandNum[i]==playerFaceHandNum[i+1]){
                num++;
                count.put(playerFaceHandNum[i],num);
            }
            else{
                num=1;
            }
        }

        //grabbing the highest dupe
        int dupe=0, dupe2=0;
        for(Integer value:count.values()){
            //System.out.println("val 2:" + value);
            if(value>dupe){
                //System.out.println("set val 2:" + value);
                dupe=value;
            }
            else if(value==dupe){
                dupe2=value;
            }
        }
        //scores for kinds and pairs
        if(dupe==0 && dupe2==0){
            dupe2=-1;
        }

        if(dupe==4){//4 of a kind
            if(score<6){
                score=5;
            }   
        }
        else if(dupe==3){//3 of a kind
            if(score<4){
                score=3;
            }
        }
        else if(dupe==dupe2){//2 pairs
            if(score<4){
                score=2;
            }
        }
        else if(dupe==2){
            if(score<4){
                score=1;
            } 
        }       
        return score;
    }

    public int POneVSCup(String YorN, int userInput1, int userInput2, int userInput3){
        //player 1
        String[] playerFaceHand = new String[5];
        String[] playerSuitHand= new String[5];
        int[] playerFaceHandNum = new int[5];
        String[] playerFaceHand2 = new String[5];
        String[] playerSuitHand2= new String[5];
        int[] playerFaceHandNum2 = new int[5];
        int score=0;   
        //System.out.println("Hand of Player 1");    
        //this is to replace the cards in players hand
        int userI1=0,userI2=0, userI3=0;

        int sizeIncrease=5;
        int bestscore=0;

        //new hand
        if(YorN.equals("yes")){
            //check dupes
            if(userInput1==userInput2||userInput1==userInput3){
                userInput1=-1;
            }
            if(userInput3==userInput2){
                userInput3=-1;
            }
            //check if the number is valid
            //1st input 
            if(userInput1>=1&&userInput1<=5){
                sizeIncrease++;
                userI1=userInput1-1;
            }
            else{
                userI1=-1;
            }
            //2nd input
            if(userInput2>=1&&userInput2<=5){
                sizeIncrease++;
                userI2=userInput2-1;
            }
            else{
                userI2=-1;
            }
            //3rd input
            if(userInput2>=1&&userInput2<=5){
                sizeIncrease++;
                userI3=userInput2-1;
            }
            else{
                userI3=-1;
            }
            
            //System.out.println(sizeIncrease);
            //default hand and new hand set up
            for(int countHand =0; countHand < 5;countHand++){
                //face
                playerFaceHand[countHand]= deck[countHand].getFace();
                playerFaceHand2[countHand]= deck[countHand].getFace();
                //suit
                playerSuitHand[countHand] = deck[countHand].getSuit();
                playerSuitHand2[countHand] = deck[countHand].getSuit();

                //change the string to int
                if(playerFaceHand[countHand]=="Ace"){
                    playerFaceHandNum[countHand]=1;
                }
                else if(playerFaceHand[countHand]=="Deuce"){
                    playerFaceHandNum[countHand]=2;
                }
                else if(playerFaceHand[countHand]=="Three"){
                    playerFaceHandNum[countHand]=3;
                }
                else if(playerFaceHand[countHand]=="Four"){
                    playerFaceHandNum[countHand]=4;
                }
                else if(playerFaceHand[countHand]=="Five"){
                    playerFaceHandNum[countHand]=5;
                }
                else if(playerFaceHand[countHand]=="Six"){
                    playerFaceHandNum[countHand]=6;
                }
                else if(playerFaceHand[countHand]=="Seven"){
                    playerFaceHandNum[countHand]=7;
                }
                else if(playerFaceHand[countHand]=="Eight"){
                    playerFaceHandNum[countHand]=8;
                }
                else if(playerFaceHand[countHand]=="Nine"){
                    playerFaceHandNum[countHand]=9;
                }
                else if(playerFaceHand[countHand]=="Ten"){
                    playerFaceHandNum[countHand]=10;
                }
                else if(playerFaceHand[countHand]=="Jack"){
                    playerFaceHandNum[countHand]=11;
                }
                else if(playerFaceHand[countHand]=="Queen"){
                    playerFaceHandNum[countHand]=12;
                }
                else if(playerFaceHand[countHand]=="King"){
                    playerFaceHandNum[countHand]=13;
                }
            }
            
            //swap cards
            int countn=6;
            //System.out.println("fnum" + userI1 + "snum" + userI2 + "tnum" + userI3);
            if(sizeIncrease>5){
                if(userI1!=-1){
                    playerFaceHand2[userI1]= deck[countn].getFace();
                    playerSuitHand2[userI1] = deck[countn].getSuit();
                    countn++;
                }
                if(userI2!=-1){
                    playerFaceHand2[userI2]= deck[countn].getFace();
                    playerSuitHand2[userI2] = deck[countn].getSuit();
                    countn++;
                }
                if(userI3!=-1){
                    playerFaceHand2[userI3]= deck[countn].getFace();
                    playerSuitHand2[userI3] = deck[countn].getSuit();
                }
            }
    
            //define the new hand
            for(int countHand =0; countHand < 5;countHand++){
                //System.out.println(playerFaceHand2[countHand] + " of " + playerSuitHand2[countHand]);
                if(playerFaceHand2[countHand]=="Ace"){
                    playerFaceHandNum2[countHand]=1;
                }
                else if(playerFaceHand2[countHand]=="Deuce"){
                    playerFaceHandNum2[countHand]=2;
                }
                else if(playerFaceHand2[countHand]=="Three"){
                    playerFaceHandNum2[countHand]=3;
                }
                else if(playerFaceHand2[countHand]=="Four"){
                    playerFaceHandNum2[countHand]=4;
                }
                else if(playerFaceHand2[countHand]=="Five"){
                    playerFaceHandNum2[countHand]=5;
                }
                else if(playerFaceHand2[countHand]=="Six"){
                    playerFaceHandNum2[countHand]=6;
                }
                else if(playerFaceHand2[countHand]=="Seven"){
                    playerFaceHandNum2[countHand]=7;
                }
                else if(playerFaceHand2[countHand]=="Eight"){
                    playerFaceHandNum2[countHand]=8;
                }
                else if(playerFaceHand2[countHand]=="Nine"){
                    playerFaceHandNum2[countHand]=9;
                }
                else if(playerFaceHand2[countHand]=="Ten"){
                    playerFaceHandNum2[countHand]=10;
                }
                else if(playerFaceHand2[countHand]=="Jack"){
                    playerFaceHandNum2[countHand]=11;
                }
                else if(playerFaceHand2[countHand]=="Queen"){
                    playerFaceHandNum2[countHand]=12;
                }
                else if(playerFaceHand2[countHand]=="King"){
                    playerFaceHandNum2[countHand]=13;
                }
            }//for loop 
            //sort to find the flushes
            Arrays.sort(playerFaceHandNum);
            Arrays.sort(playerFaceHandNum2);
            //check if they are by each other
            int num=0;
            //old
            for(int i =0; i < 4;i++){
                if(playerFaceHandNum[i+1]==10&&playerFaceHandNum[i]==1&&playerFaceHandNum[4]==13){//edge case for ace
                    num++;
                }
                else if(playerFaceHandNum[i+1]-playerFaceHandNum[i]==1){
                    num++;
                }
                else{
                    break;
                }
            }
            //new
            for(int i =0; i < 4;i++){
                if(playerFaceHandNum2[i+1]==10&&playerFaceHandNum2[i]==1&&playerFaceHandNum2[4]==13){//edge case for ace
                    num++;
                }
                else if(playerFaceHandNum2[i+1]-playerFaceHandNum2[i]==1){
                    num++;
                }
                else{
                    break;
                }
            }
            //check if they are a straight flush or flush
            //old
            if(num==5){
                for(int i =0; i < 4;i++){
                    if(playerSuitHand[i+1]==playerSuitHand[i]){
                        score=6;
                    }
                    else{
                        score=4;
                        break;
                    }
                }
            }
            //new
            int score2=0;
            if(num==5){
                for(int i =0; i < 4;i++){
                    if(playerSuitHand2[i+1]==playerSuitHand2[i]){
                        score2=6;
                    }
                    else{
                        score2=4;
                        break;
                    }
                }
            }
            //checking the dupe numbers for kinds and pairs
            Map<Integer, Integer> count = new HashMap<Integer, Integer>();
            Map<Integer, Integer> count2 = new HashMap<Integer, Integer>();
            //old
            for(int i =0; i < 4;i++){
                if(playerFaceHandNum[i]==playerFaceHandNum[i+1]){
                    num++;
                    count.put(playerFaceHandNum[i],num);
                }
                else{
                    num=1;
                }
            }

            //new
            for(int i =0; i < 4;i++){
                if(playerFaceHandNum2[i]==playerFaceHandNum2[i+1]){
                    num++;
                    count.put(playerFaceHandNum2[i],num);
                }
                else{
                    num=1;
                }
            }

            //grabbing the highest dupe
            //old
            int dupe=0, dupe2=0;
            for(Integer value:count.values()){
                //System.out.println("val 1:" + value);
                if(value>dupe){
                    dupe=value;
                    //System.out.println("set dupe val 1:" + value);
                }
                else if(value==dupe){
                    dupe2=value;
                }
            }

            //new
            int dupe3=0, dupe4=0;
            for(Integer value:count.values()){
                //System.out.println("val 1:" + value);
                if(value>dupe3){
                    dupe3=value;
                    //System.out.println("set dupe val 1:" + value);
                }
                else if(value==dupe3){
                    dupe4=value;
                }
            }
            //scores for kinds and pairs
            //System.out.println("player 1" + dupe);
            if(dupe==0&&dupe2==0){
                dupe2=-1;
            }
            if(dupe==4){//4 of a kind
                if(score<6){
                    score=5;
                }  
            }
            else if(dupe==3){//3 of a kind
                if(score<4){
                    score=3;
                }
            }
            else if(dupe==dupe2){//2 pairs
                if(score<4){
                    score=2;
                }
            }
            else if(dupe==2){
                if(score<4){
                    score=1;
                } 
            }
            //new
            if(dupe3==0&&dupe4==0){
                dupe4=-1;
            }
            if(dupe3==4){//4 of a kind
                if(score2<6){
                    score2=5;
                }  
            }
            else if(dupe3==3){//3 of a kind
                if(score2<4){
                    score2=3;
                }
            }
            else if(dupe3==dupe4){//2 pairs
                if(score2<4){
                    score2=2;
                }
            }
            else if(dupe3==2){
                if(score2<4){
                    score2=1;
                } 
            }
            
            if(score>score2){
                bestscore=1;
            }
            else{
                score=score2;
                bestscore=2;
            }
            //System.out.println("player 1 score" + score);
        }//yes
        else{
            for(int countHand =0; countHand < 5;countHand++){
                playerFaceHand[countHand]= deck[countHand].getFace();
                //suit
                playerSuitHand[countHand] = deck[countHand].getSuit();
                
                System.out.println(playerFaceHand[countHand] + " of " + playerSuitHand[countHand]);
                if(playerFaceHand[countHand]=="Ace"){
                    playerFaceHandNum[countHand]=1;
                }
                else if(playerFaceHand[countHand]=="Deuce"){
                    playerFaceHandNum[countHand]=2;
                }
                else if(playerFaceHand[countHand]=="Three"){
                    playerFaceHandNum[countHand]=3;
                }
                else if(playerFaceHand[countHand]=="Four"){
                    playerFaceHandNum[countHand]=4;
                }
                else if(playerFaceHand[countHand]=="Five"){
                    playerFaceHandNum[countHand]=5;
                }
                else if(playerFaceHand[countHand]=="Six"){
                    playerFaceHandNum[countHand]=6;
                }
                else if(playerFaceHand[countHand]=="Seven"){
                    playerFaceHandNum[countHand]=7;
                }
                else if(playerFaceHand[countHand]=="Eight"){
                    playerFaceHandNum[countHand]=8;
                }
                else if(playerFaceHand[countHand]=="Nine"){
                    playerFaceHandNum[countHand]=9;
                }
                else if(playerFaceHand[countHand]=="Ten"){
                    playerFaceHandNum[countHand]=10;
                }
                else if(playerFaceHand[countHand]=="Jack"){
                    playerFaceHandNum[countHand]=11;
                }
                else if(playerFaceHand[countHand]=="Queen"){
                    playerFaceHandNum[countHand]=12;
                }
                else if(playerFaceHand[countHand]=="King"){
                    playerFaceHandNum[countHand]=13;
                }
            }
            //sort to find the flushes
            Arrays.sort(playerFaceHandNum);
            //check if they are by each other
            int num=0;
            for(int i =0; i < 4;i++){
                if(playerFaceHandNum[i+1]==10&&playerFaceHandNum[i]==1&&playerFaceHandNum[4]==13){//edge case for ace
                    num++;
                }
                else if(playerFaceHandNum[i+1]-playerFaceHandNum[i]==1){
                    num++;
                }
                else{
                    break;
                }
            }
            //check if they are a straight flush or flush
            if(num==5){
                for(int i =0; i < 4;i++){
                    if(playerSuitHand[i+1]==playerSuitHand[i]){
                        score=6;
                    }
                    else{
                        score=4;
                        break;
                    }
                }
            }
            
            //checking the dupe numbers for kinds and pairs
            Map<Integer, Integer> count = new HashMap<Integer, Integer>();
            for(int i =0; i < 4;i++){
                if(playerFaceHandNum[i]==playerFaceHandNum[i+1]){
                    num++;
                    count.put(playerFaceHandNum[i],num);
                }
                else{
                    num=1;
                }
            }

            //grabbing the highest dupe
            int dupe=0, dupe2=0;
            for(Integer value:count.values()){
                //System.out.println("val 1:" + value);
                if(value>dupe){
                    dupe=value;
                    //System.out.println("set dupe val 1:" + value);
                }
                else if(value==dupe){
                    dupe2=value;
                }
            }
            //scores for kinds and pairs
            //System.out.println("player 1" + dupe);
            if(dupe==0&&dupe2==0){
                dupe2=-1;
            }
            if(dupe==4){//4 of a kind
                if(score<6){
                    score=5;
                }  
            }
            else if(dupe==3){//3 of a kind
                if(score<4){
                    score=3;
                }
            }
            else if(dupe==dupe2){//2 pairs
                if(score<4){
                    score=2;
                }
            }
            else if(dupe==2){
                if(score<4){
                    score=1;
                } 
            }
            bestscore=1;
            //System.out.println("player 1 score" + score);
        }//end of old

        //cup
        String[] playerFaceHandC = new String[5];
        String[] playerSuitHandC= new String[5];
        int[] playerFaceHandNumC = new int[5];
        int scoreC=0;       
        //System.out.println("Hand of PLayer 1");
        for(int countHand =0; countHand < 5;countHand++){
            //face
            playerFaceHandC[countHand]= deck[sizeIncrease+5].getFace();
            //suit
            playerSuitHandC[countHand] = deck[countHand+5].getSuit();
            //System.out.println(playerFaceHand[countHand] + " of " + playerSuitHand[countHand]);
            //change the string to int
            if(playerFaceHandC[countHand]=="Ace"){
                playerFaceHandNumC[countHand]=1;
            }
            else if(playerFaceHandC[countHand]=="Deuce"){
                playerFaceHandNumC[countHand]=2;
            }
            else if(playerFaceHandC[countHand]=="Three"){
                playerFaceHandNumC[countHand]=3;
            }
            else if(playerFaceHandC[countHand]=="Four"){
                playerFaceHandNumC[countHand]=4;
            }
            else if(playerFaceHandC[countHand]=="Five"){
                playerFaceHandNumC[countHand]=5;
            }
            else if(playerFaceHandC[countHand]=="Six"){
                playerFaceHandNumC[countHand]=6;
            }
            else if(playerFaceHandC[countHand]=="Seven"){
                playerFaceHandNumC[countHand]=7;
            }
            else if(playerFaceHandC[countHand]=="Eight"){
                playerFaceHandNumC[countHand]=8;
            }
            else if(playerFaceHandC[countHand]=="Nine"){
                playerFaceHandNumC[countHand]=9;
            }
            else if(playerFaceHandC[countHand]=="Ten"){
                playerFaceHandNumC[countHand]=10;
            }
            else if(playerFaceHandC[countHand]=="Jack"){
                playerFaceHandNumC[countHand]=11;
            }
            else if(playerFaceHandC[countHand]=="Queen"){
                playerFaceHandNumC[countHand]=12;
            }
            else if(playerFaceHandC[countHand]=="King"){
                playerFaceHandNumC[countHand]=13;
            }
        }

        //sort to find the flushes
        Arrays.sort(playerFaceHandNumC);
        //check if they are by each other
        int num=0;
        for(int i =0; i < 4;i++){
            if(playerFaceHandNumC[i+1]==10&&playerFaceHandNumC[i]==1&&playerFaceHandNumC[4]==13){//edge case for ace
                num++;
            }
            else if(playerFaceHandNumC[i+1]-playerFaceHandNumC[i]==1){
                num++;
            }
            else{
                break;
            }
        }
        //check if they are a straight flush or flush
        if(num==5){
            for(int i =0; i < 4;i++){
                if(playerSuitHandC[i+1]==playerSuitHandC[i]){
                    scoreC=6;
                }
                else{
                    scoreC=4;
                    break;
                }
            }
        }
        
        //checking the dupe numbers for kinds and pairs
        Map<Integer, Integer> countC = new HashMap<Integer, Integer>();
        for(int i =0; i < 4;i++){
            if(playerFaceHandNumC[i]==playerFaceHandNumC[i+1]){
                num++;
                countC.put(playerFaceHandNumC[i],num);
            }
            else{
                num=1;
            }
        }

        //grabbing the highest dupe
        int dupeC=0, dupe2C=0;
        for(Integer value:countC.values()){
            //System.out.println("val 2:" + value);
            if(value>dupeC){
                dupeC=value;
               // System.out.println("set val 2:" + value);
            }
            else if(value==dupeC){
                dupe2C=value;
            }
        }
        //System.out.println("player 2" + dupe);
        //scores for kinds and pairs
        if(dupeC==0&&dupe2C==0){
            dupe2C=-1;
        }
        if(dupeC==4){//4 of a kind
            if(scoreC<6){
                scoreC=5;
            }  
        }
        else if(dupeC==3){//3 of a kind
            if(scoreC<4){
                scoreC=3;
            }
        }
        else if(dupeC==dupe2C){//2 pairs
            if(scoreC<4){
                scoreC=2;
            }
        }
        else if(dupeC==2){
            if(scoreC<4){
                scoreC=1;
            } 
        }
        //System.out.println("player 2 score" + score);
        if(scoreC>score){
            bestscore=3;
        }
        return bestscore;
    }

    public void FishShuffle(){
        currentCard=0;

        for(int first =deck.length-1; first > 0; first--){
            int second = randomNumbers.nextInt(first+1);
            card temp = deck[first];
            deck[first]=deck[second];
            deck[second]=temp;
        }
    }
}
