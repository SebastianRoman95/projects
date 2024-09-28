public class cards {
    private final String face;
    private final String suit;

    public cards(String cardFace, String Cardsuit){
        this.face=cardFace;
        this.suit=Cardsuit;
    }

    //get and set?
    public String getFace(){
        return face;
    }
    public String getSuit(){
        return suit;
    }

    public String toString(){
        return face + " of " + suit;
    }
}
