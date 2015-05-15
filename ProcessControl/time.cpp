#include "utils.h"
#include <time.h>

void test_get_systime()
{
	char str[128] ;
	time_t t ;
	time(&t) ; //get system time 
	struct tm *_t = localtime(&t) ;
	strftime(str,128,"%y-%m-%d %H:%M:%S",_t) ;
	printf("time = %s \n",str) ;
}