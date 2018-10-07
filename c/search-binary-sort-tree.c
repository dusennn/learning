#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define OVERFLOW 0

typedef int Status;
typedef int ElemType;

typedef struct TNode{
	ElemType data;
	struct TNode *lchild, *rchild;
}TNode, *BinTree;

Status init(BinTree *tree){
	(*tree) = (TNode *)malloc(sizeof(TNode));
	if(!(*tree)) exit(OVERFLOW);

	(*tree)->lchild = (*tree)->rchild = NULL;

	return OK;
}

Status find(BinTree tree, ElemType key){
	if(tree){
		if(key == tree->data){
			return OK;
		}else if(key < tree->data){
			find(tree->lchild, key);
		}else{
			find(tree->rchild, key);
		}
	}
}

Status insert(BinTree tree, ElemType e){
	if(!tree->data){
		tree->data = e;
		return OK;
	}

	if(find(tree, e)){
		return OK;
	}

	if(e < tree->data){
		if(tree->lchild){
			insert(tree->lchild, e);   
		}else{
			TNode *node = (TNode *)malloc(sizeof(TNode));
			node->data = e;
			node->lchild = node->rchild = NULL;
			tree->lchild = node;
			return OK;
		}
	}else{
		if(tree->rchild){
			insert(tree->rchild, e);
		}else{
			TNode *node = (TNode *)malloc(sizeof(TNode));
			node->data = e;
			node->lchild = node->rchild = NULL;
			tree->rchild = node;
			return OK;
		}
	}
}

Status delete(BinTree tree, BinTree pre, ElemType key){
	if(!tree) return ERROR;
	if(!find(tree, key)) return ERROR;

	if(tree->data == key){
		//情况1：要删除节点为叶子结点
		if(!tree->lchild && !tree->rchild){
			if(pre->lchild == tree){
				pre->lchild = NULL;
				return OK;
			}
			if(pre->rchild == tree){
				pre->rchild = NULL;
				return OK;
			}

		//情况2：要删除节点既有左子树又有右子树
		}else if(tree->lchild && tree->rchild){
			//方法1：寻找左子树上与当前值最接近的节点，
			//把找到的节点的值替换到该节点，并删除找到
			//的节点
			TNode *temp1 = tree->lchild;
			if(temp1->rchild){
				if(temp1->rchild->rchild){
					TNode *temp2 = temp1;
					while(temp2->rchild->rchild){
						temp2 = temp2->rchild;
					}
					tree->data = temp2->rchild->rchild->data;
					temp2->rchild->rchild = NULL;
				}else{
					tree->data = temp1->rchild->data;
					temp1->rchild = NULL;
				}
			}else{
				tree->data = temp1->data;
				if(temp1->lchild){
					tree->lchild = temp1->lchild;
				}else{
					tree->lchild = NULL;
				}
			}
			//方法2：寻找右子树上...
			//...
			return OK;

		//情况3：要删除节点只有左子树
		}else if(tree->lchild){
			if(pre->lchild == tree){
				pre->lchild = pre->lchild->lchild;
			}
			if(pre->rchild == tree){
				pre->rchild = pre->rchild->lchild;
			}
			return OK;

		//情况4：要删除节点只有右子树
		}else{
			if(pre->lchild == tree){
				pre->lchild = pre->lchild->rchild;
			}
			if(pre->rchild == tree){
				pre->rchild = pre->rchild->rchild;
			}
			return OK;
		}
	}else if(key < tree->data){
		pre = tree;
		delete(tree->lchild, pre, key);
	}else{
		pre = tree;
		delete(tree->rchild, pre, key);
	}
}

Status createBinSortTree(BinTree tree, int *data, int index){
	for(int i=index; i<=data[0]; i++){
		insert(tree, data[i]);
	}
	return OK;
}

//midorder traversal
Status midTraversal(BinTree tree){
	if(tree){
		midTraversal(tree->lchild); 
		printf("%d->", tree->data);
		midTraversal(tree->rchild); 
	}
	return OK;
}

void print(BinTree tree){
	printf("Midorder Traversal:\n");
	midTraversal(tree);
	printf("\n");
}

int main(){
	BinTree tree;
	init(&tree);

	int len = 9;
	int data[10] = {len, 70, 105, 115, 104, 67, 46, 99, 111, 109};

	int index = 1;
	createBinSortTree(tree, data, index);
	print(tree);

	Status s;
	ElemType e = 67;
	s = find(tree, e); 
	printf("Status(find):%d\n", s);

	s = insert(tree, 110);
	printf("Status(insert):%d\n", s);
	print(tree);

	s = delete(tree, tree, 70);
	printf("Status(delete):%d\n", s);
	print(tree);	

	return 0;
}
