#include <stdio.h>

/*
	北工大2013 5.2(计算最长Huffman编码)
*/

#define MAX_SIZE 20

typedef struct{
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode, HuffmanTree[MAX_SIZE];

void init(HuffmanTree ht){
	ht[0].weight = 5;
	ht[0].parent = 9;
	ht[0].lchild = ht[0].rchild = 0;
	
	ht[1].weight = 29;
	ht[1].parent = 14;
	ht[1].lchild = ht[1].rchild = 0;
	
	ht[2].weight = 7;
	ht[2].parent = 10;
	ht[2].lchild = ht[2].rchild = 0;
	
	ht[3].weight = 8;
	ht[3].parent = 10;
	ht[3].lchild = ht[3].rchild = 0;
	
	ht[4].weight = 14;
	ht[4].parent = 12;
	ht[4].lchild = ht[4].rchild = 0;
	
	ht[5].weight = 23;
	ht[5].parent = 13;
	ht[5].lchild = ht[5].rchild = 0;
	
	ht[6].weight = 23;
	ht[6].parent = 13;
	ht[6].lchild = ht[6].rchild = 0;

	ht[7].weight = 3;
	ht[7].parent = 9;
	ht[7].lchild = ht[7].rchild = 0;

	ht[8].weight = 11;
	ht[8].parent = 11;
	ht[8].lchild = ht[8].rchild = 0;

	ht[9].weight = 8;
	ht[9].parent = 11;
	ht[9].lchild = 1;
	ht[9].rchild = 7;

	ht[10].weight = 15;
	ht[10].parent = 12;
	ht[10].lchild = 3;
	ht[10].rchild = 4;

	ht[11].weight = 19;
	ht[11].parent = 13;
	ht[11].lchild = 8;
	ht[11].rchild = 9;

	ht[12].weight = 29;
	ht[12].parent = 14;
	ht[12].lchild = 5;
	ht[12].rchild = 10;

	ht[13].weight = 42;
	ht[13].parent = 15;
	ht[13].lchild = 6;
	ht[13].rchild = 11;

	ht[14].weight = 58;
	ht[14].parent = 15;
	ht[14].lchild = 2;
	ht[14].rchild = 12;

	ht[15].weight = 100;
	ht[15].parent = 0;
	ht[15].lchild = 13;
	ht[15].rchild = 14;
}

int MaxLenHuffmanCode(HuffmanTree HT, int n){
	//max_len: 最长的Huffman 编码
	//cur_len: 记录当前节点的Huffman编码长度
	//parent: 父节点
	int max_len, cur_len, parent, i;
	max_len = 0;
	
	//循环所有子节点
	for(i=0; i<n; i++){
		cur_len = 0;
		parent = HT[i].parent;
		//通过当前子节点向上寻找父节点，直到没有父节点为止
		//每向上一层cur_len会加1
		while(parent != 0){
			cur_len++;
			parent = HT[parent].parent;
		}
		//如果当前子节点所记录的长度大于之前的，
		//那么就把当前的长度记录为最大值
		if(cur_len > max_len){
			max_len = cur_len;
		}
	}

	//最后返回最大长度
	return max_len;
}

int main(){
	HuffmanTree ht;
	init(ht);
	
	printf("Huffman Max Lenght:\n");
	int len = MaxLenHuffmanCode(ht, 8);
	printf("%d\n", len);
	return 0;
}
