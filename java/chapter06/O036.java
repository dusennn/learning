import java.util.*;

/**
 * 036: 后缀表达式
 */

public class O036 {
	/**
	 * 1. 循环后缀数组，使用栈保存暂时用不到的元素
	 * 2. 当遇到 + - * / 时，从栈中取出两个元素，进行操作，
	 * 把操作结果继续放入栈。
	 * 3. 当数组循环结束，从栈顶取出元素，此元素即为结果
	 */
	public int algorithm(String[] elems) {
		// 存储常用的操作符
		Set<String> opts = Set.of("+", "-", "*", "/");

		Stack<Integer> s = new Stack<>();
		for (String elem: elems) {
			if (opts.contains(elem)) {
				var num1 = s.pop();
				var num2 = s.pop();
				s.push(this.cal(elem, num1, num2));
			} else {
				s.push(Integer.parseInt(elem));
			}
		}
		return s.pop();	
	}

	//根据运算符执行计算逻辑
	private int cal(String opt, int num1, int num2) {
		switch (opt) {
		case "+":
			return num2 + num1;
		case "-":
			return num2 - num1;
		case "*":
			return num2 * num1;
		case "/":
			return num2 / num1;
		default:
			return -1; //无效运算
		}
	}

	public static void main(String[] args) {
		String[][] testset = {
			{"1", "2", "4", "+", "*"},
			{"2","1","+","3","*"},
			{"4","13","5","/","+"},
			{"10","6","9","3","+","-11","*","/","*","17","+","5","+"},
		};
		int[] targets = {
			6,
			9,
			6,
			22,
		};

		var obj = new O036();
		for (int i = 0; i < testset.length; i++) {
			var elems = testset[i];
			var target = targets[i];

			var result = obj.algorithm(elems);
			System.out.printf("Elems:%s, Target:%d, Result:%d\n", 
				Arrays.toString(elems), target, result);
			System.out.println("=====================");
		}
	}
}
