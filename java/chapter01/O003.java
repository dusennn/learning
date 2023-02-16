import java.util.*;

/**
 * 剑指Offer 003: 前 n 个数字二进制形式中的个数
*/

public class O003{

	public int[] algorithm(){
		int input = this.systemIn();
		if (input <= 0) return new int[]{0};

		int []result = new int[input+1];
		for(int i = 0; i <= input; i++){
			for(int num = i; num > 0; num = num / 2) {
				result[i] = result[i] + (num % 2);
			}
		}
		return result;
	}

	private int systemIn(){
		Scanner scan = new Scanner(System.in);
		int input = 0;
		System.out.print("请输入0～n的整数：");
		if (scan.hasNextInt()){
			input = scan.nextInt();
		}
		scan.close();
		return input;
	}

	public static void main(String []args) {
		O003 obj = new O003();
		int [] result = obj.algorithm();
		System.out.format("Result: %s\n", Arrays.toString(result));
		System.out.println("=================");
	}
}
