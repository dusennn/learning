/**
 * 整数除法
*/

public class IntegerDivision {

	public int divide(int num1, int num2) throws IllegalArgumentException {
		// 1.除数为零
		if(num2 == 0) throw new IllegalArgumentException("除数为零！");

		// 2.被除数为零
		if(num1 == 0) return 0;

		// 3. 除数等于1
		if (num2 == 1) return num1;

		// 4. 被除数等于1
		if (num1 == 1) return 0;

		// 5.除数等于被除数
		if (num1 == num2) return 1;

		// 6. 开始计算，循环被除数，不断减去除数
		int result = 0;
		boolean flag = true; //结果为正或负：正/正=正 负/正=负... 
		// 6.1.被除数大于零
		if (num1 > 0) {
			if (num2 == Integer.MIN_VALUE) throw new IllegalArgumentException("除数值溢出！");

			if (num2 < 0) {
				flag = false;
				num2 = -num2;
			}

			while(num1 >= num2){
				result ++;
				num1 = num1 - num2;
			}
		} else {
			if (num2 > 0){
				flag = false;
				num2 = -num2;
			}

			while(num1 <= num2){
				result ++;
				num1 = num1 - num2;
			}
		}
		return flag ? result: -result;
	}


	public static void main(String[] args) {
		int [][] testArrays = {
			{10, 5},
			{11, 5},
			{5, 5},
			{1, 5},
			{1, 0},
			{0, 1},
			{0, 0},
			{Integer.MAX_VALUE, 5},
			{Integer.MIN_VALUE, 5},
			{Integer.MAX_VALUE, Integer.MAX_VALUE},
			{Integer.MIN_VALUE, Integer.MIN_VALUE},
			{5, Integer.MIN_VALUE},
			{10, -5},		
			{-11, 5},
			{-5, -5},
		};

		IntegerDivision id = new IntegerDivision();
		for (int [] data: testArrays){
			var num1 = data[0];
			var num2 = data[1];

			try{
				var result = id.divide(num1, num2);
				var answer = num1/num2;
				System.out.format("[%d/%d] Result:%d, Answer:%d\n", num1, num2, result, answer);
				assert result == answer;
			} catch(Exception e){
				System.out.println(e.toString());
			}

			System.out.println("=======================");
		}
	}
}
