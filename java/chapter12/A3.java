import java.util.*;

/**
 * 快速排序
 */

public class A3 {

	/**
	 * 快速排序
	 * 1. 选取第一个元素作为基准点 flag
	 * 2. 定义两个指针 p1 p2，p1 指向第一个元素，p2 指向 p1 的下一个
	 * 3. 不断往右移动 p2 指针，当遇到比 flag 小的元素，把p1往右移动一步，
	 * 把 p1 位置的元素与 p2 进行交换，然后继续往右移动 p2。
	 * 当 p2 移动到数组尾部时，把基准点元素与 p1 的位置进行交换，第一次排序完成。
	 * 4. 然后按照 p1 所在的位置，把数组分为两段，分别按照 第1、2、3步的方式进行处理
	 * 5. 直到数组无法拆分，只有一个元素时，排序结束
	 */
	public int[] algorithm(int[] nums) {
		int start = 0;
		int end = nums.length;
		core(nums, start, end);
		return nums;
	}

	private void core(int[] nums, int start, int end) {
		if (start >= end) return;
		
		int key = nums[start]; //基准值
		int p1 = start;
		int p2 = p1 + 1;
		while (p2 < end) {
			if (nums[p2] < key) {
				p1++;
				swap(nums, p1, p2);
			}
			p2++;
		}
		nums[start] = nums[p1];
		nums[p1] = key;

		//前半段
		core(nums, start, p1-1);
		//后半段 
		core(nums, p1+1, end);
	}

	private void swap(int[] nums, int i, int j) {
		if (i == j) return;

		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}

	public static void main(String[] args) {
		int[][] testset = {
			{11, 2, 3, 4, 5, 6, 7, 8},
			{1, 222, 1, 4, 5, 6, 7, 8},
			{1, 2, 33, 33, 5, 6, 7, 8},
		};

		var obj = new A3();
		for (int i = 0; i < testset.length; i++) {
			var nums = testset[i];

			System.out.printf("Src:%s\n", Arrays.toString(nums));
			var result = obj.algorithm(nums);
			System.out.printf("Dst:%s\n", Arrays.toString(result));
			System.out.println("======================");
		}
	}
}
