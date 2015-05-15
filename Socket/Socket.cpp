#include <iostream>
#include "utils.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
using namespace std;

extern void test_popen() ;
extern void client(int argc, char *argv[]) ;
#ifndef BUFSIZE 
#define BUFSIZE 255
#endif

void test()
{
	char host[BUFSIZE]	 ;
	if(-1 == gethostname(host,BUFSIZE) )
	{
		perror("gethostname failed") ;
		exit(1) ;
	}
	printf("hostname = %s\n",host) ;
}

void test_getprototent()
{
	struct protoent *p = NULL ;
	while ( (p = getprotoent() ) != NULL ) 
	{
		cout << p->p_name << endl ;
		cout << p->p_proto << endl ;

	}
	endprotoent() ;
}

void test_getserver()
{
	struct servent *p = NULL ;
	while( (p = getservent()) != NULL)
	{
		cout << p->s_name << "  " << p->s_port << "  " << *(p->s_aliases) << endl ;
	}
	endservent() ;
}


void test_getaddrinfo(int argc,char* argv[])
{
	struct addrinfo *ailist,*aip ;
	struct addrinfo hint ;
	struct sockaddr_in *sinp ;
	const char *addr ;
	int err ;
	char buf[128] ;
	hint.ai_family = AF_INET ;
	hint.ai_flags = AI_CANONNAME ;
	hint.ai_socktype = 0 ;
	hint.ai_protocol = 0 ;
	hint.ai_addrlen = 0 ;
	hint.ai_addr = NULL ;
	hint.ai_canonname = NULL ;
	hint.ai_next = NULL ;

	if(getaddrinfo(argv[1],argv[2],&hint,&ailist) != 0)
	{
		gai_strerror(errno) ;
	}
	if(ailist != NULL)
	{
		printf("get success \n") ;
	}
}
int main(int argc, char *argv[])
{
	//test_popen()	 ;
	/*struct netent *p  = getnetbyname("link-local") ;*/
	/*while( (p = getnetent()) != NULL )
	{
		cout << p->n_name << endl ;
	
	}*/
	/*if( p != NULL)
	{
		cout << p->n_name << endl ;
	}*/

//	test_getprototent() ;
//	test_getserver() ;

	test_getaddrinfo(argc,argv) ;
	
	return 0;
}