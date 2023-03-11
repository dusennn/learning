import java.util.*;

/**
 * Top面试题 002: 两数之和
 */
public class T002 {
	public static void main(String[] args) {
		int[][] testset = {
			{2,4,9},
			{5,6,4,9},
		};

		var obj = new T002();
		var l1 = ListNode.generate(testset[0]);
		ListNode.print(l1);
		var l2 = ListNode.generate(testset[1]);
		ListNode.print(l2);
		var result = obj.addTwoNumbers(l1, l2);
		ListNode.print(result);
	}

	/**
    1. 依次对两个列表的元素执行相加操作（注意：满10进1）
    2. 把相加的结果放到新的列表中（注意：使用dummy节点指向新列表头，可以简化操作）
    */
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        var tail = dummy;

        l1 = reverse(l1);
        l2 = reverse(l2);
        int sum = 0;
        while (l1 != null || l2 != null) {
        	if (l1 != null) {
        		sum += l1.val;
        		l1 = l1.next;
        	}
        	if (l2 != null) {
        		sum += l2.val;
        		l2 = l2.next;
        	}

            var val = sum % 10;
            var node = new ListNode(val);
            tail.next = node;
            tail = node;
            sum = sum / 10;
        }

        if (sum > 0) {
            tail.next = new ListNode(sum % 10);
        }

        return dummy.next;
    }
}

class ListNode {
	public int val;
	public ListNode next;

	public ListNode(int _val) {
		this.val = _val;
		this.next = null;
	}

	public static ListNode generate(int[] nums) {
		ListNode dummy = new ListNode(0);
		var head = dummy;

		for (int num: nums) {
			var node = new ListNode(num);
			head.next = node;
			head = node;
		}

		return dummy.next;
	}

	public static void print(ListNode head) {
		if (head == null) {
			System.out.println("[]");
			return;
		}

		System.out.printf("[");
		var node = head;
		while (node != null) {
			System.out.printf("%d -> ", node.val);
			node = node.next;
		}
		System.out.println("]");
	}
}
