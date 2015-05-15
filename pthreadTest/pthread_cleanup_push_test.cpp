#include "utils.h"

/*两个子线程处理函数声明*/
static void* thread_func1(void* arg) ;
static void* thread_func2(void* arg) ;

static void cleanup(void* arg) ; //清零函数



void test_thread_cleanup_push()
{
	pthread_t tid1,tid2 ;
	void* thread_ret ;
	int err ;

	/*create first thread and join*/
	err = pthread_create(&tid1,NULL,thread_func1,(void*)1) ;
	if(err != 0)
	{
		perror("pthread create failed") ;
	}
	err = pthread_join(tid1,&thread_ret) ;
	if(err != 0)
	{
		perror("pthread join failed") ;
	}
	printf("main thread2: return code %d \n",(int*)thread_ret) ;

	/*create second thread and join*/
	err = pthread_create(&tid2,NULL,thread_func2,(void*)2) ;
	if(err != 0)
	{
		perror("pthread create failed") ;
	}
	err = pthread_join(tid2,&thread_ret) ;
	if(err != 0)
	{
		perror("pthread join failed") ;
	}
	printf("main thread2: return code %d \n",(int*)thread_ret) ;
	exit(0) ;
}

void cleanup(void* arg)
{
	printf("cleanup: %s\n",(char*)arg) ;
	//printf("cleanup \n") ;
}

/*using return to exit the thread and will not call cleanup function */
void* thread_func1(void* arg)
{
	pthread_cleanup_push(cleanup,(void*)"thread1: the first handler") ;
	pthread_cleanup_push(cleanup,(void*)"thread1: the second handler") ;
	if( arg)
	{
		return (void*)1 ;
	}
	pthread_cleanup_pop(0) ;
	pthread_cleanup_pop(0) ;
}

/*using pthread_exit to exit the thread and will call cleanup function */
void* thread_func2(void* arg)
{
	pthread_cleanup_push(cleanup,(void*)"thread2: the first handler") ;
	pthread_cleanup_push(cleanup,(void*)"thread2: the second handler") ;
	if( arg)
	{
		pthread_exit((void*)2) ;
	}
	pthread_cleanup_pop(0) ;
	pthread_cleanup_pop(0) ;
}


