import java.util.*;

/**
 * 015: 字符串中的所有变位词
 */
public class O015 {

	/**
	 * 1.把 s1 字符串映射到 hashmap，因为只包含小写字母，所有用26长度int数组可以代替
	 * 2.从下标0开始循环遍历 s2 字符串，每次取一个子串（ [i, i+s1.length) ）
	 * 3.把这个子串映射成 hashmap，然后和 s1 的 hashtable 进行比较。
	 * 如果一致，记录下标 i 到结果集，然后 i 右移动。否则，只 i 右移.
	 * 4. i >= s2.lenght - s1.length 算法结束，返回结果集
	 */
	public List<Integer> algorithm(String s1, String s2) {
		List<Integer> result = new ArrayList<>();

		var s1Hashmap = this.toHashmap(s1);

		var s1Len = s1.length();
		var s2Len = s2.length();
		for (int i = 0; i <= s2Len - s1Len; i++) {
			var subStr = s2.substring(i, i+s1Len);
			var subHashmap = this.toHashmap(subStr);
			if (this.equalsHashmap(s1Hashmap, subHashmap)) {
				result.add(i);
			}
		}

		return result;
	}

	private int[] toHashmap(String str) {
		int[] hashmap = new int[26];
		for (int i = 0; i < str.length(); i++) {
			hashmap[str.charAt(i) - 'a']++;
		}
		return hashmap;
	}

	private boolean equalsHashmap(int[] arr1, int[] arr2) {
		boolean isEqual = true;
		for (int i = 0; i < arr1.length; i++) {
			if (arr1[i] != arr2[i]) isEqual = false;
		}
		return isEqual;
	}

	public static void main(String[] args) {
		String[] testset = {
			"abccccccab",
			"abccba"
		};
		String[] targets = {
			"ab",
			"ab"
		};

		var obj = new O015();
		for (int i = 0; i < testset.length; i++) {
			var s1 = targets[i];
			var s2 = testset[i];
			var result = obj.algorithm(s1, s2);
			System.out.printf("S1:%s, S2:%s, Result:%s\n", s1, s2, result);
			System.out.println("=====================");
		}
	}
}
