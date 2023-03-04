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
	public static void preOrder(TreeNode root) {
		if (root == null) return;

		System.out.printf("%d\t", root.val);
		preOrder(root.left);
		preOrder(root.right);
	}

	/**
	 * 中序遍历
	 */
	public static void midOrder(TreeNode root) {
		if (root == null) return;

		midOrder(root.left);
		System.out.printf("%d\t", root.val);
		midOrder(root.right);
	}

	/**
	 * 后序遍历
	 */
	public static void subOrder(TreeNode root) {
		if (root == null) return;

		subOrder(root.left);
		subOrder(root.right);
		System.out.printf("%d\t", root.val);
	}
}

public class A3 {

	public static void main(String[] args) {
		TreeNode root = TreeNode.create();

		System.out.println("\n二叉树先序遍历：");
		TreeNode.preOrder(root);

		System.out.println("\n二叉树中序遍历：");
		TreeNode.midOrder(root);

		System.out.println("\n二叉树后序遍历：");
		TreeNode.subOrder(root);
	}
}
