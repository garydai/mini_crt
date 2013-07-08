mini_crt
========

implement of minicrt


	cl /c /DWIN32 /GS- entry.cpp malloc.cpp printf.cpp stdio.cpp string.cpp     

	lib entry.obj malloc.obj printf.obj stdio.obj string.obj /out:minicrt.lib


	cl /c /DWIN32 /GS- test.cpp


	link test.obj minicrt.lib kernel32.lib /NODEFAULTLIB /entry:mini_crt_entry 