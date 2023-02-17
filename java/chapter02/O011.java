import java.util.*;

/**
 * 011: 0 和 1 个数组相同的子数组
 * ❌ 暂时没思路
 */

public class O011 {

	/**
	 * 1. 数组中只有0和1，令 0 转换成 -1，转变成求子数组和的问题
	 * 2. 计算出数组的每一项与前n项的和，放到一个新数组
	 * 3. 在新数组中，从后往前遍历，和为零
	 */
	public int algorithm(int[] nums) {

	}

	public static void main(String[] args) {
		int[][] testset = {
			{0, 1, 0},
		};

		var obj = new O011();
		for (int[] nums: testset) {
			int result = obj.algorithm(nums);
			System.out.printf("Nums:%s, Result:%d", 
				Arrays.toString(nums), result);
			System.out.println("====================");
		}
	}
}
