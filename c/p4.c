#include <stdio.h>

#define STEP 20

void main()
{
	float celsius;
	int lower, upper;
	upper = 300;
	lower = 0;

	printf("华氏温度-摄氏温度对照表\n");

	while(lower <= upper){
		celsius = (5.0/9.0) * (lower - 32.0);
		printf("%d\t%f\n",lower,celsius);
		lower = lower + STEP;
	}	
}
