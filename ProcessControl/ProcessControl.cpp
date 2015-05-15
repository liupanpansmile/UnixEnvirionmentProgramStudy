#include <iostream>
#include "utils.h"

using namespace std;

extern void test_fork() ;
extern void test_fork_flush() ;
extern void test_vfork() ;



////////////////////////////////////
extern void test_orphan() ;
extern void test_zombie() ;
extern void test_WNOHANG() ;
extern void test_status() ;

////////////////////////////////////////////
extern void test_setbuf_in_fork() ;


///////////////////////////////////
extern void test_exec() ;

///////////////////////
extern void test_get_systime() ;



//////////////////////////////////
extern void test_system() ;


//////////////////////////////
extern void test__exit() ;
extern void test_vfork2() ;

int main(int argc, char *argv[])
{
	//test_orphan() ;
	//test_zombie() ;
	//test_WNOHANG() ;
	//test_status() ;

	//test_setbuf_in_fork();

	//test_exec() ;
	//test_get_systime() ;

	//test_system() ;
	//test__exit() ;
	test_vfork2() ;
	return 0;
}