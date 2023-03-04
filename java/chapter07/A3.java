import java.util.*;

/**
 * 7.3 二叉树的遍历
 */

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;

	public TreeNode(int _val) {
		this.val = _val;
	}

	/**
	 * 	  0
	 * 	1 	2
	 * 3 4 5 6
	 */
	public static TreeNode create() {
		TreeNode root = new TreeNode(0);
		root.left = new TreeNode(1);
		root.right = new TreeNode(2);

		root.left.left = new TreeNode(3);
		root.left.right = new TreeNode(4);

		root.right.left = new TreeNode(5);
		root.right.right = new TreeNode(6);

		return root;
	}

	/**
	 * 广度优先遍历
	 */
	public static List<Integer> bfs(TreeNode root) {
		Queue<TreeNode> queue = new LinkedList<>();
		if (root != null) {
			queue.offer(root);
		}

		List<Integer> nodes = new ArrayList<>();
		while (!queue.isEmpty()) {
			var node = queue.poll();
			nodes.add(node.val);

			if (node.left != null) {
				queue.offer(node.left);
			}

			if (node.right != null) {
				queue.offer(node.right);
			}
		}

		return nodes;
	}

	/**
	 * 先序遍历
	 */
	public static List<Integer> preOrderTraversal(TreeNode root) {
		List<Integer> nodes = new ArrayList<>();
		preOrderDfs(root, nodes);
		return nodes;
	}
	private static void preOrderDfs(TreeNode root, List<Integer> nodes) {
		if (root == null) return;

		nodes.add(root.val);
		preOrderDfs(root.left, nodes);
		preOrderDfs(root.right, nodes);
	}

	/**
	 * 先序遍历（非递归）
	 * 1. 先序规则：先根节点，然后左子树，最后右子树
	 * 2. 使用栈来存放节点，使用游标记录探测位置
	 * 	第一步：令游标指向根节点
	 * 	第二步：从游标开始，不断循环探测左子树，把经过的节点放入栈中保存
	 * 	第三步：从栈中pop节点，把游标指向节点的右子树，继续第二、三步操作
	 */
	public static List<Integer> preOrderTraversalLoop(TreeNode root) {
		List<Integer> nodes = new ArrayList<>();
		Stack<TreeNode> stack = new Stack<>();
		var cur = root;
		while (cur != null || !stack.isEmpty()) {
			while (cur != null) {
				nodes.add(cur.val);
				stack.push(cur);
				cur = cur.left;
			}

			cur = stack.pop();
			cur = cur.right;
		}

		return nodes;
	}

	/**
	 * 中序遍历
	 */
	public static List<Integer> midOrderTraversal(TreeNode root) {
		List<Integer> nodes = new ArrayList<>();
		midOrderDfs(root, nodes);
		return nodes;
	}
	private static void midOrderDfs(TreeNode root, List<Integer> nodes) {
		if (root == null) return;

		midOrderDfs(root.left, nodes);
		nodes.add(root.val);
		midOrderDfs(root.right, nodes);
	}

	/**
	 * 中序遍历（非递归）
	 * 1. 中序遍历原理：先左子树，然后根节点，最后右子树
	 * 2. 使用栈存放待使用的节点，使用游标记录探测位置
	 * 	第一步：令游标指向树根
	 * 	第二步：游标不断往节点的左子树移动，栈记录游标经过的节点
	 * 	第三步：当左子树为空，栈pop元素，保存栈顶元素信息。
	 * 	第四步：指针指向栈顶元素的右子树，继续第二、三、四步循环。
	 */
	public static List<Integer> midOrderTraversalLoop(TreeNode root) {
		List<Integer> nodes = new ArrayList<>();
		Stack<TreeNode> stack = new Stack<>();
		var cur = root;
		while (cur != null || !stack.isEmpty()) {
			while (cur != null) {
				stack.push(cur);
				cur = cur.left;
			}

			cur = stack.pop();
			nodes.add(cur.val);
			cur = cur.right;
		}

		return nodes;
	}

	/**
	 * 后序遍历
	 */
	public static List<Integer> subOrderTraversal(TreeNode root) {
		List<Integer> nodes = new ArrayList<>();
		subOrderDfs(root, nodes);
		return nodes;
	}
	private static void subOrderDfs(TreeNode root, List<Integer> nodes) {
		if (root == null) return;

		subOrderDfs(root.left, nodes);
		subOrderDfs(root.right, nodes);
		nodes.add(root.val);
	}

	/**
	 * 后序遍历（非递归）
	 * 1. 后序遍历原理：先左子树，然后右子树，最后根节点。
	 * 2. 使用栈保存待使用的节点，使用游标进行探测，并且记录上一次的探测节点
	 * 	第一步：游标指向根节点
	 * 	第二步：游标不断探测节点的左子树，记录经过的节点到栈中，直到左子树为空
	 * 	第三步：判断栈顶节点是否存在右子树，
	 * 		如果存在，游标开始探测节点的右子树，上一次的探测节点设为栈顶元素，记录经过的节点到栈中，直到右子树为空
	 * 		如果不存在，栈pop元素，把栈顶元素赋值给游标
	 */
	public static List<Integer> subOrderTraversalLoop(TreeNode root) {
		List<Integer> nodes = new ArrayList<>();
		Stack<TreeNode> stack = new Stack<>();
		var cur = root;
		TreeNode prev = null;
		while (cur != null || !stack.isEmpty()) {
			while (cur != null) {
				stack.push(cur);
				cur = cur.left;
			}

			cur = stack.peek();
			if (cur.right != null && cur.right != prev) {
				cur = cur.right;
			} else {
				cur = stack.pop();
				nodes.add(cur.val);
				prev = cur;
				cur = null;
			}
		}

		return nodes;
	}
}

public class A3 {

	public static void main(String[] args) {
		TreeNode root = TreeNode.create();
		
		var result = TreeNode.bfs(root);
		System.out.printf("广度优先遍历：%s\n", result);

		result = TreeNode.preOrderTraversal(root);
		System.out.printf("先序遍历：%s\n", result);
		result = TreeNode.preOrderTraversalLoop(root);
		System.out.printf("先序遍历(非递归)：%s\n", result);

		result = TreeNode.midOrderTraversal(root);
		System.out.printf("中序遍历：%s\n", result);
		result = TreeNode.midOrderTraversalLoop(root);
		System.out.printf("中序遍历(非递归)：%s\n", result);

		result = TreeNode.subOrderTraversal(root);
		System.out.printf("后序遍历：%s\n", result);
		result = TreeNode.subOrderTraversalLoop(root);
		System.out.printf("后序遍历(非递归)：%s\n", result);
	}
}
