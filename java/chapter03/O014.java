import java.util.*;

/**
 * 014: 字符串中的变位词
 */

public class O014 {

	/**
	 * 1.使用双指针，p1 和 p2 同时指向 s1 字符串的开头
	 * 2.如果 p1 的值等于 s1 最后一个元素的值，p2 从 p1 的位置不断往右移动。
	 * 	判断是否能和 s1 完全匹配，若不匹配，p1 右移，寻找下一个子串
	 * 3.如果 p1 的值不等于 s1 最后一个元素的值，p1 往右移动
	 * 4.p1移动到 s2 尾部，循环结束
	 */
	public boolean algorithm(String s1, String s2) {
		int p1 = 0;
		int p2 = p1;
		var s1Len = s1.length();
		var s2Len = s2.length();
		while (p1 <= p2 && p2 < s2Len) {

			var char1 = s2.charAt(p2);
			var char2 = s1.charAt(s1Len-1-(p2-p1));
			if (char1 == char2) {
				p2++;
				if (s1Len-1-(p2-p1) < 0)
					return true; //子串完全匹配
			} else {
				p1++;
				p2=p1;
			}
		}

		return false;
	}

	/**
	 * 字符串翻转的算法（暂未使用）
	 */
	private String reverse(String str) {
		String[] strs = str.split("");
		int start = 0;
		int end = strs.length - 1;
		while (start <= end) {
			var tmp = strs[start];
			strs[start] = strs[end];
			strs[end] = tmp;

			start++;
			end--;
		}
		return String.join("", strs);
	}

	public static void main(String[] args) {
		String[] testset = {
			"eidbaooo",
			"abc",
			"ac",
			"ac",
			"ab",
		};
		String[] targets = {
			"ab",
			"ab",
			"ca",
			"c",
			"ab",
		};

		var obj = new O014();
		for (int i = 0; i < testset.length; i++) {
			var s1 = targets[i];
			var s2 = testset[i];
			var result = obj.algorithm(s1, s2);
			System.out.printf("S1:%s, S2:%s, Result:%b\n", s1, s2, result);
			System.out.println("====================");
		}
	}
}
