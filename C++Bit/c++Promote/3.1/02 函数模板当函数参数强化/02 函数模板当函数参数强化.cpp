#include<iostream>
using namespace std;
template < typename T ,typename T2> 
//让你对字符数组 int数组进行排序
int mySort(T *array, T2 size){
	T2 i, j;
	T temp;
	if (array == NULL){
		return -1;
	}
	for (i = 0; i < size; i++){
		for ( j = i + 1; j < size; j++){
			if (array[i] < array[j]){
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	return 0;
}
template <typename T,typename T2>
int myprint(T *array,T2 size){
	T2 i;
	for ( i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	return 0;
	
}
int main(){
	{
		int myarray[] = { 11, 12, 34, 33, 94, 32, 66 };
		int size = sizeof(myarray) / sizeof(*myarray);
		mySort<int, int >(myarray, size);
		myprint<int, int >(myarray, size);
	}
	{
		char buf[] = "shangxiaofengshixuanyu";
		int len = strlen(buf);
		mySort <char, int>(buf, len);
		myprint<char, int>(buf, len);
	}
	return 0;
}