#include "utils.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>

/***************************************************************************
Author:			lpp
Date:			2015/04/09
Function:		遍历指定目录的文件，并打印文件名称
Purpose:		学习使用opendir readdir函数
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
Function:		遍历指定目录的文件，并获取每个文件的信息
Purpose:		学习使用opendir readdir  closedir stat函数
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