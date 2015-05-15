#include "utils.h"

extern void test_pthread_exit() ;
extern void Test_Mem_Override() ;

extern void test_thread_cleanup_push() ;


extern void test_pthread_detach() ;

extern void test_producer_consumer() ;

int main(int argc, char *argv[])
{
	
	//test_pthread_exit() ;
	//Test_Mem_Override() ;
	//test_thread_cleanup_push() ;
	//test_pthread_detach() ;
	test_producer_consumer() ;
	return 0;
}