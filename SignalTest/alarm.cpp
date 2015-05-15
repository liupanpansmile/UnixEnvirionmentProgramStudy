#include "utils.h"

void alarm_handler(int signo)
{
	if(signo == SIGALRM)
	printf("in alarm_handler signo = %d\n",signo) ;
}

void test_alarm() 
{
	pid_t pid ;
	signal(SIGALRM,alarm_handler) ;

	/*if( (pid = fork()) < 0)
	{

	}
	else if(pid == 0)
	{
		printf("child process \n") ;
		alarm(1) ;
	}
	waitpid(pid,NULL,0) ;
	printf("parent process ...\n") ;*/
	alarm(10) ;
	//sleep(5) ;
	printf("process ...\n") ;
	int left = alarm(0)  ;
	printf("left = %d \n",left) ;
	pause() ;
	
}