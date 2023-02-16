import java.util.*;

/**
 * 006: 排序数组中的两数之和
*/

public class O006{
	public int[] algorithm(int[] numbers, int target){
		int n = numbers.length;
		int i = 0;
		int j = n - 1;

		while(i < j){
			var sum = numbers[i] + numbers[j];
			if(sum > target){
				j--;
			}else if(sum < target){
				i++;
			}else{
				break;
			}
		}
		return new int[]{i, j};
	}

	public static void main(String[] args){
		int[][] dataset = {
			{1,2,4,6,10},
			{2,3,4},
			{-1,0},
		};
		int[] targets = {
			8,
			6,
			-1,
		};
		
		var obj = new O006();
		for(int i = 0; i < dataset.length; i++){
			var result = obj.algorithm(dataset[i], targets[i]);
			System.out.format(
				"Target:%d, Value:%s, Result:%s\n", 
				targets[i],
				Arrays.toString(dataset[i]),
				Arrays.toString(result));
			System.out.println("=================");
		}
	}
}
