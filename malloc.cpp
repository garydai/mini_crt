#include "minicrt.h"
#include <Windows.h>;
enum
{
	HEAP_BLOCK_FREE = 0xA,
	HEAP_BLOCK_USED = 0xB,
};

typedef struct _heap
{
	int type;
	unsigned size; //内存大小，包括heap头
	_heap* next;
	_heap* prev;
}heap;

static heap* heap_head = NULL;

#define HEAD_SIZE sizeof(heap)
#define ADDR_ADD(a, s) ((char*)(a) + s)

void* malloc(unsigned size)
{
	if(heap_head == NULL)
	{
		return NULL;
	}
	heap* iter = heap_head;
	while(!iter)
	{
		if(iter->type == HEAP_BLOCK_FREE)
		{
			if(iter->size > size + HEAD_SIZE)
			{
				heap* prev = iter->prev;
				heap* next = iter->next;
				heap* ret = iter;

				heap* temp = (heap*)ADDR_ADD(iter, size + HEAD_SIZE);
				temp->type = HEAP_BLOCK_FREE;
				temp->prev = iter;
				temp->next = iter->next;
				temp->size = iter->size - size;

				iter->next = temp;
				iter->size = size;	
				iter->type = HEAP_BLOCK_USED;
				return iter;

			}
			else if(iter->size == size)
			{
				iter->type = HEAP_BLOCK_USED;
				return iter;
			}
		}
		
	}

}

bool mini_crt_heap_init()
{
	void* base;
	int size = 32 * 1024 * 1024;
	base = VirtualAlloc(0, size, MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);
	if(base == NULL)
		return false;
	heap_head = (heap*)base;
	heap_head->type = HEAP_BLOCK_FREE;
	heap_head->size = size;
	heap_head->next = NULL;
	heap_head->prev = NULL;
	return true;
}