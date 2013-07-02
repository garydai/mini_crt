#include "minicrt.h"
//using namespace mini_crt;

char* mini_crt::itoa(int n, char* str, int radix)
{
	char ch[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char* head = str;

	if(radix > 36 || radix < 2 || !str)
		return str;

	if(radix != 10 && n < 0)
		return str;

	if(radix == 10 && n < 0)
	{
		*str++ = '-';
		n = -n;
	}
	if(n == 0)
	{
		*str = '0';
		*(str + 1) - '\0';
		return str;
	}
	int i = 0;

	while(n)
	{
		int idx = n % radix;
		*(str + i) = ch[idx];
		n /= radix;
		i ++;
	}
	*(str + i) = '\0';

	for(int j = 0; j < i / 2; j ++)
	{
		char temp = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = temp;
	}
	return head;
}

int mini_crt::strcmp(const char* src, const char* dst)
{
	while(*src != '\0' && *dst != '\0')
	{
		if(*src > *dst)
		{
			return 1;
		}
		else 
		{
			return -1;
		}
		src ++;
		dst ++;
	}
	if(*src == '\0' && *dst != '\0')
	{
		return -1;
	}
	else if(*dst == '\0' && *src != '\0')
	{
		return 1;
	}
	else if(*dst == '\0' && *src == '\0')
	{
		return 0;
	}

}

char* mini_crt::strcpy(char* dst, const char* src)
{
	while(*src)
	{
		*dst = *src;
		dst ++;
		src ++;
	}
	*dst = '\0';
	return dst;
}

unsigned mini_crt::strlen(const char* src)
{
	int i = 0;
	if(src == 0)
		return 0;
	if(*src == '\0')
		return 0;
	while(*src++)
	{
		i ++;
	}
	return i;
}