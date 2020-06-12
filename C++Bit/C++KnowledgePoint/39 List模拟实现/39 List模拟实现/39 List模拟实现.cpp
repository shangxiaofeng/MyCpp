#include<iostream>
using namespace std;

namespace bit{
	template<class T>
	class list;//申明list类 

	template<class T>
	class ListIterator;//声明listIterator

	//定义一个节点
	template<class T>
	class ListNode{
		friend class list<T>;//声明为友元类 
		friend class ListIterator<T>;
	public:
		ListNode(T data = T()) :next(nullptr), prev(nullptr), value(data){
		}
		~ListNode(){
		}
	private:
		ListNode *next;
		ListNode *prev;
		T         value;
	};

	//定义迭代器
	template<class T>
	class ListIterator{
	public:
		typedef ListNode<T>* PNode;
		typedef ListIterator<T> slef;
	public:
		ListIterator(PNode _P) : _Ptr(_P){
		}
		PNode Mynode()const{
			return _Ptr;
		}
	public:
		T& operator*()const{
			return _Ptr->value;
		}
		slef& operator++(){
			_Ptr = _Ptr->next;
			return *this;
		}
		slef& operator--(){
			_Ptr = _Ptr->prev;
			return *this;
		}
		bool operator!=(const slef &lt){
			return _Ptr != lt._Ptr;
		}
		bool operator==(const slef &lt){
			return _Ptr == lt._Ptr;
		}
	private:
		PNode _Ptr;
	};

	template<class T>
	class list{
	public:
		typedef ListNode<T>* PNode;
		typedef ListIterator<T> iterator;
	public:
		list(){
			CreateHead();
		}
		list(int n, const T &v = T()){
			CreateHead();
			for (int i = 0; i<n; ++i)
				push_back(v);
		}
		template<class _It>
		list(_It first, _It last){
			CreateHead();
			while (first != last){
				push_back(*first);
				++first;
			}
		}
		list(initializer_list<T> il){
			CreateHead();
			for (const auto &e : il)
				push_back(e);
		}
		list(list<T> &lt){
			CreateHead();
			list tmp_list(lt.begin(), lt.end());
			swap(tmp_list);
		}
		~list(){
			clear();
			delete _pHead;
			_pHead = nullptr;
		}
	public:
		void push_back(const T&x){
			insert(end(), x);
		}
		void push_front(const T&x){
			insert(begin(), x);
		}
		void pop_back(){
			erase(--end());
		}
		void pop_front(){
			erase(begin());
		}
		void swap(list<T> &lt){
			std::swap(_pHead, lt._pHead);
		}
		void clear(){
			erase(begin(), end());
		}
	public:
		iterator begin(){
			return iterator(_pHead->next);
		}
		iterator end(){
			return iterator(_pHead);
		}
	public:
		iterator insert(iterator pos, const T &x){
			PNode s = new ListNode<T>(x);
			PNode p = pos.Mynode();
			s->next = p;
			s->prev = p->prev;
			s->prev->next = s;
			s->next->prev = s;
			return iterator(s);
		}
		void erase(iterator first, iterator last){
			while (first != last){
				first = erase(first);
			}
		}
		iterator erase(iterator pos){
			PNode p = pos.Mynode();
			PNode q = p->next;
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			return iterator(q);
		}
	protected:
		void CreateHead(){
			_pHead = new ListNode<T>;
			_pHead->next = _pHead->prev = _pHead;
		}
	private:
		PNode _pHead;
	};
};

void main(){
	bit::list<int> lt1 = { 1, 2, 3, 4, 5, 6 };
	cout << "lt1 = ";
	for (const auto &e : lt1)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;

	//bit::list<int> lt2 = lt1;
	//lt1.erase(lt1.begin());
	//lt1.pop_front();
	//lt1.pop_back();

	lt1.clear();
	cout << "lt1 = ";
	for (const auto &e : lt1)
		cout << e << " ";
	cout << endl;
}

