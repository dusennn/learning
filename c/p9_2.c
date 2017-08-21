#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

void main(){
	for(int f = LOWER; f <= UPPER; f+=STEP){
		printf("%d\t%.2f\n", f, (5.0/9.0)*(f-32.0));
	}
}
