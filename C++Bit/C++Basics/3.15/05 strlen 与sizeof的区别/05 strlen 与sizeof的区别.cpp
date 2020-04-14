#include<iostream>
using namespace std;

class String{
public:
	String(int age,char name){
		this->age = age;
		this->name = name;
	}
	void getString(){
		cout << "name = " << name << endl;
	}
protected:
private:
	char name;
	int age;
};
int main(){
	//String s1(28, "shangxiaofeng");

	return 0;
}