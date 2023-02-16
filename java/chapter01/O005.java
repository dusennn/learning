import java.util.*;

/**
 * 005: 单词长度的最大乘积
*/

public class O005{

	public int algorithm(String[] strs){
		// 转换成set便于字符比较
		var sets = new ArrayList<HashSet<Character>>(strs.length);
		for(String str: strs){
			var set = new HashSet<Character>();
			for(int j = 0; j < str.length(); j++){
				set.add(str.charAt(j));
			}
			sets.add(set);
		}

		int maxVal = 0;
		for(int i = 0; i < strs.length; i++){
			for(int j = i; j < strs.length; j++){
				var tmpSet = new HashSet<Character>();
				tmpSet.addAll(sets.get(i));
				tmpSet.retainAll(sets.get(j)); // 通过并集判断两个字符串是否有相同字符
				if(tmpSet.size() == 0){
					var result = strs[i].length() * strs[j].length();
					maxVal = result > maxVal ? result:maxVal;
				}
			}
		}
		return maxVal;
	}

	public static void main(String[] args){
		String[][] testArrays = {
			{"abcw", "foo", "bar", "fxyz", "abcdef"},
		};

		var obj = new O005();
		for(String[] strs: testArrays){
			var result = obj.algorithm(strs);
			System.out.format("%s %d\n", Arrays.toString(strs), result);
			System.out.println("=======================");
		}
	}
}
