class SutdaDeck {
    final int CARD_NUM = 20;
    SutdaCard[] cards = new SutdaCard[CARD_NUM];
    SutdaDeck() {
        for(int i=0; i<CARD_NUM; i++) {
            int inx = i%10+1;
            if(inx==1 || inx==3 || inx==8)
                cards[i] = new SutdaCard(inx,true);
            else
                cards[i] = new SutdaCard(inx,false);
        }
    }
    void shuffle() {
        int inx= (int)(CARD_NUM * Math.random());
        for(int i=0; i<CARD_NUM; i++) {
            SutdaCard tmp = cards[i];
            cards[i] = cards[inx];
            cards[inx] = tmp;
        }
    }
    SutdaCard pick(int index) {
        if(index<0 || index>=CARD_NUM)
            return null;
        return cards[index];
    }
    SutdaCard pick() {
        int inx= (int)(CARD_NUM * Math.random());
        return pick(inx);
    }
}
class SutdaCard {
    int num;
    boolean isKwang;
    SutdaCard() {
        this(1, true);
    }
    SutdaCard(int num, boolean isKwang) {
        this.num = num;
        this.isKwang = isKwang;
    }
    public String toString() {
        return num + ( isKwang ? "K":"");
    }
}
class EX {
    public static void main(String args[]) {
        SutdaDeck deck = new SutdaDeck();
        System.out.println(deck.pick(0));
        System.out.println(deck.pick());
        deck.shuffle();
        for(int i=0; i < deck.cards.length;i++)
            System.out.print(deck.cards[i]+",");
        System.out.println();
        System.out.println(deck.pick(0));
    }
}
