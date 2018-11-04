#include <stdio.h>
#include <stdlib.h>

#define FALSE -1
#define TRUE 1
#define OVERFLOW 0

typedef int Status;

Status fileToArray(int *data){
	FILE *f = fopen("data.txt", "r");
	char c;
	int cur = 0;
	while((c=fgetc(f))!=EOF){
		printf("%d\n", (int)c);

		if(cur==0){
			data = (int *)malloc(c * sizeof(int));
		}
	}

	fclose(f);
}

int main(){
	int *data;
	fileToArray(data);
	return 0;
}
