/**
 * 剑指Offer：001.整数除法
*/

public class IntegerDivision {
	private final int ERRORCODE = Integer.MAX_VALUE; //溢出值

	public int divide(int a, int b) {
		// 1.被除数为零
		if(a == 0) return 0;

		// 2.除数等于被除数
		if (b == a) return 1;

		// 3.除数等于1
		if (b == 1) return a;
		
		// 4.被除数为int最小值，除数为-1
		if (a == Integer.MIN_VALUE && b == -1 ) return ERRORCODE;

		// 5.统一正负号，并且记录是否有一正一负的情况
		boolean flag = true;
		if (a < 0 && b > 0) {
			flag = false;
			b = -b;
		} else if (a > 0 && b < 0) {
			flag = false;
			a = -a;
		} else if (a > 0 && b > 0) {
			a = -a;
			b = -b;
		}

		// 6.开始计算
		int result = 0;
		while(a <= b) {
			result ++;
			a = a - b;
		}

		// 7.若存在一正一负，结果为负
		return flag ? result:-result;
	}


	public static void main(String[] args) {
		int [][] testArrays = {
			{10, 5},
			{11, 5},
			{5, 5},
			{1, 5},
			{0, 1},
			{Integer.MAX_VALUE, 5},
			{Integer.MIN_VALUE, 5},
			{Integer.MAX_VALUE, Integer.MAX_VALUE},
			{Integer.MIN_VALUE, Integer.MIN_VALUE},
			{5, Integer.MIN_VALUE},
			{10, -5},		
			{-11, 5},
			{-5, -5},
			{1, -1},
			{-2147483648, -1}
		};

		IntegerDivision id = new IntegerDivision();
		for (int [] data: testArrays){
			var a = data[0];
			var b = data[1];

			try{
				var result = id.divide(a, b);
				var answer = a/b;
				System.out.format("[%d/%d] Result:%d, Answer:%d\n", a, b, result, answer);
			} catch(Exception e){
				System.out.println(e.toString());
			}

			System.out.println("=======================");
		}
	}
}
