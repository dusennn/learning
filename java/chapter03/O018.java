import java.util.*;

/**
 * 018: 有效的回文
 */

public class O018 {
	
	/**
	 * 0. 字符串转为小写
	 * 1. 定义两个指针 p1 p2
	 * 2. p1 指向字符串开头, p2 指向字符串结尾
	 * 3. p1 从开头不断往右移动，p2 从结尾不断往左移动
	 * 4. 每移动一次，判断当前位置的元素是否一致（忽略大小写、忽略空格）
	 * 5. 如果一致，继续移动，如果不一致，直接返回 false
	 * 6. p1 == p2 程序结束，返回 true
	 */
	public boolean algorithm(String str) {
		boolean result = true;

		str = str.toLowerCase();

		int p1 = 0;
		int p2 = str.length() - 1;
		while (p1 <= p2) {
			var c1 = str.charAt(p1);
			var c2 = str.charAt(p2);

			if (!this.isSpacelChar(c1)) {
				p1++;
				continue;
			}
			if (!this.isSpacelChar(c2)) {
				p2--;
				continue;
			}

			if (c1 == c2) {
				p1++;
				p2--;
			} else {
				result = false;
				break;
			}
		}

		return result;
	}

	// 判断只是字母或数字
	private boolean isSpacelChar(char c) {
		return ('a' <= c && c <= 'z') || ('0' <= c && c <= '9') ? true: false;
	}

	public static void main(String[] args) {
		String[] testset = {
			"abccccccab",
			"abccba",
			"A man, a plan, a canal: Panama",
			"race a car"
		};

		var obj = new O018();
		for (int i = 0; i < testset.length; i++) {
			var str = testset[i];
			var result = obj.algorithm(str);
			System.out.printf("Str:%s, Result:%s\n", str, result);
			System.out.println("=====================");
		}
	}
}
