#include<iostream>
using namespace std;

int binary_search(int* arr,int k,int len ){
	int left = 0;
	int right =len-1;

	while (left <= right){
		int mid = (right + left) / 2;
		if (k < arr[mid]){
			 right = mid - 1;
		}
		else if (k > arr[mid]){
			 left = mid + 1;
		}
		else {
			return mid;
		}
	}

	return -1;
}

int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};
	int k = 0;
	//数组是有首地址和数组的长度以及有效元素的个数决定的，首地址是可以传递的，长度是不能传递的
	int len = sizeof(arr) / sizeof(arr[0]);//需要在函数中使用数组的长度，只能在主函数中计算好之后再传给形参，在函数中是无法计算数组的长度的

	scanf_s("%d", &k);
	int result = binary_search(arr, k, len);
	if (result == -1){
		cout << "没有找到！" << endl;
	}
	else{
		cout << "result = " << result << endl;
	}
	return 0;
}