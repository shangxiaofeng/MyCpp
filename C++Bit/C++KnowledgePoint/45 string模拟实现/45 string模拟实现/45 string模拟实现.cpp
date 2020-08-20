#include<iostream>
#include<assert.h>
#include<string>
using namespace std;

namespace bit{
	class string {
	public:
		friend ostream& operator<< (ostream& out,  string& obj);
		//构造函数
		string(const char* str = ""){
			if (str == nullptr){
				_str = new char[1];
				_str = '\0';
				_capacity = _size = 0;
			}
			else{
				_size = _capacity = strlen(str);
				_str = new char[_size + 1];
				strcpy(_str, str);
			}
		}
		//拷贝构造函数
		string(const string&  obj):_str(nullptr),_capacity(0),_size(0){
			string temp(obj._str);
			swap(temp);//this->swap(temp);

					//以前的写法
				/*	_capacity = _size = strlen(obj._str);
					_str = new char[_size + 1];
					strcpy(_str, obj._str);*/	
		}
		~string()
		{
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
				_capacity = _size = 0;
			}
		}
	public:
		void reserve(size_t n = 0){
			if (n > _capacity){
				char* newStr = new char[n + 1];
				strcpy(newStr, _str);
				delete[] _str;
				_str = newStr;
				_capacity = n;
			}
		}
		void resize(size_t n,char c = '\0'){
			if (n > _size){
				if (n > _capacity){
					reserve(n * 2);
				}
				memset(_str + _size, c, n - _size);
			}
			_size = n;
			_str[n] = '\0';
		}
	public:
		void swap(string & s){
			std::swap(_str, s._str);
			std::swap(_capacity, s._capacity);
			std::swap(_size, s._size);
		}
		size_t size(){
			return _size;
		}
		size_t capacity(){
			return _capacity;
		}
		size_t length(){
			return _size;
		}
		void clear(){
			_str = '\0';
			_capacity = _size = 0;
		}
		bool empty(){
			if (_size == 0){
				return true;
			}
			else{
				return false;
			}
		}
		void append(const string& obj){
			(*this) += obj._str;
		}
		char& operator[](int index){
			assert(index >= 0 && index < _size);
			return _str[index];
		}
		void push_back(char ch)
		{
			if (_size >= _capacity)
				reserve(_capacity * 2);
			_str[_size++] = ch;
			_str[_size] = '\0';
		}
	public:
		string& operator=(string obj){
			swap(obj);
			return *this;
		}
		string operator+=(const string& obj){
			size_t len = strlen(obj._str);
			if (_size + len > _capacity){
				reserve((_size + len) * 2);
			}
			strcat(_str, obj._str);
			_size += len;
			return *this;
		}
		bool operator<(const string& s){
			return (strcmp(_str, s._str)) < 0;
		}
		bool operator>(const string& s){
			return (strcmp(_str, s._str)) > 0;
		}
		bool operator>=(const string& s){
			return !(*this < s);
		}
		bool operator<=(const string& s){
			return !(*this > s);
		}	
		bool operator==(const string& obj){
			return (strcmp(_str, obj._str)== 0);
		}
		bool operator!=(const string& obj){
			return (!strcmp(_str, obj._str) == 0);
		}
		public:
			//查找某一个字符的位置
			size_t find(char c,size_t pos = 0)const{
				for (size_t i = 0; i < _size; ++i){
					if (_str[i] == c){
						return i;
					}
				}
				cout << "未找到！" << endl;
				//return npos; //error 
				return pos;
			}
			//查找字符串的位置 find（）
			size_t find(const char* obj, size_t pos = 0)const{
				assert(obj != NULL);
				const char* str = _str + pos;
				while (*str != '\0'){
					const char* cur = str;
					const char* sub = obj;
					while (*sub != '\0' && *sub == *cur){
						cur++;
						sub++;
					}
					if (*sub == '\0'){
						return str - _str;
					}
					else{
						str++;
					}
				}

				return -1;
			}
			//在指定的位置插入字符 然后返回字符串
			string& insert(size_t pos, char c){
				assert(pos >= 0 && pos <= _size);
				if (_size + 1 > _capacity){
					reserve(_capacity * 2);
				}
				for (size_t i = _size; i >= pos; --i){
					_str[i + 1] = _str[i];
				}
				_str[pos] = c;
				_size++;
				return *this;
			}
			//在指定的位置插入字符  串 ， 然后返回正个字符串
			string& insert(size_t pos, const char* obj){

			}

