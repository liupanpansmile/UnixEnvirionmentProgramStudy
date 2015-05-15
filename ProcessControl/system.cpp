#include "utils.h"
#include <errno.h>

int mysystem(const char* cmdstring)
{
	if(cmdstring == NULL)
		exit(1) ;
	pid_t pid ;
	int status ;
	if( (pid = fork()) < 0)
	{
		perror("fork failed") ;
		exit(1) ;
	}
	else if(pid == 0)
	{
		execl("/bin/sh","sh","-c",cmdstring,(char*)NULL) ;
		_exit(127) ;
	}
	else
	{
		while(waitpid(pid,&status,0) < 0)
		{
			if(errno == EINTR)
			{
				status = -1 ;
				break ;
			}
		}
	}
	return status  ;
	
	
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

void test_system()
{
	int status = mysystem("date") ;
	if(status < 0)
	{
		perror("date") ;
	}
	check_status(status) ;

	status = mysystem("nosuchcmd") ;
	if(status < 0)
	{
		perror("date") ;
	}

	status = mysystem("who ; exit 55") ;
	if(status < 0)
	{
		perror("date") ;
	}
	check_status(status) ;


}