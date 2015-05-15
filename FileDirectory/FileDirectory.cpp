#include <iostream>

using namespace std;

extern void test_stat() ;
extern void test_file_access() ;


extern void test_link() ;
extern void test_remove() ;
extern void test_rename() ;

//int find1(int *arr,int cnt)
//{
//	int result=0  ;
//	for(int i = 0 ;i < cnt ;++i)
//	{
//		result ^= arr[i] ;
//	}
//	return result ;
//}
//int bit_1_index(int num,int index)
//{
//	int cnt = 0 ;
//	int i = 0 ;
//	while(true) 
//	{
//		if( (num& (1<<i)) != 0)
//			++cnt ;
//		++i ;
//		if(cnt == index)
//			return i ;
//	}
//}
//int find2(int *arr,int cnt,int *a,int *b)
//{
//	int result = find1(arr,cnt) ;
//	int index = bit_1_index(result,0) ;
//	for()
//}
void func(int arr[][3],int row,int col)
{
	for (int i = 0 ;i < row;++i)
	{
		for(int j = 0 ;j < col ;++j)
		{
			cout << arr[i][j] << " " ;
		}
		cout << endl ;
	}
}

int main(int argc, char *argv[])
{

	int arr[2][3] = {1,2,3,4,5,6} ;
	func(arr,2,3) ;

	return 0;
}