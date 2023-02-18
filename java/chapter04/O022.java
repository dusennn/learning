import java.util.*;

/**
 * 022: 链表中环的入口节点
 * ❌ 还存在bug
 */

class ListNode {
	public int val;
	public ListNode next;

	public ListNode(int _val) {
		this.val = _val;
	}

	// 初始化一个带环的链表，入口节点为 k
	public static ListNode generate(int[] data, int k) {
		ListNode dummy = new ListNode(0);

		ListNode newNode = dummy;
		ListNode enterNode = null;
		for (int i = 0; i < data.length; i++) {
			var node = new ListNode(data[i]);
			newNode.next = node;
			newNode = node;
			if (i == k-1) {
				enterNode = node;
			}
		}
		newNode.next = enterNode; //连接环
		return dummy.next;
	}
}

public class O022 {

	/**
	 * 1. 根据双指针，使用快慢指针判断是否有环
	 * 2. 慢指针 p1 每次走一步，快指针 p2 每次走两步
	 * 如果 p2.next 为空，说明没有环。
	 * 如果 p2 与 p1 相遇，说明存在环，而且 p1 p2 在一个环上
	 * 3. 令 p2 暂停，p1 继续前进，并记录走的步数。
	 * 当 p1 p2 再次相遇，这个步数即为环的长度 n。
	 * 4. 令 p1 p2 重新指向表头，先让 p2 走 n 步，然后 p1 p2 开始每次走一步。
	 * 当 p1 p2 相遇，相遇点，即为环的入口处。
	 */
	public ListNode algorithm(ListNode head) {
		if (head == null) return null;

		// 判断是否有环
		ListNode p1 = head;
		ListNode p2 = head.next;
		while (p1 == p2 && p2 != null) {
			p1 = p1.next;
			p2 = p2.next;
			if (p2 != null) {
				p2 = p2.next;
			}
		}
		if (p1 == null && p2 == null) return null; //有环
		
		System.out.println(p1);
		System.out.println(p2);
		// 得到环的长度
		int n = 1;
		p1 = p1.next;
		while (p1 != p2) {
			p1 = p1.next;
			n++;
		}

		// 得到环的入口
		p1 = head;
		p2 = head;
		for (int i = 0; i < n; i++) {
			p2 = p2.next;
		}
		while (p1 != p2) {
			p1 = p1.next;
			p2 = p2.next;
		}
		return p1;
	}

	public static void main(String[] args) {
		int[][] testset = {
			// {1, 2, 3, 4, 5, 6, 7},
			{1},
		};
		int[] targets = {
			// 3,
			-1
		};

		var obj = new O022();
		for (int i = 0; i < testset.length; i++) {
			var target = targets[i];
			var head = ListNode.generate(testset[i], target);

			var result = obj.algorithm(head);
			System.out.printf("Target: %d, Result:%d\n", target, result == null ? -1:result.val);
			System.out.println("=====================");
		}
	}
}
