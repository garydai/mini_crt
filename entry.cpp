#include "minicrt.h"

using namespace mini_crt;

extern int main(int argc, char* argv[]);

void mini_exit(int exit_code)
{
	ExitProcess(exit_code);
}

void mini_crt::mini_crt_entry(void)
{
	int ret;
	char* argv[16];//最多16个参数
	char* cl = GetCommandLineA();

	int arvc = 0;
	//解析命令行
	argv[0] = cl;
	arvc ++;
	bool flag = false;
	while(*cl)
	{
		if(*cl == '\"' && !flag)
		{
			flag = true;
		}
		else if(*cl == '\"' && flag)
		{
			flag = false;
		}
		else if(*cl == ' ' && !flag)
		{
			if(*(cl + 1))
			{
				argv[arvc++] = cl;
			}
			*cl = '\0';
		}
		cl ++;
	}

	if(!mini_crt_heap_init())
	{

	}

	if(!mini_crt_io_init())
	{

	}

	ret = main(arvc, argv);
	mini_exit(ret);

}
/*
int main(int argc, char* argv[])
{

	const char* c = "11";
	//*c = '2';
	char* cl = GetCommandLineA();

	*cl = '1';

	const char *t = va_arg(c,  const char*);
	//printf("%s\n", sizeof(char*));
	for(int i = 0; i < argc; i ++)
	{

	//	printf("%s\n", argv[i]);
	}

}
*/