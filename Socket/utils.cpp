#include "utils.h"

int InitServer(int type,const struct sockaddr *addr,socklen_t len,int listenNum)
{
	int sockfd ;
	int err ;
	struct sockaddr_in server_addr ;
	memset(&server_addr,0,sizeof(server_addr)) ;

	if( -1 == (sockfd = socket(addr->sa_family,type,0))  )
	{
		return -1 ;
	}
	if( bind(sockfd,addr,len) < 0 )
	{
		err = errno ;
		goto errout ;
	}
	listen(sockfd,listenNum) ;
errout:
	close(sockfd) ;
	errno = err ;
	return -1 ;

}