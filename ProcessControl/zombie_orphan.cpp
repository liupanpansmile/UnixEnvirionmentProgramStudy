#include "utils.h"

/************************************************************************/
/* purpose:孤儿进程的测试                                                                     */
/************************************************************************/
void test_orphan()
{
	pid_t pid ;
	if( (pid = fork()) < 0)
	{
		perror("fork failed") ;
		exit(1) ;
	}
	else if(pid == 0)
	{ //child
		printf("I am a child process \n") ;
		printf("pid = %d ppid = %d \n",getpid(),getppid());
		printf("I will sleep for five minutes \n") ;
		sleep(5) ;
		printf("pid = %d ppid = %d \n",getpid(),getppid());
	}
	else
	{
		printf("I am a parent process \n") ;
		sleep(1) ;
	}
}

/************************************************************************/
/* purpose:僵尸进程的测试                                                                     */
/************************************************************************/
void test_zombie()
{
	pid_t pid ;
	if((pid = fork()) < 0)
	{
		perror("fork failed") ;
		exit(1) ;
	}
	else if(pid == 0)
	{
		printf("I am a child process \n") ;
		exit(0) ;
	}
	sleep(1) ;
	printf("I am a parent process \n") ;
	system("ps -o pid,ppid,status,command") ;
	exit(0) ;
}


/*
pid_t waitpid(pid_t pid, int *status, int options);

option: WNOHANG --> return imediately if no child has exited
*/
void test_WNOHANG()
{
	pid_t pid ;
	int status = -1;
	if((pid = fork()) < 0)
	{
		perror("fork failed") ;
		exit(1) ;
	}
	else if(pid == 0)
	{
		sleep(1) ;
		printf("pid = %d ppid = %d \n",getpid(),getppid()) ;
		exit(0) ;
	}
	waitpid(pid,&status,WNOHANG) ;
	printf("I am a parent process  status = %d \n",status) ;
	
	exit(0) ;
}



static void check_status(int status)
{
	if(WIFEXITED(status))
	{
		printf("process normally exited with status of %d \n",WIFEXITED( status)) ;
	}
	else if(WIFSIGNALED(status))
	{
		printf("process was terminated by a signal status = %d \n",WTERMSIG(status)) ;
	}
}



void test_status()
{
	pid_t pid ;
	int status = -1;
	if((pid = fork()) < 0)
	{
		perror("fork failed") ;
		exit(1) ;
	}
	else if(pid == 0)
	{
		printf("I am a child process \n") ;
		exit(3) ;
	}
	waitpid(pid,&status,0) ;
	check_status(status) ;

	if((pid = fork()) < 0)
	{
		perror("fork failed") ;
		exit(1) ;
	}
	else if(pid == 0)
	{
		printf("I am a child process \n") ;
		abort() ;
	}
	waitpid(pid,&status,0) ;
	check_status(status) ;


	exit(0) ;
}