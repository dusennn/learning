import java.util.*;

/**
 * 21. 合并两个有序链表
 */

public class T021 {
	
	/**
	 * 1. 定义指针 p1 指向 list1 开头，p2 指向 list2 开头，p3 指向新 ListNode 头节点
	 * 2. p1、p2 不断往右移动，每次移动比对 p1 和 p2 的val
	 * 如果 p1.val < p2.val，令 p3.next = p1.val, p3 = p3.next
	 * 如果 p1.val >= p2.val, 令 p3.next = p2.val, p3 = p3.next
	 * 3. 待循环结束
	 * 如果 p1 为 null，令 p3.next = p2
	 * 如果 p2 为 null，令 p3.next = p1
	 * 4. 返回新ListNode
	 */
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
    	ListNode dummy = new ListNode(0);
    	var p3 = dummy;
    	
    	var p1 = list1;
    	var p2 = list2;
    	while (p1 != null && p2 != null) {
    		if (p1.val > p2.val) {
    			p3.next = p2;
    			p2 = p2.next;
    		} else {
    			p3.next = p1;
    			p1 = p1.next;
    		}
			p3 = p3.next;
    	}

    	if (p1 != null) {
    		p3.next = p1;
    	}
    	if (p2 != null) {
    		p3.next = p2;
    	}
    	return dummy.next;
    }
}
