import java.util.*;

/**
 * 041: 滑动窗口的平均值
 */
public class O041 {
	public static void main(String[] args) {
		int size = 5;
		var obj = new MovingAverage(size);

		System.out.println(obj.next(1));
		System.out.println(obj.next(2));
		System.out.println(obj.next(3));
		System.out.println(obj.next(4));
		System.out.println(obj.next(5));
		System.out.println(obj.next(6));
	}
}

class MovingAverage {
	private ArrayDeque<Integer> queue;
	private int size;
	private double totalSum;

	public MovingAverage(int _size) {
		this.queue = new ArrayDeque<>(_size);
		this.size = _size;
		this.totalSum = 0;
	}

	public double next(int val) {
		if (this.queue.size() >= this.size) {
			this.totalSum -= this.queue.pop(); //从队列头部弹出元素
		}

		this.queue.add(val); //添加到队列的尾部
		this.totalSum += val;
		return this.totalSum / this.queue.size();
	}
}
