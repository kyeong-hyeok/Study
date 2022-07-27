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
        if(p instanceof Tv) {
            Tv t = new Tv();
            if(money<t.price) {
                System.out.println("잔액이 부족하여 "+t+"을/를 살 수 없습니다.");
                return;
            }
            money-=t.price;
            add(t);
        }
        if(p instanceof Computer) {
            Computer c = new Computer();
            if(money<c.price) {
                System.out.println("잔액이 부족하여 "+c+"을/를 살 수 없습니다.");
                return;
            }
            money-=c.price;
            add(c);
        }
        if(p instanceof Audio) {
            Audio a = new Audio();
            if(money<a.price) {
                System.out.println("잔액이 부족하여 "+a+"을/를 살 수 없습니다.");
                return;
            }
            money-=a.price;
            add(a);
        }
    }
    void add(Product p) {
        if(i>=cart.length) {
            Product[] cart2 = new Product[cart.length * 2];
            for(int i=0; i< cart.length; i++)
                cart2[i] = cart[i];
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
