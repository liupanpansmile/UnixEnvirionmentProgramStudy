#include "utils.h"
/*
Purpose:��ȡ������������Ϣ
Commont:environָ���ַ�ָ������(������),ÿ���ַ�ָ������Ԫ��ָ�򻷾��ַ�����ÿ���ַ�����'\0'������	
		ͬʱָ��������NULL����
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
Purpose:����stack heap���ڴ��ַ�仯
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