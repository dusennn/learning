#include <stdio.h>

void fun(int a, int b, int c, int d){
	static int data[100];
	int i;
	if(d==b){
		printf("%d=", b);
		for(i=0; i<a; i++){
			if(i) printf("+");
			printf("%d", data[i]);
		}
		printf("\n");
	}
	for(i=c; i<=b; i++){
		if(i+d>b) break;
		data[a] = i;
		fun(a+1, b, i, d+i);
	}
}

int main(){

//	for(int i=0; i<10; i++){
//		printf("%d\n", i);	
//	}
	int n=3;
	fun(0, n, 1, 0);
	return 0;
}
