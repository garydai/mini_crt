#include "minicrt.h"

namespace mini_crt
{

bool mini_crt_io_init()
{
	return 1;
}

FILE* fopen(const char* filename, const char* mode)
{
	HANDLE hFile = 0;
	int access = 0;
	int creation = 0;

	if(mini_crt::strcmp(mode, "w") == 0)
	{
		access |= GENERIC_WRITE;
		creation |= CREATE_ALWAYS;
	}

	if(mini_crt::strcmp(mode, "w+") == 0)
	{
		access |= GENERIC_WRITE | GENERIC_READ;
		creation |= CREATE_ALWAYS;	
	}

	if(mini_crt::strcmp(mode, "r") == 0)
	{
		access |= GENERIC_READ;
		creation |= OPEN_EXISTING;	
	}

	if(mini_crt::strcmp(mode, "r+") == 0)
	{
		access |= GENERIC_READ;
		creation |= TRUNCATE_EXISTING;	
	}
	hFile = CreateFileA(filename, access, 0, 0, creation, 0, 0);
	if(hFile == INVALID_HANDLE_VALUE)
		return NULL;
	return (FILE*)hFile;

}

int fclose(FILE* f)
{
	return CloseHandle((HANDLE)f);
}

int fread(void* buffer, int size, int count, FILE* stream)
{
	DWORD read = 0;
	if(!ReadFile((HANDLE)stream, buffer, size * count, &read, 0))
		return 0;
	return read;
}
int fwrite(void* buffer, int size, int count, FILE* stream)
{
	DWORD write = 0;
	if(!WriteFile((HANDLE)stream, buffer, size * count, &write, 0))
		return 0;
	return write;
}

int fseek(FILE* fp, int offset, int set)
{
	return SetFilePointer((HANDLE)fp, offset, 0, set);
}
}