	private:
		char* _str;
		size_t _capacity;//空间
		size_t _size;//有效的长度
	};
}
//重载《《
ostream& bit::operator<<(ostream& out, bit::string& obj){
	out << obj._str;
	/*for (int i = 0; i < obj.size(); ++i){
	out << obj[i];
	}*/
	return out;
}

int main(){
	bit::string str(nullptr);//定义一个空的字符串
	bit::string str1("xiaofeng");
	bit::string str2(str1);//等价于bit::string str2 = str1;
	bit::string str3("xuanxiaoxuan");
	 str1 += str2;
	cout << "str1 :" << str1 << endl;
	str1.append("shi");
	cout << "str1:" << str1 << endl;
	cout << "str1.capacity():" << str1.capacity() << endl;
	cout << "str1.empty():" << str1.empty() << endl;
	cout << "str1.length():" << str1.size() << endl;
	str1.push_back('X');
	cout << "str1 :" << str1 << endl;
	if (str3 > str2){
		cout << "str3>str2" << endl;
	}
	else{
		cout << "str3<=str2" << endl;
	}
	if (str3 == str2){
		cout << "str3=str2" << endl;
	}
	else{
		cout << "str3!=str2" << endl;
	}
	cout << "str3.find('f'):" << str3.find('f') << endl;
	size_t pos = str3.find("xiao");
	cout << "pos = " << pos << endl;
	str3.insert(3, 'y');
	cout << "str3: " << str3 << endl;
	return 0;
}







//bit::string str1("abc");
//bit::string str2("xyz");
//bit::string str3(str2);
//str3 = str1;
//cout << str2 << endl;
//cout << "capacity:" << str2.capacity() << endl;
//bit::string str4(nullptr);
//str4 += str1;
//cout << "str4 = " << str4 << endl;
//class string{
//	friend ostream& operator<<(ostream& out,  string& obj);
//public:
//	//构造函数 初始化为空 
//	string(const char* str = ""){
//		//初始化首先判断是否为空 ，为空分配一个空的空间
//		if (nullptr == str){
//			_str = new char[1];
//			_str = '\0';
//			_capacity = _size = 0;
//		}	
//		else{
//			_capacity = _size = strlen(str);
//			_str = new char[strlen(str) + 1];
//			strcpy(_str, str);
//		}
//	}
//	
//	//拷贝构造函数的实现
//	string(const string &s){
//		_str = new char[strlen(s._str) + 1];
//		strcpy(_str, s._str);
//	}
//	//赋值构造函数的实现（较之前的三步走要更安全）重载=号
//	//str3 = str1;这里的s是 str1
//	string& operator=(const string &s){
//		if (this != &s){
//			string tmp_str(s);    //临时对象
//			swap(_str, tmp_str._str);
//		}
//		return *this;
//	}
//	~string(){
//		if (_str){
//			delete[] _str;
//			_str = nullptr;
//			_capacity = _size = 0;
//		}
//	}
//public:
//	size_t size(){
//		return _size;
//	}
//	size_t length()const{
//		return _size;
//	}
//	size_t capacity(){
//		return _capacity;
//	}
//	bool empty(){
//		return _size = 0;
//	}
//public:
//	//当n> capacity 时候，就重新分配空间
//	void reserve(size_t n = 0){
//		if (n > _capacity){
//			char* new_str = new char[n + 1];
//			strcpy(new_str, _str);
//			delete[] _str;
//			_str = new_str;
//			_capacity = n;
//		}
//	}
////尾插
//	void push_back(char ch){
//		if (_size >= _capacity){
//			reserve(_capacity * 2);
//			_str[_size++] = ch;
//			_str[_size] = '\0';
//		}
//	}
//public:
//	//重载【】
//	const char& operator[](size_t index)const{
//		assert(index < _size);
//		return _str[index];
//	}
//	string& operator+=(const string& obj){
//		this->_str++;
//		
//		return *this;
//	}
//	string& operator+=(char ch){

//	}
//	void append(string& obj){

//	}
//	void clear(){
//		_str = '\0';
//		_size = 0;
//	}
//	const char* c_str()const {
//		return _str;
//	}
//	void resize(size_t n, char c = '\0'){
//		 
//	}