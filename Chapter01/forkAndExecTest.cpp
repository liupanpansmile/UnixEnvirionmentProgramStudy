#include "utils.h"

#define BUF_SIZE 1024

/***************************************************************************
Author:			lpp
Date:			2015/04/09
Function:		
Purpose:		学习使用read write 函数
*****************************************************************************/
void sig_int(int signo)
{
	printf("sig no: %d \n",signo) ;
}
void fork_exec()
{
	pid_t pid ;
	char buf[BUF_SIZE] ;
	signal(SIGINT,sig_int) ;
	printf("%%") ;
	while (fgets(buf,BUF_SIZE,stdin) != NULL)
	{
		if(buf[strlen(buf)-1] == '\n')
		{
			buf[strlen(buf)-1] = '\0' ;
		}
		if( (pid = fork()) < 0)
		{
			perror("fork failed") ;
			exit(1) ;
		}
		else if(pid == 0)
		{
			execlp(buf,buf,(char*)0) ;
		}
		else
		{
			int status ;
			waitpid(pid,&status,0) ;
			
		}
		printf("%%") ;
	}
	
}