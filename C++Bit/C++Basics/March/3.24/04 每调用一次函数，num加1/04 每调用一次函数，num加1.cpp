#include<iostream>
using namespace std;

int Add(int * p){
		return (*p)++;

}
int main(){
	int num = 0;
	Add(&num);
	cout << "num = " << num << endl;
	Add(&num);
	cout << "num = " << num << endl;
	return 0;
}