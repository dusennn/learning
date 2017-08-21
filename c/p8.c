#include <stdio.h>

void main(){
	for(int f = 0; f <= 300; f+=20){
		printf("%d\t%.2f\n", f, (5.0/9.0) * (f - 32.0));
	}
}
