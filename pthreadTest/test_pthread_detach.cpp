/*
purpose: test  pthread_detach function
comment: �̷߳�Ϊ����״̬��joinable��unjoinable��detachable��,�߳�Ĭ��Ϊjoinable������̴߳���detachable��
		 ���̵߳ĵײ���Դ�������߳̽���ʱ����OS���գ����̴߳��ڷ���״̬ʱ�����ܵ���pthread_join�ȴ��̵߳Ľ�������Ӧ����״̬����ɵ���pthread_join��ʧ�ܡ�

		 ��Web�����У����̶߳�ÿ���ͻ������󶼻ᴴ��һ���̣߳��������߳��ֲ������������������ִ��һЩ���飬��ô�����߳�������pthread_detach(pthread_self()),
		 �����߳̽���ʱ����Ӧ����Դ�ͻ����

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



