#include "utils.h"

using namespace std;

void test_sigset()
{
	sigset_t sigset ;
	sigemptyset(&sigset) ;
	sigaddset(&sigset,SIGINT) ;

	int ret = sigismember(&sigset,SIGINT) ;
	if(ret)
	{
		cout << "is member" << endl ;
	}
	else 
	{
		cout << "is not member" << endl ;
	}
}
static void alarm_handler(int signo)
{
	cout << "in alarm handler ...signo = " << signo << endl ;
}

void test_sigset_mask()
{
	sigset_t sigset ;
	sigset_t procsigset ;
	sigemptyset(&sigset) ;
	sigaddset(&sigset,SIGALRM) ;
	sigprocmask(SIG_BLOCK,&sigset,&procsigset) ;

	signal(SIGALRM,alarm_handler) ;
	alarm(1) ;
	pause() ;
}