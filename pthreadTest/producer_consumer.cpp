#include "utils.h"
#include <queue>
#include <deque>
/*
模拟生产者消费者问题
*/

struct foo
{
	pthread_mutex_t f_lock ;
	deque<int> f_queue ;
}foo;

//创建一个缓冲区
struct foo*  foo_alloc()
{
	struct foo *fp ;
	if( (fp = (struct foo*)malloc(sizeof(struct foo))) == NULL)
	{
		perror("malloc failed") ;
		exit(1) ;
	}
	if(pthread_mutex_init(&fp->f_lock,NULL) !=0)
	{
		free(fp) ;
		return NULL ;
	}
	fp->f_queue.clear()  ;
	return fp ;
}

/* producer: put data into queue */
void producer(struct foo* fp)
{
	int data = 1 ;

	pthread_mutex_lock(&fp->f_lock) ;
	fp->f_queue.push_back(data) ;
	int size = fp->f_queue.size();
	fp->f_queue.push_back(data) ;
	fp->f_queue.push_back(data) ;
	fp->f_queue.push_back(data) ;
	fp->f_queue.push_back(data) ;
	fp->f_queue.push_back(data) ;
	printf("producer: %d\n",data) ;
	++data ;
	pthread_mutex_unlock(&fp->f_lock) ;

	sleep(1) ;
}

/*fetch data from queue*/
void consumer(struct foo* fp)
{
	pthread_mutex_lock(&fp->f_lock) ;
	if(fp->f_queue.empty())
	{
		printf("queue is empty \n") ;
	}
	else
	{
		//printf("consumer: %d \n",fp->f_queue.front()) ;
		//fp->f_queue.pop_front() ;
	}
	pthread_mutex_unlock(&fp->f_lock) ;
	sleep(1) ;
}

void* pthread_producer(void* arg)
{
	while(1)
	{
		producer((struct foo*)arg) ;
	}
}

void* pthread_consumer(void* arg)
{
	return NULL;
	while(1)
	{
		consumer((struct foo*)arg) ;
	}
}

void test_producer_consumer()
{
	pthread_t producer_tid,consumer_tid ;
	int err ;
	struct foo *fp = foo_alloc() ;

	err = pthread_create(&producer_tid,NULL,pthread_producer,(void*)fp) ;  
	if(0 != err)
	{
		perror("create producer thread failed") ;
		exit(1) ;
	}

	err = pthread_create(&consumer_tid,NULL,pthread_consumer,(void*)fp) ;  
	if(0 != err)
	{
		perror("create consumer thread failed") ;
		exit(1) ;
	}


	err = pthread_join(producer_tid,NULL) ;
	if(0 != err )
	{
		perror("join producer failed") ;
	}

	/*consumer thread */
	
	err = pthread_join(consumer_tid,NULL) ;
	if(0 != err )
	{
		perror("join consumer failed") ;
	}
	while (true)
	{
		sleep(1);
	}

}









//
//#include "utils.h"
//#include <queue>
//#include <deque>
///*
//模拟生产者消费者问题
//*/
//
//struct foo
//{
//	pthread_mutex_t f_lock ;
//	int f_queue ;
//}foo;
//
////创建一个缓冲区
//struct foo*  foo_alloc()
//{
//	struct foo *fp ;
//	if( (fp = (struct foo*)malloc(sizeof(struct foo))) == NULL)
//	{
//		perror("malloc failed") ;
//		exit(1) ;
//	}
//	if(pthread_mutex_init(&fp->f_lock,NULL) !=0)
//	{
//		free(fp) ;
//		return NULL ;
//	}
//	
//	return fp ;
//}
//
///* producer: put data into queue */
//void producer(struct foo* fp)
//{
//	static int data = 1 ;
//
//	pthread_mutex_lock(&fp->f_lock) ;
//
//	fp->f_queue = data ;
//	printf("producer: %d\n",data) ;
//	++data ;
//
//	pthread_mutex_unlock(&fp->f_lock) ;
//	sleep(1) ;
//}
//
///*fetch data from queue*/
//void consumer(struct foo* fp)
//{
//	pthread_mutex_lock(&fp->f_lock) ;
//	printf("consumer = %d \n",fp->f_queue) ;
//	pthread_mutex_unlock(&fp->f_lock) ;
//	sleep(1) ;
//}
//
//void* pthread_producer(void* arg)
//{
//	while(1)
//	{
//		producer((struct foo*)arg) ;
//	}
//}
//
//void* pthread_consumer(void* arg)
//{
//	while(1)
//	{
//		consumer((struct foo*)arg) ;
//	}
//}
//
//void test_producer_consumer()
//{
//	pthread_t producer_tid,consumer_tid ;
//	int err ;
//	struct foo *fp = foo_alloc() ;
//
//	err = pthread_create(&producer_tid,NULL,pthread_producer,(void*)fp) ;  
//	if(0 != err)
//	{
//		perror("create producer thread failed") ;
//		exit(1) ;
//	}
//	err = pthread_create(&consumer_tid,NULL,pthread_consumer,(void*)fp) ;  
//	if(0 != err)
//	{
//		perror("create consumer thread failed") ;
//		exit(1) ;
//	}
//	err = pthread_join(producer_tid,NULL) ;
//	if(0 != err )
//	{
//		perror("join producer failed") ;
//	}
//
//	/*consumer thread */
//	
//	err = pthread_join(consumer_tid,NULL) ;
//	if(0 != err )
//	{
//		perror("join consumer failed") ;
//	}
//
//
//}