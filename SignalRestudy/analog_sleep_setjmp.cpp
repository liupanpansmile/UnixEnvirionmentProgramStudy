#include "utils.h"
#include <setjmp.h>

static jmp_buf env_alarm ;

static void alarm_sig(int sig)
{
	printf("alarm_sig before longjmp \n") ;
	longjmp(env_alarm,1) ;
	printf("alarm_sig nerver called \n") ;
}



static int sleep2(int nsecs)
{
	if( signal(SIGALRM,alarm_sig) == SIG_ERR)
	{
		return nsecs ;
	}
	printf("before setjmp \n") ;
	if(setjmp(env_alarm) == 0)
	{
		alarm(nsecs) ;
		pause() ;
	}
	printf("before return \n") ;
	return alarm(0) ;

}

void anolog_sleep_setjmp()
{

	sleep2(1) ; // shorter than the first alarm
	
}