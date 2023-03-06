import java.util.*;

/**
 * 20. 有效的括号
 */

public class T020 {

	/**
    1. 循环整个字符串，使用栈存放右半括号，
    当遇到匹配的左半括号时，对应的右半括号出栈。
    2. 当循环结束，如果栈为空，说明字符串有效，
    否则字符串无效。
    */
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();

        for (char c: s.toCharArray()) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else if (c == ')' && !stack.isEmpty() && stack.peek() == '(') {
                stack.pop();
            } else if (c == '}' && !stack.isEmpty() && stack.peek() == '{') {
                stack.pop();
            } else if (c == ']' && !stack.isEmpty() && stack.peek() == '[') {
                stack.pop();
            } else {
                return false;
            }
        }

        return stack.isEmpty();
    }

    public static void main(String[] args) {
    	String[] testset = {
    		"{}",
    		"{}[]()",
    		"{}[(]())",
    		"]",
    	};

    	var obj = new T020();
    	for (int i = 0; i < testset.length; i++) {
    		var s = testset[i];

    		var result = obj.isValid(s);
    		System.out.printf("S:%s, Result:%b\n", s, result);
    		System.out.println("=====================");
    	}
    }
}
