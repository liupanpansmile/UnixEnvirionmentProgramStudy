#include "utils.h"


#define  BUF_SIZE  1024

/***************************************************************************
Author:			lpp
Date:			2015/04/09
Function:		测试io 读写
Purpose:		学习使用read write 函数
*****************************************************************************/
void io_test()
{
	char buf[BUF_SIZE]  ;
	int cnt= 0 ;
	
	while( (cnt = read(STDIN_FILENO,buf,BUF_SIZE)) > 0)
	{
		write(STDOUT_FILENO,buf,cnt) ;	
	}
	
}