#include <stdio.h>

typedef struct
{
	double a;
	int b;
	char c[2];
	void *p;
	int e[0];
//	float f[0];
}funky;

typedef struct
{
	char *name;
	int refcount : 4;
	unsigned dirty : 1;
}funky2;

int main()
{
	int i = 3;

/*	printf("Value: %d\n", i++ * i++);*/	
//	i = i++;
	i = 7;
	printf("Value: %d\n", i++ * (i++));
	printf("i: %d\n",i);
//	funky2 f;
//	printf("Name: %d\n",sizeof(f.name));
//	printf("Refcount: %d\n",sizeof(f.refcount));
//	printf("Dirty: %d\n",sizeof(f.dirty));
/*	funky f;

	printf("A: %d\n",sizeof(f.a));
	printf("B: %d\n",sizeof(f.b));
	printf("C: %d\n",sizeof(f.c));
	printf("P: %d\n",sizeof(f.p));
	printf("E: %d\n",sizeof(f.e));
//	printf("F: %d\n",sizeof(f.f));
*/
//	printf("Size: %d\n",sizeof(f));
}
