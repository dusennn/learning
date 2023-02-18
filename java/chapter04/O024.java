import java.util.*;

/**
 * 024：反转单向链表
 */

class ListNode {
	public int val;
	public ListNode next;

	public ListNode(int _val) {
		this.val = _val;
	}

	// 生成一个链表
	public static ListNode generate(int[] data) {
		ListNode dummy = new ListNode(0);

		var head = dummy;
		for (int i = 0; i < data.length; i++) {
			head.next = new ListNode(data[i]);
			head = head.next;
		}

		return dummy.next;
	}

	// 打印一个链表
	public static void print(ListNode head) {
		if (head == null) {
			System.out.println("[]");
			return;
		}
		var node = head;
		while (node != null) {
			System.out.printf("[%d]->", node.val);
			node = node.next;
		}
		System.out.println("");
	}
}

public class O024 {

	/**
		 * 1. 遍历原始链表
		 * 2. 用三个指针 p1 p2 p3 记录当前元素的 上一个节点、当前节点、下一个节点
		 * 3. 初始化时，p1 = null，每次循环令 p3 = p2.next; p2.next = p1; p1 = p2; p2 = p3;
		 * 4. 直到 p2 为空，循环结束，返回 p1，即反转后链表的头指针
	 */
	public ListNode algorithm(ListNode head) {
		if (head == null) return null;

		ListNode p1 = null;
		ListNode p2 = head;
		while (p2 != null) {
			ListNode p3 = p2.next;
			p2.next = p1;
			p1 = p2;
			p2 = p3;
		}
		return p1;
	}

	public static void main(String[] args) {
		int[][] testset = {
			{1, 2, 3, 4, 5},
			{2, 1, 3}
		};

		var obj = new O024();
		for (int[] data: testset) {
			ListNode head = ListNode.generate(data);
			ListNode.print(head);

			var result = obj.algorithm(head);
			ListNode.print(result);
			System.out.println("=================");
		}
	}

}
