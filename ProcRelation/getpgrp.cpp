#include "utils.h"

void test_getpgrp()
{
	pid_t pid ;
	int status ;

	if( (pid = fork()) < 0)
	{
		perror("fork failed") ;
	}
	else if(pid == 0)
	{
		setpgid(getpid(),0) ;
		printf("child process pgrp = %d, pid = %d ppid = %d \n",getpgrp(),getpid(),getppid()) ;
		exit(1) ;
	}
	waitpid(pid,&status,0) ;
	printf("parent process pgrp = %d , pid = %d ppid = %d \n",getpgrp(),getpid(),getppid()) ;

}