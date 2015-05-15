#include <iostream>

using namespace std;

extern void io_test() ;
extern void lseek_test() ;
extern void test_file_hole() ;

extern  void test_write_process() ;
extern void test_dup() ;
extern void test_fcntl() ;


extern void test_lseek_append() ;
int main(int argc, char *argv[])
{
	//io_test() ;
	//lseek_test() ;
	//test_file_hole() ;

	//test_write_process() ;
	//test_dup() ;
	//test_fcntl() ;

	test_lseek_append() ;

	return 0;
}