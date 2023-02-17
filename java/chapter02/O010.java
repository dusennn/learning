import java.util.*;

/**
 * 010: 和为 k 的子数组
 */

public class O010 {

	/**
	 * 累加数组数字
	 * 1. 先计算，数组中每一项的前n项之和，放到一个新数组中
	 * 2. 计算新数组中，每一项与其它项的差值
	 * 3. 如果差值等于k，则找到一个满足条件的子数组，计数加1
	 */
	public int algorithm(int[] nums, int k) {
		int result = 0;

		int[] sumNums = new int[nums.length + 1]; //第0项为0；
		for (int i = 0; i < nums.length; i++) {
			sumNums[i + 1] = sumNums[i] + nums[i];
		}

		for (int i = sumNums.length - 1; i >= 0; i--) {
			for (int j = i - 1; j >= 0; j--) {
				if (sumNums[i] - sumNums[j] == k) {
					result++;
				}
			}
		}

		return result;
	}

	public static void main(String[] args) {
		int[][] testset = {
			{1, 1, 1},
			{1, 1, 1},
			{1, 2, 3, 4, 5, 6},
			{1, 2, 3, 4, 5, 6},
		};
		int[] targets = {
			1,
			2,
			6,
			3,
		};

		var obj = new O010();
		for(int i = 0; i < testset.length; i++) {
			var nums = testset[i];
			var k = targets[i];
			var result = obj.algorithm(nums, k);
			System.out.printf("Nums:%s, K:%d, Result:%d\n", 
				Arrays.toString(nums), k, result);
			System.out.println("=========================");
		}
	}
}
