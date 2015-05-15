#include <iostream>

using namespace std;

extern  void anolog_sleep_simple() ;
extern void anolog_sleep_setjmp() ;
extern void test_sigprocmask() ;

extern void test_mysignal() ;

int main(int argc, char *argv[])
{
	//anolog_sleep_setjmp() ;
//	test_sigprocmask() ;

	test_mysignal() ;
	return 0;
}