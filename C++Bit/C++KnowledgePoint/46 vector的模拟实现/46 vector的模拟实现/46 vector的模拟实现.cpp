#include <iostream>
#include <vector>
using namespace std;
/*
int main01(){
	vector<int> v1 = { 1, 3, 4, 5, 6, 7, 8, 990 };
	for (const auto& e : v1){
		cout << e << " ";
	}
	cout << endl;

	vector<int>::iterator it = v1.begin();
	while (it != v1.end()){
		cout << *it << " ";
		it++;
	}
	cout << endl;

	return 0;
}

int main02(){
	vector<int> v1 = { 1, 2, 4, 5, 6, 7, 8, 9, 0, 06, 90 };
	vector<int>::reverse_iterator rit = v1.rbegin();
	while (rit != v1.rend()){
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
	v1.push_back(111);
	v1.pop_back();
	//为什么没有头插入？？？
	//v1.push_front(400);//error
	v1.insert(v1.begin(), 200);//给定位置插入 即可  效率不是很高
	v1.erase(v1.begin());
	auto pos = find(v1.begin(), v1.end(),6);
	if (pos != v1.end()){
		v1.erase(pos);
	}
	else{
		cout << "删除数据不成功！" << endl;
	}

	vector<int>::iterator it = v1.begin();
	while (it != v1.end()){
		cout << *it << " ";
		it++;
	}
	cout << endl;

	return 0;
}

*/

namespace myslam{
	template<class T>
	class vector{
	public:
		typedef T* iterator;
	public:
		vector() :_start(nullptr), _finish(nullptr), _endofStorage(nullptr){}
		~vector(){
			delete[] _start;
			_start = _finish = _endofStorage = nullptr;
		}
	public:
		size_t size(){
			return _finish - _start;
		}
		size_t capacity()const{
			return _endofStorage - _start;
		}
		bool empty(){
			return _start == _finish;
		}
	public:
		void reserve(size_t n){
			if (n > capacity()){
				size_t old_size = size();
				T *new_start = new T[n];
				for (int i = 0; i < old_size; ++i){
					new_start[i] = _start[i];
				}
				delete[] _start;
				_start = new_start;
				_finish = _start + old_size;
				_endofStorage = _start + n;
			}
		}
		iterator insert(iterator pos, const T& x){
			if (size() > capacity()){
				//扩容
				size_t offset = pos - _start;
				size_t new_capacity = (capacity() == 0) ? 1 : capacity() * 2;
				reserve(new_capacity);
				//更新失效的pos迭代器
				pos = _start + offset;
			}
			iterator end = _finish;
			while (end > pos){
				*end = *(end - 1);
				end--;
			}
			*end = x;
			_finish++;
			return pos;
		}
		void push_back(const T& x){
			insert(end(), x);
		}
		//删除迭代器所=指的位置
		iterator erase(iterator pos){
			iterator p = pos;
			while (p < _finish - 1){
				*p = *(p + 1);
				p++;
			}
			_finish--;
			return pos;
		}
	public:
		iterator begin(){
			return _start;
		}
		iterator end(){
			return _finish;
		}
	public:
		void swap(vector<T> &v){
		std::swap(_start, v._start);
		std::swap()

		}
	private:
		iterator _start; 
		iterator _finish;
		iterator _endofStorage;
	};
}


int main(){
	myslam::vector<int> iv;
	cout << "iv.capacity() = "<<iv.capacity() << endl;
	cout << "iv.size() = "<<iv.capacity() << endl;
	iv.reserve(10);
	iv.insert(iv.begin(), 1);
	iv.insert(iv.begin(), 2);
	iv.insert(iv.begin(), 3);
	iv.insert(iv.begin(), 4);
	iv.push_back(2);
	for (const auto& e : iv){
		cout << e << " ";
	}
	cout << endl;
	iv.erase(iv.begin());
	for (const auto& e : iv){
		cout << e << " ";
	}
	cout << endl;
	auto pos = find(iv.begin(), iv.end(), 3);
	iv.erase(pos);
	return 0;
}