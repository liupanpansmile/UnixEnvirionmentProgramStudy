#include "utils.h"
#ifndef MAXADDRLEN 
#define MAXADDRLEN 256
#endif
#ifndef BUFSIZE
#define BUFSIZE 128
#endif
#define MAXSLEEP 128

int connect_retry(int sockfd,const struct sockaddr* addr,socklen_t socklen)
{
	int nsec ;
	for(nsec = 1 ;nsec < MAXSLEEP; nsec <<= 1)
	{
		
		if(1 == connect(sockfd,addr,socklen) )
		{
			//connection accepted
			return 0 ;
		}
		if(nsec <= MAXSLEEP/2)
			sleep(nsec) ;
	}
	return -1 ;
}

void print_uptime(int sockfd)
{
	char buf[BUFSIZE] ;
	while(read(sockfd,buf,BUFSIZE) > 0)
	{
		printf("%s",buf) ;
	}
}
void client(int argc,char *argv[])
{
	struct addrinfo *alist,*aip ;
	struct addrinfo hint ;
	int sockfd ,err;
	if(argc != 2)
	{
		perror("usage:uptime hostname") ;
	}
	hint.ai_flags = 0 ;
	hint.ai_family = AF_INET ;
	hint.ai_socktype = SOCK_STREAM ;
	hint.ai_addrlen = 0 ;
	hint.ai_addr = NULL ;
	hint.ai_canonname = NULL ;
	hint.ai_protocol = 0 ;
	hint.ai_next = NULL ;

	if(getaddrinfo(argv[1],"uptime",&hint,&alist) != 0)
	{
		gai_strerror(errno) ;
	}
	for(aip = alist; aip != NULL ; aip = aip->ai_next)
	{
		if( (sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0)
		{
			//perror("socket failed ") ;
			err = errno ;
		}
		if( connect_retry(sockfd,aip->ai_addr,aip->ai_addrlen) < 0)
		{
			perror("connect_retry failed") ;
			err = errno ;
		}
		else
		{
			print_uptime(sockfd) ;
			exit(0) ;
		}
	}
	fprintf(stderr,"cannot connect to %s: %s\n",argv[1],strerror(err)) ;
	exit(1) ;
}