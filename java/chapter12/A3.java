import java.util.*;

/**
 * 快速排序
 */

public class A3 {

	/**
	 * 1. 列表元素小于等于1，直接返回不用排序
	 * 2. 选择表头元素作为 key，定义 low 指向表头，定义 high 指向表尾
	 * 3. high 往左移动，如果指向的元素小于 key，则与 low 指向的元素交换位置，
	 * 4. low 往右移动，如果指向的元素大于 key，则与 high 指向的元素交换位置，
	 * 5. 等到 low 和 high 相遇时，把 key 复制到 low 和 high所在的位置，
	 * 然后把列表从这个点，一分为二，递归执行上述步骤。
	 */
	public void quickSort(int[] nums) {
		if (nums.length <= 1) return;

		core(nums, 0, nums.length - 1);
	}

	public void core(int[] nums, int start, int end) {
		if (start >= end) return;

		int key = nums[start];
		int low = start;
		int high = end;
		while (low < high) {
			while (low < high && nums[high] >= key) high--;
			nums[low] = nums[high];

			while (low < high && nums[low] <= key) low++;
			nums[high] = nums[low];
		}
		nums[low] = key;

		core(nums, start, low-1);
		core(nums, low+1, end);
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
			obj.quickSort(nums);
			System.out.printf("Dst:%s\n", Arrays.toString(nums));
			System.out.println("======================");
		}
	}
}
