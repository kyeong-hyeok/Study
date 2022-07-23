public class EX {
    public static void main(String[] args) {
        Student s = new Student("민경혁",1,1,100,60,76);
        System.out.println(s.info());
    }
}

class Student {
    String name;
    int ban, no, kor, eng, math;
    Student(String name,int ban, int no, int kor, int eng, int math) {
        this.name=name;
        this.ban=ban;
        this.no=no;
        this.kor=kor;
        this.eng=eng;
        this.math=math;
    }
    String info() {
        String[] arr = {name,ban+"",no+"",kor+"",eng+"",math+"",getTotal()+"", getAverage()+""};
        String a=arr[0];
        for(int i=1; i<8; i++) {
            a+=','+arr[i];
        }
        return a;
    }
    int getTotal() {
        return kor+eng+math;
    }
    float getAverage() {
        return (int)(getTotal()/3f*10f+0.5f)/10f;
    }
}
