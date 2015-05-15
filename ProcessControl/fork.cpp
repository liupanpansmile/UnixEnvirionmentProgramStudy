#include "utils.h"

void test_fork()
{
	pid_t pid ;
	int a = 10 ;
	if( (pid = vfork()) < 0)
	{
		perror("fork failed") ;
		exit(1) ;
	}
	else if(pid == 0 )
	{
		//child
		printf("a = %d \n",a) ;
		a = 1 ;
	}
	else
	{
		printf("a = %d \n",a) ;
		a = 2 ;
	}
	exit(0) ;
}

void test_fork_flush()
{
	pid_t pid ;
	int a = 10 ;
	const char* buf = "a write to stdout \n" ;
	if(strlen(buf) != write(STDOUT_FILENO,buf,strlen(buf)) )
	{
		perror("write failed") ;
		exit(1) ;
	}
	printf("before fork \n") ; //not flush
	if( (pid = fork()) < 0)
	{
		perror("fork failed") ;
		exit(1) ;
	}
	else if(pid == 0 )
	{
		//child
		a = 1 ;
	}
	else
	{
		a = 2 ;
	}
	printf("a = %d \n",a) ;
	//exit(0) ;
}



void test_vfork()
{
	pid_t pid ;
	int a = 10 ;
	
	printf("before fork \n") ; //not flush
	if( (pid = vfork()) < 0)
	{
		perror("fork failed") ;
		exit(1) ;
	}
	else if(pid == 0 )
	{
		//child
		a = 1 ;
		int fd = open("/dev/null",O_RDONLY) ;
		dup2(fd,STDOUT_FILENO) ;
		dup2(fd,STDIN_FILENO) ;
		close(fd) ;
		_exit(0 ) ;
	}
	
	printf("a = %d \n",a) ;
	//exit(0) ;
}