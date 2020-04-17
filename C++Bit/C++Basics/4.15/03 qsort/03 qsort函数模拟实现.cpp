//#include<iostream>
//using namespace std;
//
//int cmp(const void* p1, const void* p2){
//	return (*(int*)p1 - *(int *)p2);
//}
//
//void swap(void * p1, void * p2, int size){
//	int i = 0;
//	for (i = 0; i < size; ++i){
//		char temp = *((char*)p1 + i);
//		*((char*)p1 + i) = *((char*)p2 + i);
//		*((char*)p2 + i) = temp;
//	}
//}
//void bubble(void * arr, int count, int size, int(*cmp)(void*, void *)){
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < count - 1; ++i){
//		for (j = 0; j < count - i - 1; ++j){
//			if (cmp((char*)arr + j*size, (char*)arr + (j + 1)*size )> 0){
//				swap((char*)arr + j*size, (char*)arr + (j + 1)*size, size);
//			}
//		}
//	}
//}
//int main(){
//	int arr[] = { 1, 4, 60, 7, 8, 93, 40, 5 };
//	//char *arr[] = { "aaaa", "dddd", "cccc", "bbbb" };
//	int i = 0;
//	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), cmp);
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i){
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}