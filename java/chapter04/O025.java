import java.util.*;

/**
 * 025: 两个链表相加
 */

public class O025 {

	/**
	 * 1. 先把两个链表反转，得到 r1 和 r2
	 * 2. 遍历链表，依次把每个元素相加，并把结果放到新链表中
	 * （需要注意满10进一）
	 * 3. 反转新链表，作为结果集返回
	 */
	public ListNode algorithm(ListNode head1, ListNode head2) {
		head1 = this.reverse(head1);
		head2 = this.reverse(head2);

		ListNode dummy = new ListNode(0);
		var head = dummy;
		int n = 0; //需要进位的数量（10进一）
		while (head1 != null || head2 != null) {
			int v1 = 0;
			int v2 = 0;
			if (head1 != null) {
				v1 = head1.val;
				head1 = head1.next;
			}
			if (head2 != null) {
				v2 = head2.val;
				head2 = head2.next;
			}

			// 计算
			var sum = v1 + v2 + n;
			var node = new ListNode(sum % 10);
			head.next = node;
			head = node;
			n = sum / 10;
		}

		if (n > 0) { //还有需要进位的数
			head.next = new ListNode(n);
		}

		return this.reverse(dummy.next);
	}

	private ListNode reverse(ListNode head) {
		ListNode prev = null;
		ListNode cur = head;
		while (cur != null) {
			var next = cur.next;
			cur.next = prev;
			prev = cur;
			cur = next;
		}
		return prev;
	}

	public static void main(String[] args) {
		int[][] testset1 = {
			{1, 2, 3},
			{1, 9},
		};
		int[][] testset2 = {
			{1, 2, 3},
			{2, 9},
		};

		var obj = new O025();
		for (int i = 0; i < testset1.length; i++) {
			var head1 = ListNode.generate(testset1[i]);
			var head2 = ListNode.generate(testset2[i]);
			ListNode.print(head1);
			ListNode.print(head2);

			var result = obj.algorithm(head1, head2);
			ListNode.print(result);
			System.out.println("=====================");
		}
	}
}

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
