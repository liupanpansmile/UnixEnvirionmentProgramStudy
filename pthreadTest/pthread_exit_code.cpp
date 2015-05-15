#include "utils.h"

void* thread_func1 (void *arg)
{
	printf("thread1 returning status = %d\n",*((int *)arg) ) ;
	*(int*)arg = 1 ;
	return ( (void *)1 );
}

void* thread_func2 (void *arg)
{
	printf("thread2 returning status = %d\n",*(int*)arg) ;
	*(int*)arg = 2 ;
	
	pthread_exit((void*)2) ;
}

void test_pthread_exit()
{
	pthread_t tid1,tid2 ;
	int err ;
	void *tret ;
	int status = 0 ;
	err = pthread_create(&tid1,NULL,thread_func1,(void*)&status ) ;
	if(err != 0)
	{
		perror("create pthread--1 failed") ;
	}
	pthread_join(tid1,&tret) ;
	printf("main thread tret = %d \n",(int*)tret) ;

	err = pthread_create(&tid2,NULL,thread_func2,(void*)&status ) ;
	if(err != 0)
	{
		perror("create pthread--2 failed") ;
	}
	pthread_join(tid2,&tret) ;
	printf("main thread tret = %d \n",(int*)tret) ;
	
	exit(0) ;
}