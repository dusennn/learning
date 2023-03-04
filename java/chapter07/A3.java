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
}

public class A3 {

	public static void main(String[] args) {
		TreeNode root = TreeNode.create();

		var result = TreeNode.preOrderTraversal(root);
		System.out.printf("二叉树先序遍历：%s\n", result);

		result = TreeNode.midOrderTraversal(root);
		System.out.printf("二叉树中序遍历：%s\n", result);

		result = TreeNode.subOrderTraversal(root);
		System.out.printf("二叉树后序遍历：%s\n", result);
	}
}
