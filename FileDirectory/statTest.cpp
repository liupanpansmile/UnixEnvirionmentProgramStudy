#include "utils.h"



void test_stat()
{
	struct stat buf ;
	stat("/dev/fd/0",&buf) ;
	if(S_ISCHR(buf.st_mode))
	{
		printf("character file \n") ;
	}
	else if(S_ISDIR(buf.st_mode))
	{
		printf("dir file \n") ;
	}
	else if(S_ISREG(buf.st_mode))
	{
		printf("regular file \n") ;
	}
	else if(S_ISLNK(buf.st_mode))
	{
		printf("symbol link \n") ;
	}
}