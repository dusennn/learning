import java.util.*;

/**
 * 008: 和大于或等于k的最短子数组
 * 
 * 使用双指针，
 * 1. 指针a 和 b指向数组的开头
 * 2. 计算a到b之间的元素之和，以及元素的路径长度。
 * 3. 如果元素和小于k，则把b往右移动。如果元素和大于k，则把a往右移动。
 * 4. 当a 指针移动到末尾时，算法结束。
 */

public class O008 {
	public int algorithm(int[] nums, int k) {
		int a = 0;
		int b = 0;
		int range = Integer.MAX_VALUE; //初始为最大值，便于求最短路径
		while (a < nums.length && b < nums.length && a >= 0 && b >= a) {

			int sum = 0;
			for (int i = a; i <= b; i++) {
				sum += nums[i];
			}

			if (sum < k) {
				b++;
			} else {
				if (range > b - a + 1) {
					range = b - a + 1;
				}
				a++;
			}
		}
		// 没有合适路径，返回0
		if (range == Integer.MAX_VALUE) return 0;

		return range;
	} 

	public static void main(String[] args) {
		int[][] testset = {
			{5, 1, 4, 3},
		};
		int[] targets = {
			7
		};

		var obj = new O008();
		for (int i = 0; i < testset.length; i++) {
			var nums = testset[i];
			var target = targets[i];
			var result = obj.algorithm(nums, target);
			System.out.format("Nums:%s, Target:%d Result:%d\n", 
				Arrays.toString(nums), target, result);
			System.out.println("========================");
		}
	}
}
