import java.util.*;

/**
 * 公众号：程序员石头
 * 加群验证题目
 */

public class HelloWorld {

	public static void main(String[] args) {
		System.out.println(sum(1, 36));
	}

	public static int sum(int start, int end) {
		int sum = start;
		for (int i = start+1; i <= end; i++) {
			sum += i;
		}
		return sum;
	}
}
