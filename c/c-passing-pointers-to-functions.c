#include <stdio.h>
#include <time.h>

void modifiedValues(int *num){
	*num = 5;
}

void waitSec(long sec){
	long nTime = time(0) + sec;
	while(time(0) < nTime);
}

long getSecond(long *l){
	waitSec(5);
	*l = time(NULL);
}

int main(){
	int num = 3;
	printf("%d\n", num);

	modifiedValues(&num);
	printf("%d\n", num);

	printf("%s\n", "------------------------------------------");

	long l = time(NULL);
	printf("%ld\n", l);

	getSecond(&l);
	printf("%ld\n", l);

}
