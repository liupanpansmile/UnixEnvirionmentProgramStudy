#include "utils.h"

/***************************************************************************
Author:			lpp
Date:			2015/04/09
Function:		����io ��д
Purpose:		ѧϰʹ��read write ����
*****************************************************************************/
void io_test()
{
	

	int fd ;
	for(fd = 0 ;fd < 2 ;++fd)
		close(fd) ;

	fd = open("/home/lpp/infile",O_WRONLY|O_CREAT) ;
	if(fd < 0)
	{
		perror("open file failed") ;
		exit(1) ;
	}
	printf("fd = %d \n",fd) ;
	close(fd) ;

}

void lseek_test()
{
	if( lseek(STDIN_FILENO,0,SEEK_CUR) == -1)
	{
		printf("cannot seek\n") ;
	}
	else
	{
		printf("seek ok !\n") ;
	}
}

void test_file_hole()
{
	const char* pstr1 = "abcdefghij" ;
	const char* pstr2 = "ABCDEFGHIJ" ;

	int fd = open("./file_hole",O_RDWR|O_APPEND) ;
	if(fd < 0)
	{
		perror("open file failed") ;
		exit(1) ;
	}
	write(fd,pstr1,10) ;
	lseek(fd,16384,SEEK_SET) ;
	write(fd,pstr2,10) ;
	close(fd) ;
}

/***************************************************************************
Author:			lpp
Date:			2015/04/09
Function:		�����������̷ֱ���ͬһ���ļ���append���ݣ�����A����lseek�󣬹��𣬶�B����lseek��ִ��write�����A����write���Ӷ���ɴ�ʱA������seek�������µ��ļ�ĩβ���Ӷ�����֮ǰB����д���ļ�����
Purpose:		ѧϰʹ��read write ����
*****************************************************************************/

void test_write_process()
{
	pid_t pid ;
	int fd ;
	const char* bufA = "zhangsan" ;
	const char* bufB = "lisi" ;
	if( (fd =open("file",O_RDWR |O_APPEND)) < 0)
	{
		perror("open file failed") ;
		exit(1) ;
	}
	if( (pid = fork()) < 0)
	{
		perror("fork failed") ;
		exit(1) ;
	}
	else if(pid == 0)
	{
		
		if( lseek(fd,0,SEEK_END)< 0)
			perror("lseek failed") ;
		sleep(1) ;
		write(fd,bufA,strlen(bufA)) ;
	}
	else
	{
		if( lseek(fd,0,SEEK_END)< 0)
			perror("lseek failed") ;
		//waitpid(pid,0,0) ;
		write(fd,bufB,strlen(bufB)) ;
	}
	close(fd) ;

	
}


void test_dup()
{
	int fd = open("/dev/null",O_WRONLY) ;
	//int newfd = dup(STDIN_FILENO) ;
	dup2(fd,STDIN_FILENO) ;
	dup2(fd,STDOUT_FILENO) ;
	dup2(fd,STDERR_FILENO) ;
	printf("hello world \n") ;
	close(fd) ;

}



void test_fcntl()
{
	/*
	int newfd = fcntl(STDIN_FILENO,F_GETFD) ;
	int fd = fcntl(STDIN_FILENO,F_SETFD,3) ;
	*/

	int fd = open("file",O_WRONLY) ;
	int file_status = fcntl(fd,F_GETFL) ;
	if(O_WRONLY == (file_status&O_ACCMODE))
	{
		printf("WRITE ONLY \n") ;
	}
	else if(O_RDONLY == file_status&O_ACCMODE)
	{
		printf("READ ONLY \n") ;
	}
	else if(O_RDWR == file_status&O_ACCMODE)
	{
		printf("WRITE AND READ \n") ;
	}
}

/***************************************************************************
Author:			lpp
Date:			2015/04/010
Purpose:		����ʹ��O_APPEND��־��дһ���ļ����ܷ���lseek����һλ�ö�����һλ�ø�������
*****************************************************************************/
void test_lseek_append()
{

	int fd ;
	if( (fd = open("file",O_RDWR | O_APPEND)) < 0)
	{
		perror("cannot open the file") ;
		exit(1) ;
	}
	__off_t position = lseek(fd,0,SEEK_CUR) ;
	printf("position = %ld \n",position) ;
	const char* buf = "zhangsan" ;
	const char* name = "lisi" ;
	char b[1024] ;
	write(fd,buf,strlen(buf)) ;

	position = lseek(fd,0,SEEK_SET) ;
	printf("position = %ld \n",position) ;

	write(fd,name,strlen(name)) ;

	lseek(fd,4,SEEK_SET) ;
	read(fd,b,4) ;
	printf("b = %s \n",b) ;
	close(fd) ;
}