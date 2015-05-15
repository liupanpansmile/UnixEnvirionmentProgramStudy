#include "utils.h"

void test__exit()
{
	pid_t pid ;
	int status = -1 ;

	if((pid = fork()) < 0)
	{
		perror("fork failed") ;
		exit(1) ;
	}
	else if(0 == pid)
	{
		printf("child process \n") ;
		_exit(1) ;
	}
	waitpid(pid,&status,0) ;
	printf("parent process exit code %d\n",status) ;

}

const char* test_vfork_sub() ;

void test_vfork2()
{
	char pstr[50] ;
	strcpy(pstr, test_vfork_sub()) ;
	
	printf("pstr = %s \n",pstr) ;
}

const char* test_vfork_sub()
{
	pid_t pid ;
	int status = -1 ;
	const char* pstr = NULL ;
	if((pid = vfork()) < 0)
	{
		perror("fork failed") ;
		exit(1) ;
	}
	else if(0 == pid)
	{
		pstr = "child process" ;
		return pstr ;
	}

	waitpid(pid,&status,0) ;
	pstr = "parent process" ;
	return pstr ;
}