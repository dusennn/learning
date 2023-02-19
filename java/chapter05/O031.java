import java.util.*;

/**
 * 031: 最近最少使用缓存
 * 
 * 1. 使用双向链表记录元素的使用频率：
 * 每次访问的元素移动到链表尾部，链表头部即为最近最少使用
 * 2. 使用 HashMap 满足 get put 为O(1)的操作：
 * map.key = 元素值；map.value = 链表的一个节点；
 */

public class O031 {
	public static void main(String[] args) {
		boolean debug = false;

		String[] opt = {
			"LRUCache","put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put",
		};
		int[][] testset = {
			{10},{10,13},{3,17},{6,11},{10,5},{9,10},{13},{2,19},{2},{3},{5,25},{8},{9,22},{5,5},{1,30},{11},{9,12},{7},{5},{8},{9},{4,30},{9,3},{9},{10},{10},{6,14},{3,1},{3},{10,11},{8},{2,14},{1},{5},{4},{11,4},{12,24},{5,18},{13},{7,23},{8},{12},{3,27},{2,12},{5},{2,9},{13,4},{8,18},{1,7},{6},{9,29},{8,21},{5},{6,30},{1,12},{10},{4,15},{7,22},{11,26},{8,17},{9,29},{5},{3,4},{11,30},{12},{4,29},{3},{9},{6},{3,4},{1},{10},{3,29},{10,28},{1,20},{11,13},{3},{3,12},{3,8},{10,9},{3,26},{8},{7},{5},{13,17},{2,27},{11,15},{12},{9,19},{2,15},{3,16},{1},{12,17},{9,1},{6,19},{4},{5},{5},{8,1},{11,7},{5,2},{9,28},{1},{2,2},{7,4},{4,22},{7,24},{9,26},{13,28},{11,26},
		};
		List<Integer> results = new ArrayList<>(opt.length);

		LRUCache lru = null;
		for (int i = 0; i < opt.length; i++) {
			var data = testset[i];

			switch (opt[i]) {
			case "LRUCache":
				lru = new LRUCache(data[0]);
				results.add(null);
				break;
			case "put":
				lru.put(data[0], data[1]);
				results.add(null);
				break;
			case "get":
				var result = lru.get(data[0]);
				results.add(result);
				break;
			}

			if (debug) {
				lru.print();
				System.out.println("===============");	
			}
		}

		System.out.println(results);
	}
}

class LRUCache {
	private ListNode head;
	private ListNode tail;
	private Map<Integer, ListNode> map;
	private int cap; //容量

	public LRUCache(int _cap) {
		this.cap = _cap;
		this.head = new ListNode(0, 0);
		this.tail = new ListNode(0, 0);
		this.head.prev = null;
		this.head.next = this.tail;
		this.tail.prev = this.head;
		this.tail.next = null;
		this.map = new HashMap<>();
	}

	public int get(int key) {
		if (!this.map.containsKey(key)) return -1;

		//获取数据
		var node = this.map.get(key);
		// 移动节点
		this.move(node);
		return node.value;
	}

	public void put(int key, int value) {
		//已经存在：更新value
		if (this.map.containsKey(key)) {
			this.update(key, value);
		} else { //不存在，新增
			// 检查容量
			if (this.cap < 1) {
				//容量不足，删除最少使用
				this.removeLR();
			}
			// 添加新元素
			this.add(key, value);
		}
	}

	// 添加元素
	private void add(int key, int value) {
		//容量减1
		this.cap--;
		//添加
		var node = new ListNode(key, value);
		node.prev = this.tail.prev;
		node.next = this.tail;
		this.tail.prev.next = node;
		this.tail.prev = node;
		//映射
		this.map.put(key, node);
	}

	// 更新元素
	private void update(int key, int value) {
		var node = this.map.get(key);
		node.key =  key;
		node.value =  value;
		// 移动节点
		this.move(node);
	}

	// 移除元素
	private void removeLR() {
		var lrNode = this.head.next;
		lrNode.next.prev = this.head;
		this.head.next = lrNode.next;
		this.map.remove(lrNode.key);
		//容量加1
		this.cap++;
	}

	// 节点移动：用于维护元素在链表中的顺序，以满足最近最少使用
	private void move(ListNode node) {
		//移动数据到链表尾部
		//把当前节点的上一个元素和下一个元素链接在一起
		node.prev.next = node.next;
		node.next.prev = node.prev;
		//移动到尾部
		this.tail.prev.next = node;
		node.prev = this.tail.prev;
		this.tail.prev = node;
		node.next = this.tail;
	}

	// 用于打印调试
	public void print() {
		System.out.println(this.cap);
		System.out.println(this.map);
		ListNode.print(this.head);
	}
}

class ListNode {
	public int key;
	public int value;
	public ListNode prev; //指向上一个元素
	public ListNode next; //指向下一个元素

	public ListNode(int _key, int _value) {
		this.key = _key;
		this.value = _value;
	}

	// 打印一个链表
	public static void print(ListNode head) {
		if (head == null) {
			System.out.println("[]");
			return;
		}
		var node = head;
		while (node != null) {
			System.out.printf("[%d]->", node.value);
			node = node.next;
		}
		System.out.println("");
	}
}
