#include <iostream>

using namespace std;


extern void test_signal() ;


extern void test_reentrant() ;

extern void test_alarm()  ;

extern void test_sigset() ;

extern void test_sigset_mask() ;
int main(int argc, char *argv[])
{
	//test_signal() ;
	//test_reentrant() ;
	//test_alarm() ;
	//test_sigset() ;
	test_sigset_mask() ;
	return 0;
}