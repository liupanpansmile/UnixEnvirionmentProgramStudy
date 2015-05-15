#include "utils.h"
#ifndef BUFSIZE
#define BUFSIZE 128
#endif

void test_popen()
{
	FILE* fp = popen("/usr/bin/uptime","r") ;
	if(fp == NULL)
	{
		perror("popen failed") ;
		exit(1) ;
	}
	char buf[BUFSIZE] ;
	int cnt ;
	while( fgets(buf,BUFSIZE,fp) > 0)
	{
		printf("%s",buf) ;
	}
	pclose(fp) ;

}