#include "utils.h"
#ifndef BUFSIZE
#define BUFSIZE 128
#endif

#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX 255 
#endif

#define BINDLEN 10

void server(int sockfd)
{
	int clientfd ;
	FILE *fp ;
	char buf[BUFSIZE] ;
	
	for (;;)
	{
		struct sockaddr_in client_addr ;
		socklen_t socklen = sizeof(client_addr) ;
		clientfd = accept(sockfd,(sockaddr*)&client_addr,&socklen) ;
		if(clientfd < 0)
		{
			perror("ruptimed: accept error") ;
			exit(1) ;
		}
		if( (fp = popen("/usr/bin/uptime","r")) == NULL)
		{
			sprintf(buf,"error: %s \n",strerror(errno)) ;
			send(clientfd,buf,BUFSIZE,0) ;
		}
		else
		{
			while( fgets(buf,BUFSIZE,fp) != NULL)
			{
				send(clientfd,buf,BUFSIZE,0) ;
			}
			pclose(fp) ;
		}
		close(sockfd) ;
	}
}


void test_server()
{
	struct addrinfo *ailist,*aip ;
	struct addrinfo hint ;
	int sockfd ,err,n ;
	char *host ;
#ifdef _SC_HOST_NAME_MAX
		n = sysconf(_SC_HOST_NAME_MAX) ;
		if(n < 0)
#endif
			n = HOST_NAME_MAX ;
		host = (char *) malloc(n ) ;
		if(host == NULL)
		{
			perror("malloc failed") ;
		}
		if( gethostname(host,n) < 0) 
		{
			perror("gethostname failed") ;
		}
		hint.ai_flags = AI_CANONNAME ;
		hint.ai_family = AF_INET ;
		hint.ai_socktype = SOCK_STREAM ;
		hint.ai_protocol = 0 ;
		hint.ai_addrlen =0 ;
		hint.ai_canonname = NULL ;
		hint.ai_next = NULL ;
		hint.ai_addr = NULL ;
		if( getaddrinfo(host,"uptime",&hint,&ailist) != 0) 
		{
			gai_strerror(errno) ;
		}
		for(aip = ailist; aip != NULL ; aip = ailist->ai_next) 
		{
			if( (sockfd = InitServer(SOCK_STREAM,aip->ai_addr,aip->ai_addrlen,BINDLEN)) >0 )
			{
				server(sockfd) ;
				exit(0) ;
			}
		}
		
		exit(1) ;


}