#include<iostream>
using namespace std;

class Demo {
public:
	Demo() :count(0) {}
	~Demo() {}

	void say(const std::string&msg) {
		fprintf(stderr, "%s\n", msg.c_str());
	}
private:
	int count;
};

int main(int argc, char **argv) {
	Demo* v = NULL;
	v->say("hello world");
}
