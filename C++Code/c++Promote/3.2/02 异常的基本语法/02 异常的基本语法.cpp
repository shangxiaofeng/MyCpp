#include<iostream>
using namespace std;

void divide(int x, int y){
	if (y == 0){
		throw x;//抛出int类型异常
	}
	cout<<"divide:" << x / y << endl; 
}




int main(){
	try {
		divide(10, 8);
		divide(100, 0);
	}
	catch (int e){
		cout << e <<"被零除"<< endl;
	}
	catch (...){
		cout << "其他未知类型异常" << endl; 
	}

	return 0;
}