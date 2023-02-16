import java.util.*;

/**
 * 剑指Offer 004: 只出现一次的数字
*/

public class O004 {
	public int algorithm(int[] nums){
		int[] bitSums = new int[32];
		for(int num: nums){
			for(int i=0; i<32; i++){
				bitSums[i] += (num >> (31 - i)) & 1;
			}
		}

		int result = 0;
		for(int i = 0; i < 32; i++){
			result = (result << 1) + bitSums[i] % 3;
		}
		return result;
	}

	public static void main(String[] args){
		int[][] testArrays = {
			{2, 1, 1, 1, 100, 100, 100},
			{2, 2, 2, 1, 1, 1, 100},
			{5, 1, 1, 1, 100, 100, 100},
			{2, 2, 2, 1, 100, 100, 100},
			{-2,-2,1,1,4,1,4,4,-4,-2},
		};

		var obj = new O004();
		for(int[] nums: testArrays){
			int result = obj.algorithm(nums);
			System.out.format("Result: [%d]\n", result);
			System.out.println("=====================");
		}
	}
}
