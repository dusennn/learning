import java.util.*;

/**
 * 021: 删除倒数第k个节点
 */

class ListNode {
	public int val;
	public ListNode next;

	public ListNode(int _val) {
		this.val = _val;
	}
}

public class O021 {

	/**
	 * 0. 为了简化判断逻辑，可以定义哨兵节点，作为链表第一个元素
	 * 1. 使用双指针，p1 指向第一个节点，p2 指向第 k 个节点
	 * 2. 遍历链表，p1 和 p2 每次往右一个元素
	 * 3. 当 p2 为 null 时（到达链表末尾），p1 所在的位置为第 k 个节点
	 * 4. 删除 p1 所在的节点，返回链表，算法结束
	 */
	public ListNode algorithm(ListNode head, int k) {
		ListNode dummy = new ListNode(0);
		dummy.next = head;

		var p1 = dummy;
		var p2 = head;
		for (int i = 0; i < k; i++) {
			if (p2 != null) {
				p2 = p2.next;
			} else {
				return dummy.next; //链表没有 k 个元素
			}
		}

		while (p2 != null) {
			p1 = p1.next;
			p2 = p2.next;
		}
		p1.next = p1.next.next;
		return dummy.next;
	}

	// 生成链表
	private ListNode init(int[] data) {
		if (data.length == 0) return null;

		var head = new ListNode(data[0]);
		var node = head;
		for (int i = 1; i < data.length; i++) {
			ListNode next = new ListNode(data[i]);
			node.next = next;
			node = next;
		}
		return head;
	}

	// 打印链表
	private void print(ListNode head) {
		if (head == null) {
			System.out.println("null");
			return;
		}

		while (head != null) {
			System.out.printf("[%d]->", head.val);
			head = head.next;
		}
		System.out.println("");
	}

	public static void main(String[] args) {
		int[][] testset = {
			{1, 2, 3, 4, 5, 6},
			{1, 2, 3},
			{1},
			{1, 2},
			{1, 2},
		};
		int[] targets = {
			3,
			2,
			1,
			1,
			3,
		};

		var obj = new O021();
		for (int i = 0; i < testset.length; i++) {
			var head = obj.init(testset[i]);
			var k = targets[i];
			obj.print(head);

			var result = obj.algorithm(head, k);
			obj.print(result);
			System.out.println("=================");
		}
	}
}

