import java.util.*;

/**
 * 005: 寻找两个正序数组的中位数
 */
public class T005 {
    /**
     1. 循环字符串 s
     2. 在循环中定义两个指针 start，end，
     start指向当前循环到的字符，end 指向字符串的尾部
     3. 令 end 不断往左移动，当遇到 end 的字符等于 start，
     start 往右移动，end 往左移动，同时记录移动的次数。
     4. 当 start 和 end 碰撞，且中间start的经过的字符等于end，说明找到一个回文。
     否则，说明这次回文查找失败。
     5. 继续循环字符串 s，直到循环结束。
     */
    public String longestPalindrome(String s) {
        int maxLen = 0;
        String result = "";

        var chars = s.toCharArray();
        for (int i = 0; i < chars.length; i++) {

            int start = i, end = chars.length-1;
            int point=-1; //标记回文结束点
            int retry = 0; //搜索次数
            while (start <= end) {
                if (chars[end] == chars[start]) {
                    point = point == -1 ? end+1:point;
                    end--;
                    start++;
                } else {
                    point = -1;
                    start = i;
                    retry++;
                    end = chars.length - 1 - retry;
                }
            }
            if (point != -1 && (point - i) > maxLen) {
                maxLen = point - i;
                result = s.substring(i, i+maxLen);
            }
        }

        return result;
    }

    public static void main(String[] args) {
        String[] testset = {
                "bacabab",
                "babad",
                "aba",
                "a",
                "aacdcd",
                " ",
        };

        var obj = new T005();
        for (String s: testset) {
            var result = obj.longestPalindrome(s);
            System.out.printf("s:%s, result:%s\n", s, result);
            System.out.println("==================");
        }
    }
}
