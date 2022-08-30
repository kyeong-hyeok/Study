abstract class Shape {
    Point p;
    Shape() {
        this(new Point(0,0));
    }
    Shape(Point p) {
        this.p = p;
    }
    abstract double calcArea(); // 도형의 면적을 계산해서 반환하는 메서드
    Point getPosition() {
        return p;
    }
    void setPosition(Point p) {
        this.p = p;
    }
}
class Circle extends Shape {
    double r;
    Circle(double r) {
        super();
        this.r=r;
    }
    double calcArea() {
        return r*r*Math.PI;
    }
}
class Rectangle extends Shape {
    double width, height;
    Rectangle(double w, double h) {
        super();
        width = w;
        height = h;
    }
    boolean isSquare() {
        return (width*height!=0 && width==height);
    }
    double calcArea() {
        return width*height;
    }
}
class Point {
    int x;
    int y;
    Point() {
        this(0,0);
    }
    Point(int x, int y) {
        this.x=x;
        this.y=y;
    }
    public String toString() {
        return "["+x+","+y+"]";
    }
}
