import java.util.*;

/**
 * 387. 字符串中的第一个唯一字符
 */
public class T387 {
    /**
    1. 循环字符串 s，统计字符串 s 中每个字符出现的次数。
    因为只包含小写字母，所以可以用一个长度为26的数组，代替HashMap保存结果。
    2. 再次循环字符串 s，判断字符在 freq 中出现频率。
    如果出现 1 次，算法结束，返回当前索引。
    否则循环结束，返回 -1；
     */
    public int firstUniqChar(String s) {
        int[] freq = new int[26];
        char[] chars = s.toCharArray();
        for (char c: chars) {
            freq[c - 'a']++;
        }

        for (int i = 0; i < chars.length; i++) {
            if (freq[chars[i] - 'a'] == 1) return i;
        }

        return -1;
    }
}
