import java.util.*;

/**
 * 019: 最多删除一个字符得到回文
 */

public class O019 {

	/**
	 * 1. 利用双指针求字符串是不是回文
	 * 2. p1 p2 分别指向字符串的开头和结尾，依次比对相应的值是否一致，
	 * 每次比对成功，p1 往右移动，p2 往左移动。当 p1 与 p2 相遇，说明字符串是回文。
	 * 3. 当出现比对失败，记录出错的位置，先尝试 p1 右移，失败后 p1 回到失败的位置。
	 * 继续尝试 p2 左移，若还是失败，说明字符串删除一个字符不能得到回文。
	 * 4. 如果两次尝试有一次成功，记录已经删除过一个字符串，并继续移动比对。下次再遇到比对失败，就直接失败了。
	 */
	public boolean algorithm(String str) {
		boolean result = true;

		int p1 = 0;
		int p2 = str.length() - 1;
		while (p1 <= p2) {
			if (str.charAt(p1) == str.charAt(p2)) {
				p1++;
				p2--;
			} else {
				result = false;
				break;
			}
		}

		// 如果失败，尝试删除一个字符
		if (!result) {
			// 先尝试删右边的字符
			result = this.core(str, p1+1, p2);
			// 再尝试删左边的字符
			if (!result) {
				result = this.core(str, p1, p2-1);
			}
		}
		return result;
	}

	public boolean core(String str, int start, int end) {
		boolean result = true;

		while (start <= end) {
			if (str.charAt(start) == str.charAt(end)) {
				start++;
				end--;
			} else {
				result = false;
				break;
			}
		}

		return result;
	}

	public static void main(String[] args) {
		String[] testset = {
			// "aaabb",
			// "aba",
			// "abaa",
			// "abba",
			// "a",
			"aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga",
		};

		var obj = new O019();
		for (String str: testset) {
			var result = obj.algorithm(str);
			System.out.printf("Str:%s, Result:%s\n", str, result);
			System.out.println("==========================");
		}
	}
}
