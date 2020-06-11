#include<iostream>
#include<list>
using namespace std;

void traverse(list<int>& obj){
	list<int>::iterator it = obj.begin();
	while (it != obj.end()){
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

int main01(){
	//链表的构造
	list<int> li1;
	list<int> li2(10);
	list<int> li3(10, 8);
	for (const auto& e:li1){
		cout << e << " ";
	}
	cout << endl;

	for (const auto& e : li2){
		cout << e << " ";
	}
	cout << endl;

	for (const auto& e : li3){
		cout << e << " ";
	}
	cout << endl;

	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	list<int> li4(arr, arr + 10);
	for (const auto& e : li4){
		cout << e << " ";
	}
	cout << endl;

	list<int> li5(li4.begin(), li4.end());
	for (const auto& e:li5){
		cout << e << " ";
	}
	cout << endl;


	return 0;
}

int main02(){
	list<int> li1 = { 1, 2, 3, 4, 5, 6, 8, 9, 10 };
	//对链表的访问 C+11 的for 里面含有begin()  end()
	//采用迭代器的方式访问
	list<int>::iterator it = li1.begin();
	while (it != li1.end()){
		cout << *it << " ";
		it++;
	}
	cout << endl;
	//采用auto自动推导访问
	auto it1 = li1.begin();
	while (it1 != li1.end()){
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;
	//逆向迭代器的使用,因为是双向链表 所有可以实现  单项链表示不可以这样实现的
	list<int>::reverse_iterator it2 = li1.rbegin();
	while (it2 != li1.rend()){
		cout << *it2 << " ";
		it2++;
	}
	cout << endl;
	//逆向实现的方法 2 采用逆向遍历 是第一种方法实现的原理
	auto it3 = li1.end();
	--it3;
	while (it3 != li1.begin()){
		cout << *it3 << " ";
		--it3;
	}
	cout << *it3;
	

	cout<< endl;
	return 0;
}

int main03(){
	list<int> li1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//求元素的个数
	cout << "size = " << li1.size() << endl;
	//返回链表中的第一个节点的值
	cout << "链表中第一个元素的值：" << li1.front() << endl;
	//返回链表中最后一个节点的值
	cout << "链表中最后一个元素的值：" << li1.back() << endl;
	//判断是否为空
	if (li1.empty()){
		cout << "list is empty" << endl;
	}
	else{
		cout << "逆向遍历：" << endl;
		for (list<int>::reverse_iterator rit = li1.rbegin(); rit != li1.rend(); ++rit){
			cout << *rit << " ";
		}
		cout << endl;
		cout << "顺序遍历：" << endl;
		list<int>::iterator it = li1.begin();
		while (it != li1.end()){
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}
	cout << "链表的头插、尾插 实现:" << endl;
	li1.push_front(0);
	li1.push_back(11);
	li1.insert(li1.begin(), 0);
	li1.insert(li1.end(), 22);
	traverse(li1);
	cout << "在链表中的位置插入：" << endl;
	auto pos = find(li1.begin(), li1.end(), 8);//利用find 查找到相关的位置 然后在该位置的前面插入您想要插入的数据
	li1.insert(pos, 77);
	traverse(li1);
	cout << "链表的头删尾部删除的实现：" << endl;
	li1.pop_front();
	li1.pop_back();
	traverse(li1);
	cout << "删除中间的值：" << endl;
	auto poss = find(li1.begin(), li1.end(), 77);
	li1.erase(poss);
	li1.erase(li1.begin());
	li1.erase(--li1.end());
	traverse(li1);
	return 0;
}


int main04(){
	list<int> li1 = { 1, 2, 3, 4};
	list<int> li2 = { 5, 6, 7, 8, 9, 10 };
	li1.swap(li2);//交换两个链表
	traverse(li1);
	traverse(li2);

	li1.clear();
	traverse(li1);

	return 0;
}

int main05(){
	list<int> li1 = { 1, 2, 3, 4 ,5,6,7,8,9,11,44,33,66};
	li1.remove(4);//直接移除 不需要找到迭代器的位置
	li1.remove(2);
	//li1.remove_if(1);//条件删除 需要绑定器 以后再论
	traverse(li1);
	cout << "排序的实现：" << endl;
	li1.sort();
	traverse(li1);
	list<int> li2 = { 88, 99, 100, 111 };
	cout << "合并的实现（合并之前两个必须是有序的（升序））:" << endl;
	li1.merge(li2);
	traverse(li1);
	auto pos = find(li1.begin(), li1.end(), 100);
	cout << *pos << endl;
	li1.erase(pos);
	traverse(li1);
	//cout << *pos << endl; error 由于对迭代器的pos位置的节点进行删除，删除后节点不存在，再次访问该节点，会造成迭代器节点失效
	//如何避免上述的迭代器节点失效的情况呢 那就是将删除后节点的位置返回
	auto poss = find(li1.begin(), li1.end(), 111);
	poss = li1.erase(poss);
	//cout << *poss << endl;
	traverse(li1);
	return 0;
}

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
	bit::list<int> lt1 = { 1, 2, 3, 4, 5, 6};
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

