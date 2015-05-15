#include "utils.h"

#include <pwd.h>

void my_alarm(int signo)
{
	struct passwd *pwd ;
	printf("in signal handler\n") ;
	if( (pwd = getpwnam("root")) == NULL)
	{
		perror("my_alarm getpwnam failed ") ;
		exit(0) ;
	}
	alarm(1) ;
}

void sig_segv(int signo)
{
	printf("SEGV Caught : %d\n",signo) ;
}
void test_reentrant()
{
	struct passwd *pwd; 
	signal(SIGALRM,my_alarm) ;
	signal(SIGSEGV,sig_segv) ;
	alarm(1) ;
	while(1)
	{
		if( (pwd=getpwnam("lpp")) == NULL)
		{
			perror("getpwnam failed") ;
			exit(1) ;
		}
		if( strcmp(pwd->pw_name,"lpp") !=0)
		{
			printf("return value conrupted name = %s\n",pwd->pw_name) ;
		}
		
	}
}