#include "utils.h"
static pthread_t ntid ;


void printids(const char* info) 
{
	pthread_t tid  = pthread_self();
	pid_t pid  = getpid();
	pid_t ppid = getppid() ;
	printf("%s pid = %u ,ppid = %u tid = %u,0x%x ntid = %u\n",info,pid,ppid,(unsigned int)tid,(unsigned int)tid,(unsigned int )ntid) ;
}

void* thread_func (void *arg)
{
	cout << (char*) arg << endl ;
	printids("new thread:") ;
	return ( (void *)0 );
}


void test_create_pthread()
{
	const char* arg = "new thread arg"  ;
	int err ;

	err = pthread_create(&ntid,NULL,thread_func,(void*)arg) ;
	//cout << "ntid: " << ntid << endl ;
	if(err != 0)
	{
		perror("create pthread failed") ;
	}
	sleep(1 ) ;

	printids("main thread :") ;
}