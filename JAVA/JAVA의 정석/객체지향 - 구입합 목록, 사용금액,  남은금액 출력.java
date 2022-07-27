class EX {
    public static void main(String args[]) {
        Buyer b = new Buyer();
        b.buy(new Tv());
        b.buy(new Computer());
        b.buy(new Tv());
        b.buy(new Audio());
        b.buy(new Computer());
        b.buy(new Computer());
        b.buy(new Computer());
        b.summary();
    }
}
class Buyer {
    int money = 1000;
    Product[] cart = new Product[3]; // 구입한 제품을 저장하기 위한 배열
    int i = 0; // Product cart index 배열 에 사용될
    void buy(Product p) {
        if(money<p.price) {
            System.out.println("잔액이 부족하여 "+p+"을/를 살 수 없습니다.");
            return;
        }
        money-=p.price;
        add(p);
    }
    void add(Product p) {
        if(i>=cart.length) {
            Product[] cart2 = new Product[cart.length * 2];
            System.arraycopy(cart,0,cart2,0, cart.length);
            cart = cart2;
        }
        cart[i++] = p;

    } // add(Product p)
    void summary() {
        System.out.print("구입한 물건:");
        for(int i=0; i< cart.length; i++) {
            System.out.print(cart[i]+",");
        }
        System.out.println();
        System.out.print("사용한 금액:");
        System.out.println(1000-money);
        System.out.print("남은 금액:");
        System.out.println(money);
    } // summary()
}
class Product {
    int price; // 제품의 가격
    Product(int price) {
        this.price = price;
    }
}
class Tv extends Product {
    Tv() { super(100); }
    public String toString() { return "Tv"; }
}
class Computer extends Product {
    Computer() { super(200); }
    public String toString() { return "Computer";}
}
class Audio extends Product {
    Audio() { super(50); }
    public String toString() { return "Audio"; }
}
