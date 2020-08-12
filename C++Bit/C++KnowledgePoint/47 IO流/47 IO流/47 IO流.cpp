#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

//文本的读写
int main01(){
	vector<int> iv = { 12, 3, 4, 5, 6, 7, 7, 8, 9, 9, 10 };
	FILE *file = fopen("text.txt", "w");

	if (file == NULL){
		cerr << "filed error." << endl;
		exit(1);
	}

	for (const auto &e : iv){
		fprintf(file, "%d", e);
	}
	fclose(file);

	return 0;
}

int main02(){
	vector<int> iv = { 2, 4, 6, 8, 9, 0, 32 };

	fstream ofile;
	ofile.open("text2.txt", ios::out);
	if (!ofile){
		cerr << "filed error." << endl;
		exit(1);
	}

	for (const auto &e : iv){
		ofile << e << " ";
	}
	cout << endl;
	ofile.close();
	return 0;
}


int main03(){
	vector<int> iv;
	FILE *file = fopen("text.txt", "r");
	if (file == NULL){
		cerr << "failed error" << endl;
		exit(-1);
	}
	int val;
	for (int i = 0; i < 10; ++i){
		fscanf(file, "%d", &val);
		iv.push_back(val);
	}
	fclose(file);


	return 0;
}


int main04(){
	vector<int> iv;

	fstream ifile;
	ifile.open("text2.txt", ios::out);
	if (!ifile){
		cerr << "filed error." << endl;
		exit(1);
	}

	int val;
	for (int i = 0; i < 10; ++i){
		ifile >> val;
		iv.push_back(val);
	}
	ifile.close();
	return 0;
}

//c 写入文件 二进制文件
int main05(){
	vector<int>  iv = { 1, 3, 4, 5, 4, 3, 2, 2, 22, 3, 4, 5, 5, 4, 3, 90 };
	FILE*file = fopen("text3.txt", "wb");

	if (file == NULL){
		printf("failed error.\n");
		exit(1);
	}

	//方式1
	//fwrite(&iv[0], sizeof(int), iv.size(), file);

	//方式2
	for (const auto &e : iv){
		fprintf(file, "%d", e);
	}
	return 0;
}

//c语言读出来

int main06(){
	vector<int> iv(10);
	FILE* file = fopen("text4.txt", "rb");
	if (file == NULL){
		printf("failed error .\n");
		exit(1);
	}

	fread(&iv[0], sizeof(int), 10, file);

	return 0;
}




//c++ 写入硬盘
int main07(){
	vector<int> iv = { 2, 3, 4, 6, 7, 8, 89, 90, 10 };
	ofstream ofile("text5.txt", ios::out || ios::binary);//c++的输出形式
	if (!ofile){
		printf("failed error .\n");
		exit(1);
	}

	ofile.write((const char*)&iv[0], sizeof(int)*iv.size());

	return 0;
}

//使用文件IO流用文本及二进制方式演示读写配置文件
struct ServerInfo{
	char _ip[32];  // ip
	int  _port;    // 端口
};

class ConfigManager{
public:
	ConfigManager(string str) :_configfile(str)
	{
		ReadSerInfo();
	}
	~ConfigManager()
	{
		WriteSerInfo();
	}
public:
	void ReadSerInfo()
	{
		ifstream ifile;
		ifile.open(_configfile.c_str(), ios::in);
		if (!ifile)
		{
			cerr << "Open File Error." << endl;
			exit(1);
		}
		ifile >> ser_info._ip >> ser_info._port;
		ifile.close();
	}
	void WriteSerInfo()
	{
		ofstream ofile;
		ofile.open(_configfile.c_str(), ios::out);
		if (!ofile)
		{
			cerr << "Open File Error." << endl;
			exit(1);
		}
		ofile << ser_info._ip << " " << ser_info._port;
		ofile.close();
	}
	void set_info(string ip, int port)
	{
		strcpy(ser_info._ip, ip.c_str());
		ser_info._port = port;
	} 
public:
	void show_info()const{
		cout << "ip = " << ser_info._ip << endl;
		cout << "port = " << ser_info._port << endl;
	}
private:
	string _configfile;
	ServerInfo ser_info;
};

void main08(){
	ConfigManager cfmgr("bit.conf");
	cfmgr.show_info();
	cfmgr.set_info("10.182.1.212", 9999);
	cfmgr.show_info();
}


int main09(){

	char* str = "12345678";
	cout << "str = " << str << endl;

	int value = atoi(str); //atoi();函数将一个整形的字符串“274392749” 转化成 一个整数,保证能够容纳
	cout << "value = " << value << endl;
	return 0;
}
 
//在c++使用字符串流 stringStream
int main10(){
	int a = 4719411;
	stringstream sstream;
	sstream << a;

	string str;
	sstream >> str;
	cout << "str = " << str << endl;
	return 0;
}


int main(){
	string str = "383749849";
	stringstream sstream;
	sstream << str;
	int a;
	sstream >> a;
	cout << "a = " << a << endl;
	return 0;
}
