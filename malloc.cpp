#include "minicrt.h"
namespace mini_crt
{

static heap* heap_head = NULL;

#define HEAD_SIZE sizeof(heap)
#define ADDR_ADD(a, s) ((char*)(a) + s)

void* mini_crt::malloc(int size)
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
			else if(iter->size == size + HEAD_SIZE)
			{
				iter->type = HEAP_BLOCK_USED;
				return iter;
			}
		}
		
	}
	return NULL;

}

void free(heap* base)
{
	if(base->next && base->next->type == HEAP_BLOCK_FREE)
	{
		heap* next = base->next;
		base->size += next->size;
		base->next = next->next;
		next->next->prev = base;

	}
	if(base->prev && base->prev->type == HEAP_BLOCK_FREE)
	{
		heap* prev = base->prev;
		prev->size += base->size;
		prev->next = base->next;
		if(base->next != NULL)
		{
			base->next->prev = prev;
		}

		base = prev;
	}
	base->type = HEAP_BLOCK_FREE;
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
}