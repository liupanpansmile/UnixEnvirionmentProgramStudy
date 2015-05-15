#include "utils.h"

static void alarm_sig(int sig)
{
	//do nothing and just to wake up pause
	printf("alarm sig \n") ;
}



static int sleep1(int nsecs)
{
	if( signal(SIGALRM,alarm_sig) == SIG_ERR)
	{
		return nsecs ;
	}
	int left = alarm(nsecs) ;
	if(left == 0)
	{
		sleep(nsecs+1) ;
		pause() ;
	}
	else if(left < nsecs)
	{
		alarm(0) ;
		alarm(left) ;
		//pause() ;
	}
	else
	{
		pause() ;
		alarm(left) ;
	}
	
}

void anolog_sleep_simple()
{
	//signal(SIGALRM,alarm_sig) ;
	//alarm(1) ;

	sleep1(5) ; // shorter than the first alarm
	pause() ;
}