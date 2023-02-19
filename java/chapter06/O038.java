import java.util.*;

/**
 * 038: 每日温度
 */

public class O038 {
	
	/**
	 * 1. 循环温度数组，
	 * 2. 如果栈为空，温度入栈；如果栈不为空：
	 * 	先处理情况a：栈顶温度小于当前温度
	 * 		while (栈顶温度 < 当前温度)
	 * 			栈顶出栈，并把计数器的值保存到结果集中
	 * 	然后处理情况b1：栈空了
	 * 		当前温度入栈
	 * 	然后处理情况b2：栈没空 && 栈顶温度 >= 当前温度
	 * 		当前温度入栈
	 * 3. 返回结果集，算法结束
	 * 
	 * 注意：
	 * 1. 结果集的设计：和温度数组长度一样，元素值为天数
	 * 2. 栈中保存温度值的数组下标，便于结果回写到结果集
	 */
	public int[] algorithm(int[] temps) {
		int[] result = new int[temps.length];

		Stack<Integer> stack = new Stack<>();
		for (int i = 0; i < temps.length; i++) {
			var curTemp = temps[i];

			while(!stack.empty() && temps[stack.peek()] < curTemp) {
				var prevI = stack.pop();
				result[prevI] = i - prevI;
			}

			if (stack.empty()) {
				stack.push(i);
			} else if (!stack.empty() && temps[stack.peek()] >= curTemp) {
				stack.push(i);
			}
		}

		return result;
	}

	public static void main(String[] args) {
		int[][] testset = {
			{35, 31, 33, 36, 34},
			{73,74,75,71,69,72,76,73},
			{30,40,50,60},
			{30,60,90},
		};

		var obj = new O038();
		for (int[] temps: testset) {
			var result = obj.algorithm(temps);
			System.out.printf("Temps:%s, Result:%s \n", 
				Arrays.toString(temps), Arrays.toString(result));
			System.out.println("=========================");
		}
	}
}

