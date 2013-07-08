#include "minicrt.h"
namespace mini_crt
{



int fputc(int ch, FILE* stream)
{
	if(fwrite(&ch, 1, 1, stream) != 1)
	{
		return -1;
	}
	else
	{
		return ch;
	}

}

int fputs(const char* s, FILE* stream)
{
	int len = strlen(s);
	if(fwrite((void*)s, len, 1, stream) != len)
	{
		return -1;
	}
	else
	{
		return len;
	}
}

int vfprintf(FILE* stream, const char* format, va_list list)
{
	bool pre = 0;
	int ret = 0;
	while(*format)
	{
		//mini_crt::fputc(*format, stream);
		if(*format == '%')
		{
			if(!pre)
			{
				pre = true;
			}
			else
			{
				if(mini_crt::fputc(*format, stream) == -1)
				{
					return -1;
				}
				ret ++;

				pre = false;
			}
		}
		else if(*format == 'd')
		{
			if(pre)
			{
				char buf[11];
				mini_crt::itoa(va_arg(list, int), buf, 10);
				if(mini_crt::fputs(buf, stream) == -1)
				{
					return -1;
				}
				ret += strlen(buf);
				pre = false;

				
			}
			else
			{
				if(mini_crt::fputc('d', stream) == -1)
				{
					return -1;
				}
				ret ++;
				pre = false;
			}

		}
		else
		{
			if(mini_crt::fputc(*format, stream) == -1)
			{
				return -1;
			}
			ret ++;
			pre = false;
		}
/*
		else if(*format == 's')
		{
			if(pre)
			{
				const char* str = va_arg(list, const char*);
				if(fputs(str, stream) == -1)
				{
					return -1;
				}
				ret += strlen(str);
				format ++;
				pre = false;


			}
			else
			{
				if(fputc('s', stream) == -1)
				{
					return -1;
				}
				ret ++;
				format ++;
				pre = false;
			}
		}
		*/
		format ++;
	}
}

int printf(const char* format, ...)
{
	va_list(arglist);
	va_start(arglist, format);
	return vfprintf(stdout, format, arglist);

}
int fprintf(FILE* stream, const char* format, ...)
{
	va_list(arglist);
	va_start(arglist, format);
	return vfprintf(stream, format, arglist);

}
}