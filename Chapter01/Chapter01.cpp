#include "utils.h"

using namespace std;
extern void TraverseDirectory(const char *path) ;
extern void lsDirAndGetStat(const char *path) ;

extern void io_test() ;

extern void fork_exec() ;
int main(int argc, char *argv[])
{
	

	//TraverseDirectory("nishi") ;
	//lsDirAndGetStat("/var/log/oneapm/") ;


	//io_test() ;
	fork_exec() ;
	return 0;
}