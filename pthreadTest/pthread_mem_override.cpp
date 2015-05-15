#include "utils.h"

typedef struct foo
{
	int a,b,c,d ;
}foo;

void print(const char* info,foo *p)
{
	printf("%s \n",info) ;
	printf("a = %d,b = %d,c = %d,d = %d\n",p->a,p->b,p->c,p->d) ;
}

static void* thread_func1(void* arg)
{
	
	foo f  = {1,2,3,4} ;
	print("thread 1",&f) ;
	return (void*)&f ;
}

static void* thread_func2(void* arg)
{
	
	foo f = {5,6,7,8} ;
	print("thread 2",&f) ;
	pthread_exit((void*)&f) ;
}



void Test_Mem_Override()
{
	pthread_t tid1,tid2 ;
	foo* p ;
	int err ;
	err = pthread_create(&tid1,NULL,thread_func1,NULL) ;
	if(0 != err)
	{
		perror("thread1 create failed") ;
	}
	err = pthread_join(tid1,(void**)&p) ;
	if(err !=  0)
	{
		perror("thread1 join failed") ;
	}
	print("main thread",p) ;

	err = pthread_create(&tid2,NULL,thread_func2,NULL) ;
	if(0 != err)
	{
		perror("thread2 create failed") ;
	}
	err = pthread_join(tid2,(void**)&p) ;
	if(err !=  0)
	{
		perror("thread2 join failed") ;
	}
	print("main thread ",p) ;
	exit(0) ;
	
}