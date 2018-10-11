#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define OVERFLOW 0
#define NULL_VALUE -32768
#define HASH_SIZE 20

typedef int ElemType;
typedef int Status;

typedef struct {
	ElemType *data;
	int count; //已用空间
	int size; //总空间
}HashTable;

Status init(HashTable *h){
	h->count = 0;
	h->size = HASH_SIZE;
	h->data = (int *)malloc(HASH_SIZE * sizeof(int));
	if(!h->data) exit(OVERFLOW);

	for(int i=0; i<HASH_SIZE; i++){
		h->data[i] = NULL_VALUE;
	}
	return OK;
}

// division method
int hash(int key){
	return key % HASH_SIZE;
}

Status insert(HashTable *h, int key){
	//满了
	if(h->count == h->size) return ERROR;

	int addr;
	addr = key % HASH_SIZE;
	while(h->data[addr] != NULL_VALUE){
		addr = (addr + 1) % HASH_SIZE;
	}
	h->count++;
	h->data[addr] = key;

	return OK;
}

Status search(HashTable h, int key, int *addr){
	//空的
	if(!h.count) return ERROR;
	
	*addr = key % HASH_SIZE;
	while(h.data[*addr] != key){
		*addr = (*addr + 1) % HASH_SIZE;
		if(h.data[*addr] == NULL_VALUE || *addr == key % HASH_SIZE) return ERROR;
	}

	return OK;
}

Status create(HashTable *h){
	int data[10] = {12, 23, 13, 234, 3, 24, 5, 4, 3, 9};
	for(int i=0; i<10; i++){
		insert(h, data[i]);
	}
	return OK;
}

void print(HashTable h){
	printf("========== HASH: Division method ==========\n");
	for(int i=0; i<h.size; i++){
		printf("Addr:%d, Data:%d\n", i, h.data[i]);
	}
}

int main(){
	HashTable h;
	init(&h);
	create(&h);
	print(h);
	
	insert(&h, 132);
	print(h);

	int addr;
	Status s;
	s = search(h, 13, &addr);
	printf("Status:%d, Addr:%d\n", s, addr);

	s = search(h, 2, &addr);
	printf("Status:%d, Addr:%d\n",s, addr);
	return 0;
}
