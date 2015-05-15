#include "utils.h"

void test_link()
{
	const char* old_filename = "oldfile" ;
	const char* new_filename ="newfile" ;
	int fd = creat(old_filename,S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH) ;
	const char* buf = "zhangsan lisi" ;
	if(fd  < 0)
	{
		perror("create file failed ") ;
		exit(1) ;
	}
	

	int ret = link(old_filename,new_filename) ;

	write(fd,buf,strlen(buf)+1) ;
	close(fd) ;

	if(ret == -1)
	{
		perror("link file failed") ;
	}
	else
	{
		printf("link ok ! \n") ;
	}
	unlink(new_filename) ;
}


void test_remove()
{
	const char* old_filename = "oldfile" ;
	const char* new_filename ="newfile" ;
	int fd = creat(old_filename,S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH) ;
	const char* buf = "zhangsan lisi" ;
	if(fd  < 0)
	{
		perror("create file failed ") ;
		exit(1) ;
	}


	int ret = link(old_filename,new_filename) ;

	write(fd,buf,strlen(buf)+1) ;
	close(fd) ;

	if(ret == -1)
	{
		perror("link file failed") ;
	}
	else
	{
		printf("link ok ! \n") ;
	}
	remove(old_filename) ;
}


void test_rename()
{
	const char* oldname = "oldfile" ;
	const char* newname = "newfile" ;
	int ret = rename(oldname,newname) ;
	if(ret == 0)
	{
		printf("rename success ! \n") ;
	}
	else
	{
		printf("rename failed \n") ;
	}

}