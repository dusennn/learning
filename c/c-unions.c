#include <stdio.h>
#include <string.h>

union Data {
	int id;
	char str[5];
};

int main(){
	union Data data;
	
	// data.id = 1000000;
	strcat(data.str, "测试一下。");

	printf("%d\n", data.id);
}