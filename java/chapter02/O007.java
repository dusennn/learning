import java.util.*;

/**
 * 007: 数组中和为0的三个数字
*/

public class O007{
	public List<List<Integer>> algorithm(int[] nums){
		Arrays.sort(nums); //排序便于去除重复元素

		List<List<Integer>> result = new LinkedList<>();
		// 找出和为零的三个数
		for(int i = 0; i < nums.length; i++){
			for(int j = i+1; j < nums.length; j++){
				for(int k = j+1; k < nums.length; k++){
					if(nums[i] + nums[j] + nums[k] == 0){
						result.add(Arrays.asList(nums[i], nums[j], nums[k]));
					}
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
			{-1, 0, 1, 2, -1, -4}，
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
