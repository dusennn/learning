import java.util.*;

/**
 * 剑指Offer 068: 查找插入位置
 */

public class O068 {

	/**
	 * 1. 使用二分查找法，令 left 指向数组开头，right 指向数组结尾
	 * 2. 循环判断 mid(left + ((right - left) / 2)) 位置的元素，与 target 的关系
	 * 	如果大于 target，left = mid + 1
	 * 	如果小于 target, right = mid - 1
	 * 	如果等于 target, 返回 mid
	 * 3. 当 left > right，循环结束
	 * 4. 判断 left 位置的元素，与 target 的关系
	 * 	如果 left 已经达到数组长度，返回 left
	 * 	如果大于 target，返回 left
	 * 	如果小于 target，返回 left + 1
	 */
	public int algorithm(int[] nums, int target) {
		int left = 0;
		int right = nums.length - 1;

		while (left <= right) {
			int mid = left + ((right - left) / 2);

			if (nums[mid] < target) {
				left = mid + 1;
			} else if (nums[mid] > target) {
				right = mid - 1;
			} else {
				return mid;
			}
		}

		if (left == nums.length) {
			return left; 
		}

		if (nums[left] > target) {
			return left;
		} else {
			return left + 1;
		}
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

		var obj = new O068();
		for (int i = 0; i < testset.length; i++) {
			var nums = testset[i];
			var target = targets[i];

			var result = obj.algorithm(nums, target);
			System.out.printf("Nums:%s, Target:%d, Result:%d\n", 
				Arrays.toString(nums), target, result);
			System.out.println("======================");
		}
	}
}
