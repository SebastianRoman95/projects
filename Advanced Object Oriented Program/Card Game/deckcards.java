import java.util.*;
import java.security.SecureRandom;
public class deckcards {
    //variables
    private static final SecureRandom randomNumbers = new SecureRandom();
    private static final int NumberOfCards = 52;
    private cards[] deck = new cards[NumberOfCards];
    private int currentCard = 0;
    //private String playerFaceHand[];
    //private String playerSuitHand[];

    //deck
    public deckcards(){
        String[] faces = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
        String[] suits= {"Heart", "Diamond", "Club", "Spade"};

        //set the deck to be random
        for(int count =0; count < deck.length;count++){
            deck[count]= new cards(faces[count%13],suits[count%4]);
        }
    }

    //shuffle
    public void shuffle(){
        currentCard = 0;

        for(int first =0; first < deck.length; first++){
            int second = randomNumbers.nextInt(NumberOfCards);
            cards temp = deck[first];
            deck[first]=deck[second];
            deck[second]=temp;
        }
    }

    //deal
    public cards dealCard(){
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
}
