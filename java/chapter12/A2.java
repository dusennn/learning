import java.util.*;

/**
 * 计数排序
 */

public class A2 {

	/**
	 * 计数排序
	 * 1. 求出待排序数组中的最小值和最大值
	 * 2. 创建临时数组，记录待排序数组中，每个元素的出现次数
	 * 3. 循环待排序数组，按照临时数组的记录填充待排序数组
	 */
	public int[] algorithm(int[] nums) {
		int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;
		for (int num: nums) {
			min = num < min ? num : min;
			max = num > max ? num : max;
		}

		int[] counts = new int[max - min + 1];
		for (int num: nums) {
			counts[num - min]++;
		}

		int i = 0;
		for (int num = min; num <= max; num++) {
			while (counts[num - min] > 0) {
				nums[i] = num;
				i++;
				counts[num - min]--;
			}
		}

		return nums;
	}

	public static void main(String[] args) {
		int[][] testset = {
			{11, 2, 3, 4, 5, 6, 7, 8},
			{1, 222, 1, 4, 5, 6, 7, 8},
			{1, 2, 33, 33, 5, 6, 7, 8},
		};

		var obj = new A2();
		for (int i = 0; i < testset.length; i++) {
			var nums = testset[i];

			var result = obj.algorithm(nums);
			System.out.printf("Nums:%s, Result:%s\n", 
				Arrays.toString(nums), Arrays.toString(result));
			System.out.println("======================");
		}
	}
}
