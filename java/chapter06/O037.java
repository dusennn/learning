import java.util.*;

/**
 * 037: 小行星碰撞
 * ❌ 判断逻辑太复杂，还存在bug
 */

public class O037 {
	/**
	 * 1. 使用栈来辅助计算（为了方便获取栈的大小，使用自定义栈类）
	 * 2. 循环小行星集合，
	 * 如果栈为空，直接放到栈中；
	 * 如果栈不为空，判断栈顶小行星和当前小行星的关系：
	 * 	如果栈顶星为正 && 当前星为正，当前星放入栈中；
	 * 	如果栈顶星为负 && 当前星为负，当前星放入栈中；
	 * 	如果栈顶星为负 && 当前星为正，当前星放入栈中；
	 * 	如果栈顶星为正 && 当前星为负，
	 * 		首先，while (栈不为空 && 栈顶星为正 && 当前星为负 && 栈顶星 < -当前星) 栈顶星出栈
	 * 		然后，如果栈顶星 == -当前星，栈顶出栈。否则判断如果栈为空，把当前星放进去；
	 * 3. 小行星集合循环结束，把栈中小行星返回，算法结束
	 */
	public int[] algorithm(int[] stars) {
		Stack<Integer> s = new Stack<>();
		for (int star: stars) {
			
			if (s.empty()) {
				s.push(star);
				continue;
			}

			while (!s.empty() && s.peek() > 0 && star < 0 && s.peek() < -star) {
				s.pop();
			}
			if (!s.empty() && s.peek() > 0 && star < 0 && s.peek() == -star) {
				s.pop();
			} else if(s.empty()){
				s.push(star);
			}
		}

		// //把栈转成数组返回
		int[] result = new int[s.size()];
		for (int i = s.size() - 1; i >= 0; i--) {
			result[i] = s.pop();
		}
		return result;
	}

	public static void main(String[] args) {
		int[][] testset = {
			{4, 5, -6, 4, 8, -5},
			{5,10,-5},
			{8,-8},
			{10,2,-5},
			{-2,-1,1,2},
			{-2,-2,1,-2}
		};

		var obj = new O037();
		for (int[] stars: testset) {
			var result = obj.algorithm(stars);
			System.out.printf("Starts:%s, Result:%s \n", 
				Arrays.toString(stars), Arrays.toString(result));
			System.out.println("=========================");
		}
	}
}

