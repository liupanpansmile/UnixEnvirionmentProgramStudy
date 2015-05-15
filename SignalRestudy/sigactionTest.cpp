#include "utils.h"

typedef void (*SigFunc) (int signo) ;

SigFunc MySignal(int signo,SigFunc func)
{
	struct sigaction act,oldact ;
	act.sa_handler = func ;
	sigemptyset(&act.sa_mask) ;
	act.sa_flags = 0 ;

	if(signo == SIGALRM)
	{
#ifdef SA_INTERRUPT
			act.sa_flags |= SA_INTERRUPT ;
#endif
	}
	else
	{
#ifdef SA_RESTART
		act.sa_flags |= SA_RESTART ;
#endif 
	}
	if(sigaction(signo,&act,&oldact) < 0)
	{
		return SIG_ERR ;
	}
	return oldact.sa_handler ;
}

void sig_alarm(int signo)
{
	printf("sig_alarm signo = %d \n",signo) ;
}



void test_mysignal()
{
	if( MySignal(SIGALRM,sig_alarm) == SIG_ERR )
	{
		perror("signal sigalarm failed") ;
	}
	alarm(2) ;
	pause() ;
}