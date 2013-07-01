#include "minicrt.h"
#include <Windows.h>
#include <stdio.h>

void mini_crt_entry(void)
{
	int ret;
	int flag = 0;
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
	exit(ret);

}
void exit(int exit_code)
{
	ExitProcess(exit_code);
}
int main(int argc, char* argv[])
{

	char* c = "11";
	//*c = '2';
	char* cl = GetCommandLineA();

	*cl = '1';
	printf("%s\n", cl);
	for(int i = 0; i < argc; i ++)
	{

		printf("%s\n", argv[i]);
	}

}