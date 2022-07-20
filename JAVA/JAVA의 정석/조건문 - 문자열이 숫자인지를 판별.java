import java.util.*;
public class EX {
    public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    String input = scanner.nextLine();
    boolean isNumber = true;
    for(int i=0; i<input.length(); i++) {
        if(input.charAt(i)<'0' || input.charAt(i)>'9') {
            isNumber = false;
            break;
        }
    }
    System.out.println(isNumber);
    }
}
