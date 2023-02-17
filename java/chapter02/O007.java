import java.util.*;

/**
 * 007: 数组中和为0的三个数字
 * ❌ 存在bug
*/

public class O007{
	public List<List<Integer>> algorithm(int[] nums){
		Arrays.sort(nums); //排序

		List<List<Integer>> result = new LinkedList<>();
		// 找出和为零的三个数
		for(int i = 0; i < nums.length; i++){
			int target = -nums[i];
			int j = i+1;
			int k = nums.length - 1;
			while(j < k){
				int sum = nums[j] + nums[k] + target;
				if(sum > 0){
					k--;
				}else if(sum < 0){
					j++;
				}else{
					result.add(Arrays.asList(nums[i], nums[j], nums[k]));
					j++;
				}
			}
		}

		// List<Integer> dupIndex = new ArrayList<>();
		// 去除重复的元素
		for(int i = 0; i < result.size(); i++){
			for(int j = i+1; j < result.size(); j++){
				if(result.get(i).get(0) == result.get(j).get(0) 
					&& result.get(i).get(1) == result.get(j).get(1) 
					&& result.get(i).get(2) == result.get(j).get(2)){
					result.remove(j);
					j--;
				}
			}
		}
		return result;
	}

	public static void main(String[] args){
		int[][] dataset = {
			{-1, 0, 1, 2, -1, -4},
			{12,5,-12,4,-11,11,2,7,2,-5,-14,-3,-3,3,2,-10,9,-15,2,14,-3,-15,-3,-14,-1,-7,11,-4,-11,12,-15,-14,2,10,-2,-1,6,7,13,-15,-13,6,-10,-9,-14,7,-12,3,-1,5,2,11,6,14,12,-10,14,0,-7,11,-10,-7,4,-1,-12,-13,13,1,9,3,1,3,-5,6,9,-4,-2,5,14,12,-5,-6,1,8,-15,-10,5,-15,-2,5,3,3,13,-8,-13,8,-5,8,-6,11,-12,3,0,-2,-6,-14,2,0,6,1,-11,9,2,-3,-6,3,3,-15,-5,-14,5,13,-4,-4,-10,-10,11},
			{0,0,0,0},
			{-2,0,1,1,2}
		};
		
		var obj = new O007();
		for(int i = 0; i < dataset.length; i++){
			var result = obj.algorithm(dataset[i]);
			System.out.format(
				"Value:%s, Result:%s\n", 
				Arrays.toString(dataset[i]),
				result);
			System.out.println("=================");
		}
	}
}
