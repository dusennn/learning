#include <stdio.h>
#include <string.h>

void test(){
	
	struct Person{
		char name[50];
		int age;
	} person1, person2;

	strcat(person1.name, "XIo");
	person1.age = 18;

	strcat(person2.name, "dias");
	person2.age = 12;

	printf("Person1:%s\n", person1.name);
	printf("%d\n", person1.age);

	printf("Person2:%s\n", person2.name);
	printf("%d\n", person2.age);

}

struct School{
	char name [50]; 
	char area [50];
} school;

void print(struct School school){
	printf("School: name-> %s\n", school.name);
	printf("School: area-> %s\n", school.area);
}

void print2(struct School *school){
	printf("School: name-> %s\n", school->name);
	printf("School: area-> %s\n", school->area);
}

void test2(){
	strcat(school.name, "whv");
	strcat(school.area, "武汉");

	// print(school);
	print2(&school);
}

int main(){
	// test();
	// test2();
	struct Data
	{
		struct A
		{
			char name[10];
		} a;
		struct B
		{
			char name[20];
		} b;
		int id;
	} data;

	strcat(data.a.name, "test");
	
	printf("%s\n", data.a.name);
	printf("%d\n", data.id);

	return 0;
}
