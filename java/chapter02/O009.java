import java.util.*;

/**
 * 009: 乘积小于 k 的子数组数量
 */

public class O009 {

	/**
	 * 利用双指针
	 * 1. 令指针 p1 p2 指向数组开头
	 * 2. 如果 p1 p2 之间元素的乘积小于 k，令计数加上 p1 p2间的元素总数，
	 * 然后向右移动 p2 指针。
	 * 3. 如果 p1 p2 对应元素的乘积大于 k，
	 * 		如果 p1 p2 相等，且 p1 p2 不在数组尾部，p1 p2同时往右移动
	 * 		如果 p1 p2 不相等，p1 往右移动
	 * 4. p1 p2 移动至数组尾部，算法中止，返回找到的结果计数。
	 */
	public int algorithm(int[] nums, int k) {
		int count = 0;

		int p1 = 0;
		int p2 = 0;
		while (p1 <= p2 && p2 < nums.length) {

			int sum = 1;
			for (int i = p1; i <= p2; i++) {
				sum *= nums[i];
			}

			if (sum < k) {
				count += p2 - p1 + 1;
				p2++;
			} else {
				if (p1 == p2) {
					p1++;
					p2++;
				} else {
					p1++;
				}
			}
		}

		return count;
	}

	public static void main(String[] args) {
		int[][] testset = {
			{1, 2, 3, 4, 5, 6, 7},
		};
		int[] targets = {
			4,
		};

		var obj = new O009();
		for (int i = 0; i < testset.length; i++) {
			var nums = testset[i];
			var k = targets[i];
			var result = obj.algorithm(nums, k);
			System.out.printf("Nums:%s, K:%d, Result:%s\n", 
				Arrays.toString(nums), k, result);
			System.out.println("====================");
		}
	}
}
