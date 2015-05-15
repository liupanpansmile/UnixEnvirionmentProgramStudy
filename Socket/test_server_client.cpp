#include <iostream>
#include "utils.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
using namespace std;

#define PORT 8899
void server()
{
	int sockfd = socket(AF_INET,SOCK_STREAM,0) ; //ipv4  tcp
	if(sockfd < 0 )
	{
		perror("create socket failed") ;
		exit(1) ;
	}
	struct sockaddr_in server_addr ;
	memset(&server_addr,0,sizeof(server_addr)) ;
	server_addr.sin_family = AF_INET ;
	server_addr.sin_port = PORT ;					//随机分配端口
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY) ;	//本地地址

	if(-1 == bind(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr)) )  //bind a name to a socket 
	{
		perror("bind failed") ;
		exit(1) ;
	}

	listen(sockfd,5) ;
	printf("listen ...\n") ;
	while(1)
	{
		struct sockaddr_in client_addr;
		socklen_t socklen ;
		int clientfd ;
		if( (clientfd= accept(sockfd,(sockaddr*)&client_addr,&socklen)) == -1)
		{
			perror("accept failed ") ;
		}
		const char* welcomeString = "Welcome to visit server!" ;
		char buf[128] ;
		write(clientfd,welcomeString,strlen(welcomeString)+1) ;
		read(clientfd,buf,128) ;
		printf("%s\n",buf) ;
		close(clientfd) ;
	}

}


void client(const char* server_address)
{
	int sockfd = socket(AF_INET,SOCK_STREAM,0) ; //ipv4  tcp
	if(sockfd < 0 )
	{
		perror("create socket failed") ;
		exit(1) ;
	}
	struct sockaddr_in client_addr ;
	memset(&client_addr,0,sizeof(client_addr)) ;
	client_addr.sin_family = AF_INET ;
	client_addr.sin_port = htons(0) ;					//随机分配端口
	client_addr.sin_addr.s_addr = htonl(INADDR_ANY) ;	//本地地址


	struct sockaddr_in server_addr ;
	server_addr.sin_family = AF_INET ;
	server_addr.sin_port = PORT ;
	inet_aton(server_address,&server_addr.sin_addr) ; //将地址转换成网络地址
	if(-1 == connect(sockfd,(sockaddr*)&server_addr,sizeof(server_addr)) )
	{
		perror("connect failed");
		exit(1) ;
	}
	char buf[128] ;
	if(read(sockfd,buf,128) >0)
	{
		printf("%s\n",buf) ;
	}
	strcpy(buf,"I am client") ;
	write(sockfd,buf,strlen(buf)+1) ;
	close(sockfd) ;
}