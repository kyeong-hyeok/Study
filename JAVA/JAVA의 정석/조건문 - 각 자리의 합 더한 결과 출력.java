import java.util.*;

public class EX {
    public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    String input = scanner.nextLine();
    int num = Integer.parseInt(input);
    int sum=0;
    while(num!=0) {
        sum += num%10;
        num/=10;
    }
    System.out.println(sum);
    }
}
