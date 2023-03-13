import java.util.*;

/**
 * 412. Fizz Buzz
 */
public class T412 {
    /**
    1. 定义一个数组，容量为 n - 1
    2. 循环 1 到 n 之间数字i，进行如下判断：
    如果 i % (3 * 5) == 0，数组中添加 "FizzBuzz",
    否则，如果 i % 3 == 0，数组中添加 "Fizz",
    否则，如果 i % 5 == 0，数组中添加 "Buzz",
    否则 数组中添加 i 的字符串形式。
     */
    public List<String> fizzBuzz(int n) {
        List<String> answer = new ArrayList<>(n - 1);

        for (int i = 1; i <= n; i++) {
            if (i % (3 * 5) == 0) {
                answer.add("FizzBuzz");
            } else if (i % 3 == 0) {
                answer.add("Fizz");
            } else if (i % 5 == 0) {
                answer.add("Buzz");
            } else {
                answer.add(String.format("%d", i));
            }
        }

        return answer;
    }
}
