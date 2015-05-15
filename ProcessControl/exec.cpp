#include "utils.h"

//
//void test_exec()
//{
//	pid_t pid ;
//	int status = 100;
//	if((pid = fork()) < 0)
//	{
//		perror("fork failed") ;
//		exit(1) ;
//	}
//	else if(pid == 0)
//	{
//		printf("pid = %d ppid = %d \n",getpid(),getppid()) ;
//		if(-1 != execl("a",NULL) )
//		{
//			printf("execl success ! \n") ;
//		}
//		exit(3) ;
//	}
//	waitpid(pid,&status,0);
//	if(-1 == execlp("ls","-l",NULL) )
//	{
//		perror("execlp failed") ;
//	}
//	printf("parent process end... status = %d\n",status) ;
//
//}




void test_exec()
{
	pid_t pid ;
	int status = 100;
	if((pid = fork()) < 0)
	{
		perror("fork failed") ;
		exit(1) ;
	}
	else if(pid == 0)
	{
		printf("pid = %d ppid = %d \n",getpid(),getppid()) ;
		if(-1 != execl("a",NULL) )
		{
			printf("execl success ! \n") ;
		}
		exit(3) ;
	}
	waitpid(pid,&status,0);
	if(-1 == execlp("ls","ls","-l",NULL) )
	{
		perror("execlp failed") ;
	}
	printf("parent process end... status = %d\n",status) ;

}