#include <iostream>
using namespace std;

int isLeapYear(int year){
	if ((year % 4 == 0) && (year % 100 != 0)||(year % 400 ==0 )){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	int count = 0;
	int year = 0;
	for (year = 1000; year <= 2000; year++){
		if (isLeapYear(year) == 1){
			count++;
			printf("%d ", year);
		}
	}
	cout << "闰年的个数：" << count << endl;


	return 0;
}