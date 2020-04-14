#include <stdio.h>


void c()
{
	printf("C\n");
	void* p = NULL;
	printf("C stack - %p\n", (void*)&p);
	__asm {
		mov esp, ebp
		pop ebp
		retn
	};
}


void b()
{
	printf("B\n");
	c();
	void* p = NULL;
	printf("B stack - %p\n", (void*)&p);
	__asm {
		mov esp, ebp
		pop ebp
		retn
	};
}


void a()
{
	printf("A\n");
	b();
	void* p = NULL;
	printf("A stack - %p\n", (void*)&p);
}


int main()
{
	a();
	system("PAUSE");
	return 0;
}