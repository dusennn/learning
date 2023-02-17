import java.util.*;

/**
 * 014: 字符串中的变位词
 */

public class O014 {

	/**
	 * 1.把 s1 转成一个hash表，因为只包含26个字母，所以用长度为26的数组可以模拟哈希表
	 * 2.从下标 0 遍历 s2 ，每次取 s2 的子串（下标i 到 i+s1.length）
	 * 3.比对子串是否与 s1 匹配，若匹配返回 true，否则i往右移动
	 */
	public boolean algorithm(String s1, String s2) {
		var s1CharMap = this.charMap(s1);

		int i = 0;
		var s1Len = s1.length();
		var s2Len = s2.length();
		while (i <= s2Len - s1Len) {
			var subStr = s2.substring(i, i+s1Len);
			var charMap = this.charMap(subStr);

			if (this.equalsCharMap(s1CharMap, charMap)) {
				return true;
			} else {
				i++;
			}
		}

		return false;
	}

	private int[] charMap(String str) {
		int[] map = new int[26];
		for (int i = 0; i < str.length(); i++) {
			map[str.charAt(i) - 'a']++;
		}
		return map;
	}

	private boolean equalsCharMap(int[] arr1, int[] arr2) {
		boolean isEqual = true;
		for (int i = 0; i < arr1.length; i++) {
			if (arr1[i] != arr2[i]) isEqual = false;
		}
		return isEqual;
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
			"fabaf",
			"ooolleoooleh"
		};
		String[] targets = {
			"ab",
			"ab",
			"ca",
			"c",
			"ab",
			"fb",
			"hello"
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
