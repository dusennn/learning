import java.util.*;

/**
 * 归并排序
 */
public class A4 {

	/**
	 * 1. 如果两个数组都是有序的，那么很容易合并成一个有序数组。
	 * 2. 对于一个无序数组，从中间分成两段，然后对这两段分别从中间拆分，递归进行，
	 * 		[9, 2, 10, 8, 11, 1]
	 * [9, 2, 10]		[8, 11, 1]
	 * [9, 2] [10]		[8, 11] [1]
	 * [9] [2]			[8] [11]
	 * 拆分到最后，子数组中只有一个元素，然后进行合并，成为有序数组。依次反递归进行，
	 * 合并到最后，会产生一个有序数组。
	 * 
	 * 注意：
	 * 1. 数组合并时，两个数组不会同时结束，需要处理尾部多出来的元素。
	 */
	public void mergeSort(int[] nums, int start, int end) {
		if (start >= end) return;

		int mid = (end + start) / 2;
		mergeSort(nums, start, mid);
		mergeSort(nums, mid+1, end);
		merge(nums, start, mid, end);
	}

	// 两个有序数组（或者一个数组中两段有序子数组），合并成一个有序数组
	public void merge(int[] nums, int start, int mid, int end) {
		int[] temp = new int[end - start + 1];

		int i = start;
		int j = mid+1;
		int t = 0; //temp 的下标
		while (i <= mid && j <= end) {
			if (nums[i] <= nums[j]) {
				temp[t] = nums[i];
				i++;
				t++;
			} else {
				temp[t] = nums[j];
				j++;
				t++;
			}
		}

		//补充尾部没用到元素
		while (i <= mid) {
			temp[t] = nums[i];
			i++;
			t++;
		}
		while (j <= end) {
			temp[t] = nums[j];
			j++;
			t++;
		}

		// 把临时表的数据复制到原表
		for(int n = 0; n < temp.length; n++) {
			nums[start + n] = temp[n];
		}
	}

	// 两个有序数组，合并成一个有序数组
	public int[] merge(int[] nums1, int[] nums2) {
		int[] result = new int[nums1.length + nums2.length];

		int i = 0;
		int j = 0;
		while (i < nums1.length && j < nums2.length) {
			if (nums1[i] <= nums2[j]) {
				result[i + j] = nums1[i];
				i++;
			} else {
				result[i + j] = nums2[j];
				j++;				
			}
		}

		while (i < nums1.length) {
			result[i + j] = nums1[i];
			i++;
		}
		while (j < nums2.length) {
			result[i + j] = nums2[j];
			j++;
		}

		return result;
	}

	public static void main(String[] args) {
		int[][] testset = {
			{11, 2, 3, 4, 5, 6, 7, 8},
			{1, 222, 1, 4, 5, 6, 7, 8},
			{1, 2, 33, 33, 5, 6, 7, 8},
		};

		var obj = new A4();
		for (int i = 0; i < testset.length; i++) {
			var nums = testset[i];

			System.out.printf("Src:%s\n", Arrays.toString(nums));
			obj.mergeSort(nums, 0, nums.length-1);
			System.out.printf("Dst:%s\n", Arrays.toString(nums));
			System.out.println("======================");
		}
	}
}
