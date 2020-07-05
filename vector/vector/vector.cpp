//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int main()
//{
//	//vector定义
//	//// constructors used in the same order as described above:
//	//std::vector<int> first; // empty vector of ints
//	//std::vector<int> second(4, 100); // four ints with value 100
//	//std::vector<int> third(second.begin(), second.end()); // iterating through second
//	//std::vector<int> fourth(third);//拷贝构造
//
//	////vector迭代器
//	//// 使用push_back插入4个数据
	/*vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	cout << v.size() << endl;
	v.pop_back();
	cout << v.size() << endl;

	v.insert(v.begin(), 0);
	for (auto e : v)
		cout << e << " ";
	cout << endl;*/
//	//// 使用迭代器进行遍历打印
//	//vector<int>::iterator it = v.begin();
//	//while (it != v.end())
//	//{
//	//	cout << *it << " ";
//	//	++it;
//	//}
//	//cout << endl;
//	//// 使用迭代器进行修改
//	//it = v.begin();
//	//while (it != v.end())
//	//{
//	//	*it += 2;
//	//	++it;
//	//}
//	//// 使用反向迭代器进行遍历再打印
//	//vector<int>::reverse_iterator rit = v.rbegin();
//	//while (rit != v.rend())
//	//{
//	//	cout << *rit << " ";
//	//	++rit;
//	//}
//
//	// vector 空间增长问题
//	///*size_t sz;
//	//std::vector<int> foo;
//	//sz = foo.capacity();
//	//std::cout << "making foo grow:\n";
//	//for (int i = 0; i<100; ++i) {
//	//	foo.push_back(i);
//	//	if (sz != foo.capacity()) {
//	//		sz = foo.capacity();
//	//		std::cout << "capacity changed: " << sz << '\n';
//	//	}
//	//}*/
//	//std::vector<int> bar;
//	//size_t sz = bar.capacity();
//	//bar.reserve(100); 
//	//std::cout << "making bar grow:\n";
//	//for (int i = 0; i<100; ++i) {
//	//	bar.push_back(i);
//	//	if (sz != bar.capacity()) {
//	//		sz = bar.capacity();
//	//		std::cout << "capacity changed: " << sz << '\n';
//	//	}
//	//}
//
//	//std::vector<int> myvector;
//	// set some initial content:
//	//for (int i = 1; i<10; i++)
//	//	myvector.push_back(i);
//	//myvector.resize(5);//newsize<oldzize直接将有效元素个数减少到newsize，结果为1 2 3 4 5
//	//myvector.resize(8, 100);//oldsize<newsize<=capacity直接将有效元素个数增大到newsize，多出的元素使用data填充，结果为1 2 3 4 5 100 100 100
//	//myvector.resize(12);//newsize>capacity直接将有效元素个数增大到newsize,扩容到newsize，多出的元素用0填充（data为内置类型）
//	//std::cout << "myvector contains:";
//	//for (int i = 0; i<myvector.size(); i++)
//	//	std::cout << ' ' << myvector[i];//结果为1 2 3 4 5 100 100 100 0 0 0 0
//	//std::cout << '\n';
//
//	// vector 增删查改
//	/*int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	vector<int>::iterator it = v.begin();
//	while (it != v.end()) {
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	v.pop_back();
//	v.pop_back();
//	it = v.begin();
//	while (it != v.end()) {
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	return 0;*/
//
//	//int a[] = { 1, 2, 3, 4 };
//	//vector<int> v(a, a + sizeof(a) / sizeof(int));
//	//// 使用find查找3所在位置的iterator
//	//vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//	//// 在pos位置之前插入30
//	//v.insert(pos, 30);
//	//vector<int>::iterator it = v.begin();
//	//while (it != v.end()) {
//	//	cout << *it << " ";
//	//	++it;
//	//}
//	//cout << endl;
//	//pos = find(v.begin(), v.end(), 3);
//	//// 删除pos位置的数据
//	//v.erase(pos);
//	//it = v.begin();
//	//while (it != v.end()) {
//	//	cout << *it << " ";
//	//	++it;
//	//}
//	//cout << endl;
//	//return 0;
//
//	// operator[]+index 和 C++11中vector的新式for+auto的遍历
//	// vector使用这两种遍历方式是比较便捷的。
//	//int a[] = { 1, 2, 3, 4 };
//	//vector<int> v(a, a + sizeof(a) / sizeof(int));
//	//// 通过[]读写第0个位置。
//	//v[0] = 10;
//	//cout << v[0] << endl;
//	//// 通过[i]的方式遍历vector
//	//for (size_t i = 0; i < v.size(); ++i)
//	//	cout << v[i] << " ";
//	//cout << endl;
//	//vector<int> swapv;
//	//swapv.swap(v);
//	//cout << "v data:";
//	//for (size_t i = 0; i < v.size(); ++i)
//	//	cout << v[i] << " ";
//	//cout << endl;
//	//cout << "swapv data:";
//	//for (size_t i = 0; i < swapv.size(); ++i)
//	//	cout << swapv[i] << " ";
//	//cout << endl;
//	//// C++11支持的新式范围for遍历
//	//for (auto x : swapv)
//	//	cout << x << " ";
//	//cout << endl;
//	//return 0;
//}

//模拟实现
#include <iostream>
#include <assert.h>
using namespace std;
namespace bit
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}

		vector(const vector<T>& v)
		{
			_start = new T[v.size()];
			memcpy(_start, v._start, sizeof(T)*v.size());
			_finish = _start + v.size();
			_end_of_storage = _start + v.size();
		}

		// v1 = v2
		vector<T>& operator=(vector<T> v)
		{
			//this->swap(v);
			swap(v);
			return *this;
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

		// v1.swap(v2)
		void swap(vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_end_of_storage, v._end_of_storage);
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		void resize(size_t n, const T& val = T())
		{
			// 1.如果n小于当前的size，则有效数据个数缩小到n
			if (n < size())
			{
				_finish = _start + n;
				return;
			}
			// 2.空间不够则增容
			if (n > capacity())
			{
				reserve(n);
			}
			// 3.将size扩大到n
			while (_finish != _start + n)
			{
				*_finish = val;
				++_finish;
			}
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T)*sz);
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}

		void push_back(const T& x)
		{
			/*	if (_finish == _end_of_storage)
			{
			size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
			reserve(newcapacity);
			}

			*_finish = x;
			++_finish;*/
			insert(end(), x);
		}

		void pop_back()
		{
			//assert(_finish > _start);
			//--_finish;
			erase(--end());
		}

		//void insert(iterator& pos, const T& x)
		void insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);

			if (_finish == _end_of_storage)
			{
				size_t n = pos - _start;
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + n;
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}

			*pos = x;
			++_finish;
		}

		void erase(iterator pos)
		{
			assert(pos < _finish && pos >= _start);
			iterator begin = pos + 1;
			while (begin < _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}

			--_finish;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		T& operator[](size_t pos)
		{
			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			return _start[pos];
		}
	private:
		//T* _a;
		//size_t _size;
		//size_t _capacity;		
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

	
}
void test_vector1()
{
	    bit::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		auto it = v.begin();
		v.insert(it, 0);
		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		it = v.begin();
		v.erase(it);
		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		bit::vector<int>::iterator iter = v.begin();
		while (iter != v.end())
		{
			cout << *iter << " ";
			++iter;
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
}

void test_vector2()
{
		bit::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		bit::vector<int> copy(v);
		for (auto e : copy)
		{
			cout << e << " ";
		}
		cout << endl;
}
int main()
{
		test_vector2();
		return 0;
}