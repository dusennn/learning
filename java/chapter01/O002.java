import java.util.*;
/**
 * 剑指Offer：002.二进制加法
*/

public class O002 {

	public String addBinary(String a, String b) {
		var al = a.length();
		var bl = b.length();
		// 1.a b 其中一个为空，则返回另一个
		if(al <= 0) return b;
		if(bl <= 0) return a;

		// 2. a b 为 0，直接返回
		if("0".equals(a) && "0".equals(b)) return "0";

		// 3.按照最短的二进制串循环
		if(al < bl){
			return this.add(a, b);
		} else {
			return this.add(b, a);
		}
	}

	private String add(String minStr, String maxStr) {
		var minStrReversed = this.reverse(minStr);
		var maxStrReversed = this.reverse(maxStr);

		int []strs = new int[minStr.length() + maxStr.length()];
		for(int i=0; i<maxStrReversed.length(); i++) {
			int t1 = 0;
			if (i < minStrReversed.length()) {
				t1 = minStrReversed.charAt(i) - '0';
			}
			int t2 = maxStrReversed.charAt(i) - '0';

			// 相加大于2，进位运算
			strs[i] = t1 + t2 + strs[i];
			int j = i;
			while(strs[j] >= 2) {
				strs[j] = strs[j] - 2;
				strs[j+1] = strs[j+1] + 1;
				if (strs[j] < 2 && strs[j+1] >= 2) {
					j++;
				} else {
					break;
				}
			}
		}

		return this.toStr(strs);
	}

	private String reverse(String str) {
		return new StringBuffer(str).reverse().toString();
	}

	private String toStr(int []strs) {
		StringBuilder sb = new StringBuilder();
		for(int i = strs.length-1; i>=0; i--){
			var s = strs[i];
			if (s == 0 && sb.length() == 0){
				continue;
			}
			sb.append(s);
		}
		return sb.toString();
	}

	public static void main(String []args) {
		String [][] testArrays = {
			{"11", "10"},
			{"00011111", "10"},
			{"11", "00011111"},
			{"11", "100000"},
			{"11111111", "10"},
			{"11", "110"},
			{"1111111", "10"},
			{"0", "0"},
		};

		for(String []data: testArrays){
			String s1 = data[0];
			String s2 = data[1];

			O002 obj = new O002();
			var result = obj.addBinary(s1, s2);
			System.out.format("['%s', '%s'] Result: '%s'\n", s1, s2, result);
			System.out.println("======================");
		}
	}
}
