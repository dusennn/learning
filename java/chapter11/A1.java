import java.util.*;

/**
 * 11.1 二分查找法
 */

public class A1 {

	/**
	 * 二分查找
	 * 	给定一个有序数组 nums，目标数字 target，判断是否在数组中
	 * 1. 令 left 指向数组开头，right 指向数组末尾
	 * 2. 循环判断 mid = left + ((right - left) / 2) 位置元素 与 target 的关系
	 * 	如果小于 target，令 left = mid - 1 
	 * 	如果大于 target，令 right = mid + 1
	 * 	如果等于 target，查找成功
	 * 3. 当 left > right 时，还未找到 target，查找失败
	 */
	public int binarySearch(int[] nums, int target) {
		int left = 0;
		int right = nums.length - 1;

		while (left <= right) {
			int mid = left + ((right - left) / 2);

			if (nums[mid] < target) {
				left = mid + 1;
			} else if (nums[mid] > target) {
				right = mid - 1; // +1 -1 为了跳过mid，因为 mums[mid] != target
			} else {
				return 1; // 查找成功
			}

		}
		return -1; //查找失败
	}

	public static void main(String[] args) {
		int[][] testset = {
			{1, 2, 3, 4, 5, 6, 7, 8},
			{1, 2, 3, 4, 5, 6, 7, 8},
			{1, 2, 3, 4, 5, 6, 7, 8},
			{1, 2, 3, 4, 5, 6, 7, 8},
			{1, 2, 3, 4, 5, 6, 7, 8},
		};
		int[] targets = {
			2,
			1,
			8,
			0,
			10
		};

		var obj = new A1();
		for (int i = 0; i < testset.length; i++) {
			var nums = testset[i];
			var target = targets[i];

			var result = obj.binarySearch(nums, target);
			System.out.printf("Nums:%s, Target:%d, Result:%d\n", 
				Arrays.toString(nums), target, result);
			System.out.println("======================");
		}
	}
}
