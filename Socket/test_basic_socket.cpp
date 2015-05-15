#include "utils.h"

void test_dup()
{
	int fd = open("outfile", O_RDWR) ;
	const char* pstr = "after dup----------2" ;
	if(fd <  0 )
	{
		perror("open failed ") ;
		exit(1) ;
	}
	printf("before dup------1") ;
	int newfd = dup2(fd,STDOUT_FILENO) ;
	write(fd,pstr,sizeof(pstr)) ;
	printf(" after dup newfd = %d\n",newfd) ;
	close(fd) ;
}


void Test_inet_ntop()
{
	char pstr[20]="192.168.1.1" ;
	char IPDotDec[20] ;
	struct in_addr s ;
	//printf("Please enter IP address : ");
	//scanf("%s",pstr) ;
	inet_pton(AF_INET,pstr,(void*)&s) ;

	unsigned int i0 = s.s_addr& 0xff ;
	unsigned int i4 = (s.s_addr >> 8)& 0xff ;
	unsigned int i8 = (s.s_addr>>16)&0xff  ;
	unsigned int i12 = (s.s_addr>>24)& 0xff ;


	/*unsigned int i0 = s.s_addr& 0xff ;
	unsigned int i4 = (s.s_addr& (0xff << 8)) >> 8 ;
	unsigned int i8 = (s.s_addr& (0xff << 16) ) >>16 ;
	unsigned int i12 = (s.s_addr& (0xff << 24)) >> 24 ;*/
	printf("ip: %d\n",s.s_addr) ;
	printf("i0=%d, i4=%d, i8=%d,i12=%d\n",i0,i4,i8,i12) ;


	inet_ntop(AF_INET,(void*)&s,IPDotDec,20) ;
	printf("IPDotDec = %s \n",IPDotDec) ;



}


void test_gethostent()
{
	struct hostent *phost = gethostent() ;
	cout << phost->h_name << endl ;
	for(int i = 0 ;phost->h_addr_list[i]  ;++i)
	cout << phost->h_addr_list[i] << " "  ;
	cout << endl ;
	if(AF_INET == phost->h_addrtype )
	{
		cout << "AF_INET" << endl ;
	}
	phost = gethostent() ;
	cout << phost->h_name << endl ;

}
void print_netent(struct netent *net)
{
	if(net == NULL)
	{
		return ;
	}
	char buf[20] ;
	printf("name of network: %s\n",net->n_name) ;
	for(char **p = net->n_aliases ;*p != NULL  ;++p) 
	{
		cout << "aliases:" << *p << endl ;
	}
	uint32_t netnumber = net->n_net ;
	inet_ntop(AF_INET,(void*)&netnumber,buf,20) ;
	cout << "ip: " << buf << endl ;
}
void test_getnet()
{
	struct netent* net = NULL ;
	setnetent(1) ;
	while ( (net=getnetent()) != NULL)
	{
		print_netent(net) ;
	}
	endnetent() ;
}