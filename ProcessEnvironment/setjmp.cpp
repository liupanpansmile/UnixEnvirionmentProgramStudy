#include "utils.h"
#include <setjmp.h>

jmp_buf env ;

void do_line() ;
void do_cmd() ;

void test_jmp_main()
{
	if(setjmp(env) != 0)
	{
		printf("error\n") ;
	}
	do_line() ;
	printf("in jmp main... after do_line\n") ;
	exit(0) ;
}

void do_line()
{
	do_cmd() ;
	printf("in do_line ... after do_cmd \n  ") ;
}

void do_cmd()
{
	longjmp(env,1) ;
	printf("in do_cmd... after longjmp\n") ;
}