#include <iostream>
#include <stdio.h>

using namespace std;

extern char** environ ;

extern void test_print_environ() ;
extern void test_memory() ;
extern void test_calloc() ;
extern void test_environ() ;


extern void test_jmp_main() ;

int main(int argc, char *argv[])
{
	//test_print_environ() ;
	//test_memory() ;

	//test_calloc() ;
	//test_print_environ() ;

	//test_environ() ;
	test_jmp_main() ;

	return 0;
}