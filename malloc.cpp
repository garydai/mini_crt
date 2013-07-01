#include "minicrt.h"
#include <Windows.h>;

static heap* head = NULL;
bool mini_crt_heap_init()
{
	void* base;
	int size = 32 * 1024 * 1024;
	base = VirtualAlloc(0, size, MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);
	if(base == NULL)
		return 0;


}