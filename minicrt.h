#ifndef _mini_crt_h_
#define _mini_crt_h_
#include <windows.h>

extern "C"
{


namespace mini_crt
{

typedef int FILE;

#define NULL 0
void mini_crt_entry(void);



///////////////////////////////////////////////////////////
bool mini_crt_io_init();
FILE* fopen(const char* filename, const char* mode);
int fclose(FILE* f);
int fread(void* buffer, int size, int count, FILE* stream);
int fwrite(void* buffer, int size, int count, FILE* stream);
int fseek(FILE* fp, int offset, int set);
#define EOF (-1)
#define stdin ((FILE*)(GetStdHandle(STD_INPUT_HANDLE)))
#define stdout ((FILE*)(GetStdHandle(STD_OUTPUT_HANDLE)))
#define stderr ((FILE*)(GetStdHandle(STD_ERROR_HANDLE)))


////////////////////////////////////////////////////////////
enum
{
	HEAP_BLOCK_FREE = 0xA,
	HEAP_BLOCK_USED = 0xB,
};

typedef struct _heap
{
	int type;
	int size; //内存大小，包括heap头
	_heap* next;
	_heap* prev;
}heap;
bool mini_crt_heap_init();
void* malloc(int size);
void free(heap* base);

/////////////////////////////////////////////////////

char* itoa(int n, char* str, int radix);
int strcmp(const char* src, const char* dst);
char* strcpy(char* dst, const char* src);
unsigned strlen(const char* src);

/////////////////////////////////////////////////////
#define va_list char*
#define va_start(ap, arg) (ap = (va_list)((char*)(&format) + sizeof(format)))
#define va_arg(ap, t) ( *(t*)((ap += sizeof(t)) - sizeof(t)) )
#define va_end(ap) (ap = (va_list)0)

int fputc(int ch, FILE* stream);
int fputs(const char* s, FILE* stream);
int fprintf(FILE* stream, const char* format, ...);
int printf(const char* format, ...);
int vfprintf(FILE* stream, const char* format, va_list list);
};
};
#endif