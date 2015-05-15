#include "utils.h"
void sighandler(int ) ;
void test_signal() 
{
	signal(SIGCHLD,sighandler) ;
	pid_t pid ;
	int status ;
	if( (pid = fork()) < 0 )
	{
		perror("fork failed") ;
		exit(1) ;
	}
	else if(pid == 0)
	{
		exit(1) ;
	}
	waitpid(pid,&status,0) ;
	printf("parent status = %d",WEXITSTATUS(status)) ;

}


void sighandler(int status)
{
	printf("catched %d \n",status) ;
}