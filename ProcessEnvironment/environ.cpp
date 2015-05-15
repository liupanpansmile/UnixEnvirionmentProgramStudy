#include "utils.h"
/*
Purpose:获取环境变量的信息
Commont:environ指向字符指针数组(环境表),每个字符指针数组元素指向环境字符串（每个字符串以'\0'结束）	
		同时指针数组以NULL结束
*/
void test_print_environ()
{
	for(int i = 0 ;environ[i] != NULL ;++i)
	{
		printf("environ[%d]: %s \n",i,environ[i]) ;
	}

	char* value = getenv("HOME") ;
	printf("\nvalue = %s\n",value) ;
}


/*
Purpose:测试stack heap的内存地址变化
Commont:
*/
void test_memory()
{
	int a = 1 ;
	int b = 2 ;
	
	int *pa =(int*) malloc(sizeof(int)) ;
	int *pb =(int*) malloc(sizeof(int)) ;
	int c = 10 ;
}

void test_environ()
{
	 char* entry = "TEST=VALUE" ;
	int ret = putenv(entry) ;
	if(ret != 0)
	{
		printf("putenv failed \n ");
		exit(1) ;
	}
	char* name = getenv("TEST") ;
	if(name == NULL)
	{
		printf("getenv failed\n") ;
		exit(1) ;
	}
	printf("name = %s \n",name) ;


	//setenv
	setenv("TEST","value",0) ;
	entry = getenv("TEST") ;
	printf("entry = %s \n",entry) ;

	//unsetenv
	if(unsetenv("TEST") !=0)
	{
		perror("unsetenv failed") ;
		exit(1) ;
	}
	if( (entry = getenv("TEST")) != NULL)
	{
		printf("entry = %s \n",entry) ;
	}
	else
	{
		printf("TEST has been unset \n") ;
	}
}