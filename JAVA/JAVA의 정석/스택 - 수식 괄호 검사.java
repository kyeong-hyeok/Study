import java.util.*;

public class EX {
    public static void main(String[] args)
    {
        Stack st = new Stack();
        String expression = "((3+5*8-2))";
        try {
            for(int i=0; i<expression.length(); i++) {
                char ch = expression.charAt(i);
                if(ch=='(')
                    st.push(ch);
                else if (ch==')')
                    st.pop();
            }
            if (st.isEmpty())
                System.out.println("괄호가 일치합니다.");
            else
                System.out.println("괄호가 일치하지 않습니다.");
        }
        catch (EmptyStackException e) {
            System.out.println("괄호가 일치하지 않습니다.");
        }
    }
}
