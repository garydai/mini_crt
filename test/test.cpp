#include "minicrt.h"
#include <Windows.h>
using namespace mini_crt;
//#include "stdio.h"
//#include "stdlib.h"

// char* itoa(int n, char* str, int radix)
// {
// 	char ch[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// 	char* head = str;
// 
// 	if(radix > 36 || radix < 2 || !str)
// 		return str;
// 
// 	if(radix != 10 && n < 0)
// 		return str;
// 
// 	if(radix == 10 && n < 0)
// 	{
// 		*str++ = '-';
// 		n = -n;
// 	}
// 	if(n == 0)
// 	{
// 		*str = '0';
// 		*(str + 1) - '\0';
// 		return str;
// 	}
// 	int i = 0;
// 
// 	while(n)
// 	{
// 		int idx = n % radix;
// 		*(str + i) = ch[idx];
// 		n /= radix;
// 		i ++;
// 	}
// 	*(str + i) = '\0';
// 
// 	for(int j = 0; j < i / 2; j ++)
// 	{
// 		char temp = str[j];
// 		str[j] = str[i - j - 1];
// 		str[i - j - 1] = temp;
// 	}
// 	return head;
// }
// 
// int strcmp(const char* src, const char* dst)
// {
// 	while(*src != '\0' && *dst != '\0')
// 	{
// 		if(*src > *dst)
// 		{
// 			return 1;
// 		}
// 		else 
// 		{
// 			return -1;
// 		}
// 		src ++;
// 		dst ++;
// 	}
// 	if(*src == '\0' && *dst != '\0')
// 	{
// 		return -1;
// 	}
// 	else if(*dst == '\0' && *src != '\0')
// 	{
// 		return 1;
// 	}
// 	else if(*dst == '\0' && *src == '\0')
// 	{
// 		return 0;
// 	}
// 
// }
// 
// char* strcpy(char* dst, const char* src)
// {
// 	while(*src)
// 	{
// 		*dst = *src;
// 		dst ++;
// 		src ++;
// 	}
// 	*dst = '\0';
// 	return dst;
// }
// 
// unsigned strlen(const char* src)
// {
// 	int i = 0;
// 	if(src == 0)
// 		return 0;
// 	if(*src == '\0')
// 		return 0;
// 	while(*src++)
// 	{
// 		i ++;
// 	}
// 	return i;
// }
// 
// #define va_list char*
// #define va_start(ap, arg) (ap = (va_list)((char*)(&format) + sizeof(format)))
// #define va_arg(ap, t) ( *(t*)((ap += sizeof(t)) - sizeof(t)) )
// #define va_end(ap) (ap = (va_list)0)
// 
// #define stdin ((FILE*)(GetStdHandle(STD_INPUT_HANDLE)))
// #define stdout ((FILE*)(GetStdHandle(STD_OUTPUT_HANDLE)))
// #define stderr ((FILE*)(GetStdHandle(STD_ERROR_HANDLE)))
// #define FILE int
// //using namespace mini_crt;
// int fwrite(void* buffer, int size, int count, FILE* stream)
// {
// 	DWORD write = 0;
// 	if(!WriteFile((HANDLE)stream, buffer, size * count, &write, 0))
// 		return 0;
// 	return write;
// }
// 
// int fputc(int ch, FILE* stream)
// {
// 	if(fwrite(&ch, 1, 1, stream) != 1)
// 	{
// 		return -1;
// 	}
// 	else
// 	{
// 		return ch;
// 	}
// 
// }
// 
// int fputs(const char* s, FILE* stream)
// {
// 	int len = strlen(s);
// 	if(fwrite((void*)s, len, 1, stream) != len)
// 	{
// 		return -1;
// 	}
// 	else
// 	{
// 		return len;
// 	}
// }
// 
// int vfprintf(FILE* stream, const char* format, va_list list)
// {
// 	bool pre = 0;
// 	int ret = 0;
// 	while(*format)
// 	{
// 	//	fputc(*format, stream);
// 		if(*format == '%')
// 		{
// 			if(!pre)
// 			{
// 				pre = true;
// 			}
// 			else
// 			{
// 				if(fputc(*format, stream) == -1)
// 				{
// 					return -1;
// 				}
// 				ret ++;
// 
// 				pre = false;
// 			}
// 		}
// 		else if(*format == 'd')
// 		{
// 			if(pre)
// 			{
// 				char buf[11];
// 				itoa(va_arg(list, int), buf, 10);
// 				if(fputs(buf, stream) == -1)
// 				{
// 					return -1;
// 				}
// 				ret += strlen(buf);
// 				pre = false;
// 
// 				
// 			}
// 			else
// 			{
// 				if(fputc('d', stream) == -1)
// 				{
// 					return -1;
// 				}
// 				ret ++;
// 				pre = false;
// 			}
// 
// 		}
// 		else
// 		{
// 			if(fputc(*format, stream) == -1)
// 			{
// 				return -1;
// 			}
// 			ret ++;
// 			pre = false;
// 		}
// /*
// 		else if(*format == 's')
// 		{
// 			if(pre)
// 			{
// 				const char* str = va_arg(list, const char*);
// 				if(fputs(str, stream) == -1)
// 				{
// 					return -1;
// 				}
// 				ret += strlen(str);
// 				format ++;
// 				pre = false;
// 
// 
// 			}
// 			else
// 			{
// 				if(fputc('s', stream) == -1)
// 				{
// 					return -1;
// 				}
// 				ret ++;
// 				format ++;
// 				pre = false;
// 			}
// 		}
// 		*/
// 		format ++;
// 	}
// }
// 
// int printf(const char* format, ...)
// {
// 	va_list(arglist);
// 	va_start(arglist, format);
// 	int a = sizeof(format);
// 	int b = (int)&format;
// 	b = a + b;
// 	char *c = (va_list)((char*)(&format) + sizeof(format));
// 	int d = sizeof(char*);
// 	return vfprintf(stdout, format, arglist);
// 
// }
// int fprintf(FILE* stream, const char* format, ...)
// {
// 	va_list(arglist);
// 	va_start(arglist, format);
// 	return vfprintf(stream, format, arglist);
// }

int main(int argc, char* argv[])
{
	printf("%d %d", 1, 2);
}