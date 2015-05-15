#include "utils.h"

/***************************************************************************
Author:			lpp
Date:			2015/04/09
Function:		测试io 读写
Purpose:		学习使用read write 函数
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
Function:		测试两个进程分别往同一个文件中append数据，由于A进程lseek后，挂起，而B进程lseek，执行write，最后A进程write，从而造成此时A进程了seek不是最新的文件末尾，从而覆盖之前B进程写的文件数据
Purpose:		学习使用read write 函数
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
Purpose:		测试使用O_APPEND标志读写一个文件，能否用lseek在任一位置读，任一位置更新数据
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