#include "utils.h"

void output_string(const char* pstr) ;

void test_setbuf_in_fork()
{
	pid_t pid ;
	int status = -1;
	if((pid = fork()) < 0)
	{
		perror("fork failed") ;
		exit(1) ;
	}
	else if(pid == 0)
	{
		output_string("output from child\n") ;
		exit(3) ;
	}
	output_string("output from parent\n") ;
	
}

void output_string(const char* pstr)
{
	const char* p = pstr ;
	setbuf(stdout,NULL) ;
	while(*p != '\0' )
	{
		putc(*p,stdout) ;
		++p ;
	}
}