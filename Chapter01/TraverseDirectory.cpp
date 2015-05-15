#include "utils.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>

/***************************************************************************
Author:			lpp
Date:			2015/04/09
Function:		����ָ��Ŀ¼���ļ�������ӡ�ļ�����
Purpose:		ѧϰʹ��opendir readdir����
*****************************************************************************/
void TraverseDirectory(const char* path)
{
	struct dirent *dirp ;
	DIR *dp ;
	if(path == NULL)
	{
		std::cerr << "list -- directory file name " << std::endl   ;
		exit(1) ;
	}
	if( (dp =opendir(path) ) == NULL)
	{
		std::cerr << "open " << path << "failed " << std::endl ;
		exit(1) ;
	}
	while( (dirp = readdir(dp)) != NULL)
	{
		printf("%s\n",dirp->d_name) ;
	}
	closedir(dp) ;
}





/***************************************************************************
Author:			lpp
Date:			2015/04/09
Function:		����ָ��Ŀ¼���ļ�������ȡÿ���ļ�����Ϣ
Purpose:		ѧϰʹ��opendir readdir  closedir stat����
*****************************************************************************/
void lsDirAndGetStat(const char* path)
{
	struct dirent *dirp ;
	DIR *dp ;
	if(path == NULL)
	{
		std::cerr << "list -- directory file name " << std::endl   ;
		exit(1) ;
	}
	if( (dp =opendir(path) ) == NULL)
	{
		std::cerr << "open " << path << "failed " << std::endl ;
		exit(1) ;
	}
	while( (dirp = readdir(dp)) != NULL)
	{
		//printf("%s\n",dirp->d_name) ;
		char filename[128] ;
		sprintf(filename,"%s%s",path,dirp->d_name) ;
		struct stat file_stat_info ;
		if(-1 ==stat(filename,&file_stat_info) ) // get file stat info
			perror("get stat failed") ;
		
	}
	closedir(dp) ;
}