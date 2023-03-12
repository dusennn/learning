import java.util.*;

/**
 * Top Offer 003: 无重复字符的最长子串
 */
public class T003 {

	/**
    0. 字符串长度小于等于，直接返回字符串长度。
    1. 定义两个指针 start，end，指向字符串的开始。
    2. 定义一个集合 set 用于保存start，end之间的字符，用于判断是否重复出现。
    3. 定义一个变量 maxLen 用于保存最长字符串的长度。
    4. 循环字符串，end 往右移动，判断遇到的字符串是否在集合中。如果不在加入集合；
    如果在，把集合长度与 maxLen 比较，取最大值赋给 maxLen。
    然后 start 往右移动，start 赋值给end，清空集合，继续循环字符串。
    5. 字符串循环结束，把 maxLen 返回，算法结束。
     */
    public int lengthOfLongestSubstring(String s) {
        if (s.length() <= 1) return s.length();

        var chars = s.toCharArray();
        int start = 0, end = 0, maxLen = 0;
        Set<Character> set = new HashSet<>();

        while (start <= end && end < chars.length) {
            var c = chars[end];
            if (set.contains(c)) {
                maxLen = maxLen > set.size() ? maxLen: set.size();
                start++;
                end = start;
                set = new HashSet<>();
            } else {
                set.add(c);
                end++;
            }
        }

        return maxLen > set.size() ? maxLen: set.size();
    }

    public static void main(String[] args) {
    	String[] testset = {
    		"abcabcbb",
    		"ab",
    		"",
    		" ",
    	};

    	var obj = new T003();
    	for (String s: testset) {
    		var result = obj.lengthOfLongestSubstring(s);
    		System.out.printf("s:%s, result:%s\n", s, result);
    		System.out.println("==================");
    	}
    }
}
