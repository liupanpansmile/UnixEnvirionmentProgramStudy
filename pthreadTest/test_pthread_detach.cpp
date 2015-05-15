/*
purpose: test  pthread_detach function
comment: 线程分为两种状态：joinable和unjoinable（detachable）,线程默认为joinable，如果线程处于detachable，
		 则线程的底层资源可以在线程结束时，有OS回收，当线程处于分离状态时，不能调用pthread_join等待线程的结束，对应分离状态的想成调用pthread_join会失败。

		 在Web服务中，主线程对每个客户端请求都会创建一个线程，但是主线程又不想阻塞，而是想继续执行一些事情，那么在子线程中设置pthread_detach(pthread_self()),
		 则子线程结束时，相应的资源就会回收

*/

#include "utils.h"

void read_file(const char* filename) 
{
	int fd  ;
	if((fd = open(filename,O_RDONLY)) < 0)
	{
		perror("open file failed ") ;
		exit(1) ;
	}
	
	char buf[128] ;
	int n ;

	while(1)
	{
		while( (n = read(fd,buf,128))> 0)
		{
			write(STDOUT_FILENO,buf,n) ;
			sleep(1) ;
		}
		lseek(fd,0,SEEK_SET) ;
	}
	close(fd) ;
	
}

static void* thread_func1(void* arg)
{

	pthread_detach(pthread_self()) ;
	//read another file
	int fd = open((char*)arg,O_RDONLY) ;
	char buf[128] ;
	int n ;
	if(fd < 0)
	{
		perror("open file failed ") ;
	}
	//sleep(1) ;
	while(1)
	{
		while( (n = read(fd,buf,128))> 0)
		{
			write(STDOUT_FILENO,buf,n) ;
			sleep(1) ;
		}
		lseek(fd,0,SEEK_SET) ;
	}
	close(fd) ;
	
}

void test_pthread_detach()
{
	pthread_t tid ;
	void* arg ;
	int err ;
	char* main_filename = "main_file" ;
	char* sub_filename = "sub_file" ;
	if( (err = pthread_create(&tid,NULL,thread_func1,(void*)sub_filename)) != 0)
	{
		perror("pthread_create failed") ;
	}
	/*main thread*/
	read_file(main_filename) ;
	
	exit(0) ;
}



