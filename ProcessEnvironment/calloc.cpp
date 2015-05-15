#include "utils.h"

/************************************************************************/
/* purpose:≤‚ ‘malloc calloc  realloc                                                                     */
/************************************************************************/
void test_calloc()
{
	char* pstr = (char*)calloc(10,sizeof(char)) ; // alloc 10bytes ,and initailize to 0
	for (int i = 0 ;i < 10 ;++i)
	{
		std::cout << pstr[i] ;
	}
	std::cout << std::endl ;

	strcpy(pstr,"zhangsan") ;
	std::cout << pstr << std::endl ;
	char *p =(char*) realloc(pstr,2000) ;
	std::cout << p << std::endl ;

	strcat(p," lisi") ;
	std::cout << p << std::endl ;
	if(pstr != NULL)
	{
		printf("pstr != NULL \n") ;
		std::cout << pstr << std::endl ;
	}
	if(p == pstr)
	{
		std::cout << "the same address !" << std::endl ;
	}
	free(p) ;
}