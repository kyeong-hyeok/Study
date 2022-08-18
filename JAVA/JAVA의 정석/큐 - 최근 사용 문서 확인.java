import java.util.*;

public class EX {
    static Queue q = new LinkedList();
    static final int MAX_SIZE = 5;
    public static void main(String[] args) {
        System.out.println("help를 입력하면 도움말을 볼 수 있습니다.");
        while(true) {
            System.out.print(">>");
            try {
                Scanner s = new Scanner(System.in);
                String input = s.nextLine().trim();
                if ("".equals(input)) continue;
                if (input.equalsIgnoreCase("q"))
                    System.exit(0);
                else if (input.equalsIgnoreCase("help")) {
                    System.out.println("help - 도움말");
                    System.out.println("q - 프로그램 종료");
                    System.out.println("history - 최근 입력 명령어를" + MAX_SIZE + "개 보여줍니다.");
                } else if (input.equalsIgnoreCase("history")) {
                    save(input);
                    LinkedList list = (LinkedList) q;
                    for (int i = 0; i < list.size(); i++)
                        System.out.println((i + 1) + "." + list.get(i));
                } else {
                    save(input);
                    System.out.println(input);
                }
            } catch(Exception e) {
                System.out.println("입력오류");
            }
        }
    }
    public static void save(String input) {
        if(!"".equals(input))
            q.offer(input);
        if(q.size()>MAX_SIZE)
            q.poll();
    }
}
