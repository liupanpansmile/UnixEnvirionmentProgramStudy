#include "utils.h"


void test_file_access()
{
	const char* filename = "file" ;
	struct stat buf ;
	stat(filename,&buf) ;
	
	//test file access permission
	if(S_IRUSR & buf.st_mode)
	{
		printf("user read \n") ;
	}
	if(S_IWUSR & buf.st_mode)
	{
		printf("user write \n") ;
	}
	if(S_IXUSR & buf.st_mode)
	{
		printf("user execute \n") ;
	}

	if(S_IRGRP & buf.st_mode)
	{
		printf("group read \n") ;
	}
	if(S_IWGRP &buf.st_mode)
	{
		printf("group write \n") ;
	}
	if(S_IXGRP & buf.st_mode)
	{
		printf("group execute \n") ;
	}

	if(S_IROTH & buf.st_mode)
	{
		printf("other read \n") ;
	}
	if(S_IWOTH & buf.st_mode)
	{
		printf("other write \n") ;
	}
	if(S_IXOTH & buf.st_mode) 
	{
		printf("other execute \n") ;
	}






}