import java.util.*;

/**
 * 042: 最近请求次数
 */
public class O042 {
	public static void main(String[] args) {
		String[] opts = {
			"RecentCounter", "ping", "ping", "ping", "ping",
		};
		int[][] testset = {{}, {1}, {100}, {3001}, {3002}};
		
		Integer[] results = new Integer[opts.length];

		RecentCounter obj = null;
		for (int i = 0; i < opts.length; i++) {
			switch (opts[i]) {
			case "RecentCounter":
				obj = new RecentCounter();
				results[i] = null;
				break;
			case "ping":
				var data = testset[i][0];
				var result = obj.ping(data);
				results[i] = result; 
				break;
			}			
		}
		System.out.println(Arrays.toString(results));		
	}
}

class RecentCounter {
	private static final int WINDOW_SIZE = 3000; //窗口大小
	private LinkedList<Integer> queue;

	public RecentCounter() {
		this.queue = new LinkedList<>();
	}

	/**
	 * 1. 使用队列保存过去 3000ms 的数据
	 * 2. 如果新的数据，超过了 3000ms，则把最先进队列的元素弹出。
	 * 否则，把新元素放入队列。
	 */
	public int ping(int t) {
		while (this.queue.size() > 0 && t - this.queue.peek() > this.WINDOW_SIZE) {
			this.queue.poll();
		}
		this.queue.offer(t);
		return this.queue.size();
	}
}
