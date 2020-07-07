//#include<iostream>
//using namespace std;
#if 0
namespace bite//深拷贝传统写法
{
	//string类：动态类型的顺序表
	class string
	{
	public:
		/*string(const char*str ="")
		{
			if (nullptr == str)
			{
				//构造空的字符串""：是一个有效的字符串，只不过该字符串只包含了一个'\0'
				_str = new char[1];
				*_str = '\0';
				//将\0放置到字符串空间中
				//_str：是一个指针，该指针指向了堆上的一个字符空间
				//*_str:是_str指针指向空间中的内容，该空间在堆上，里面可以放置一个字符
				//'0' 字符0
				//'\0' ---转义字符，将'0'转换数字0
				//'\0'==数字0是等价的
				//_str = '\0';//_str=0;_str=nullptr
				//_str = 0;//_str=nullptr
				//*_str = '0';//_str指向的空间中放的不是\0是0
				//*_str = 0;//可以--但是代码可读性差
				//*_str = '\0';//可以
				//_str = "";//不行，会导致开始的单个字符的空间丢失
			}
			else
			{
				_str = new char[strlen(str) + 1];//strlen没算'\0'
				strcpy(_str, str);
			}
		}*/
		//浅拷贝：多个对象共享同一份资源，最后导致同一份资源释放多次引起程序崩溃
		//深拷贝：不要与其他对象共用资源，每个对象都拥有一份资源
		string(const char*str = "")//构造函数
		{
			if (nullptr == str)
			{
				str = "";
			}
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		string(const string&s)//拷贝构造函数
			:_str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
		}
		string &operator=(const string&s)//赋值运算符重载
		{
			if (this != &s)
			{
				//1、开辟新空间
				char *tmp = new char[strlen(s._str) + 1];
				//2、拷贝到新空间
				strcpy(tmp, s._str);
				//3、释放旧空间
				delete[] _str;
				//4、赋值
				_str = tmp;
			}
			return *this;
		}
		~string()//析构函数
		{
			if (_str)
			{
				delete[]  _str;
				_str = nullptr;
			}
		}
	private:
		char *_str;
	};

}
void Teststring()
{
	bite::string s1;
	bite::string s2("helloworld");
	bite::string s3(s2);//string类：并没有显示提供拷贝构造函数，编译器在编一阶段会生成一份默认的拷贝构造函数--将
	//一个对象中的内容原封不动的拷贝到一个新对象中---值的拷贝--简称“浅拷贝”
	s1 = s2;
}
int main()
{
	Teststring();
	return 0;
}
#endif

//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	////string类对象的容量操作
//	//// 注意：string类对象支持直接用cin和cout进行输入和输出
//	//string s("hello, bit!!!");
//	//cout << s.size() << endl;
//	//cout << s.length() << endl;
//	//cout << s.capacity() << endl;
//	//cout << s << endl;
//
//	//// 将s中的字符串清空，注意清空时只是将size清0，不改变底层空间的大小
//	//s.clear();
//	//cout << s.size() << endl;
//	//cout << s.capacity() << endl;
//
//	//// 将s中有效字符个数增加到10个，多出位置用'a'进行填充
//	//// “aaaaaaaaaa”
//	//s.resize(10, 'a');
//	//cout << s.size() << endl;
//	//cout << s.capacity() << endl;
//
//	//// 将s中有效字符个数增加到15个，多出位置用缺省值'\0'进行填充
//	//// "aaaaaaaaaa\0\0\0\0\0"
//	//// 注意此时s中有效字符个数已经增加到15个
//	//s.resize(15);
//	//cout << s.size() << endl;
//	//cout << s.capacity() << endl;
//	//cout << s << endl;
//
//	//// 将s中有效字符个数缩小到5个
//	//s.resize(5);
//	//cout << s.size() << endl;
//	//cout << s.capacity() << endl;
//	//cout << s << endl;
//
//	//string s;
//	//// 测试reserve是否会改变string中有效元素个数
//	//s.reserve(100);
//	//cout << s.size() << endl;
//	//cout << s.capacity() << endl;
//	//// 测试reserve参数小于string的底层空间大小时，是否会将空间缩小
//	//s.reserve(50);
//	//cout << s.size() << endl;
//	//cout << s.capacity() << endl;
//
//	////string类对象的访问及遍历操作
//	//string s("hello Bit");
//	//// 3种遍历方式：
//	//// 需要注意的以下三种方式除了遍历string对象，还可以遍历时修改string中的字符，
//	//// 另外以下三种方式对于string而言，第一种使用最多
//	//// 1. for+operator[]
//	//for (size_t i = 0; i < s.size(); ++i)
//	//	cout << s[i] << endl;
//	// //2.迭代器
//	//string::iterator it = s.begin();
//	//while (it != s.end())
//	//{
//	//	cout << *it << endl;
//	//	++it;
//	//}
//	// //3.范围for
//	//for (auto ch : s)
//	//	cout << ch << endl;
//
//	//string类对象的修改操作
//	//string str;
//	//str.append("hello"); // 在str后追加一个字符"hello"
//	//str.push_back(' '); // 在str后插入空格
//	//str += 'b'; // 在str后追加一个字符'b'
//	//str += "it"; // 在str后追加一个字符串"it"
//	//cout << str << endl;
//	//cout << str.c_str() << endl; // 以C语言的方式打印字符串
//	// 获取file的后缀
//	//string file1("string.cpp");
//	//size_t pos = file1.rfind('.');
//	//string suffix(file1.substr(pos, file1.size() - pos));
//	//cout << suffix << endl;
//	// npos是string里面的一个静态成员变量
//	// static const size_t npos = -1;
//	// 取出url中的域名
//	//string url("http://www.cplusplus.com/reference/string/string/find/");
//	//cout << url << endl;
//	//size_t start = url.find("://");
//	//if (start == string::npos)
//	//{
//	//	cout << "invalid url" << endl;
//	//	return 0;
//	//}
//	//start += 3;
//	//size_t finish = url.find('/', start);
//	//string address = url.substr(start, finish - start);
//	//cout << address << endl;
//	// 删除url的协议前缀
//	//pos = url.find("://");
//	//url.erase(0, pos + 3);
//	//cout << url << endl;
//}

#include<iostream>
#include <assert.h>
using namespace std;

// 深浅拷贝问题
//namespace bit
//{
//	class string
//	{
//	public:
//		/*	string()
//				:_str(new char[1])
//				{
//				*_str = '\0';
//				}*/
//
//		//string(const char* str = "\0")    错误示范
//		//string(const char* str = nullptr) 错误示范
//		string(const char* str = "")
//			:_str(new char[strlen(str)+1])
//		{
//			// 已经拷贝'\0'
//			strcpy(_str, str);// while (*dst++ = *src++);
//		}
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//		//string copy1(s1)
//		string(const string& s)
//			:_str(new char[strlen(s._str)+1])
//		{
//			strcpy(_str, s._str);
//		}
//
//		// s1 = s2;
//		// s1 = s1;
//		string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				delete[] _str;
//				_str = new char[strlen(s._str) + 1];
//				strcpy(_str, s._str);
//			}
//
//			return *this;
//		}
//
//		const char* c_str()
//		{
//			return _str;
//		}
//
//		char& operator[](size_t pos)
//		{
//			return _str[pos];
//		}
//
//	private:
//		char* _str;
//	};
//}
//
//int main()
//{
//	bit::string s1("hello");
//	s1[0] = 'x';
//	cout << s1.c_str() << endl;
//
//	bit::string copy1(s1);
//	cout << copy1.c_str() << endl;
//
//	copy1[0] = 'h';
//	cout << s1.c_str() << endl;
//	cout << copy1.c_str() << endl;
//
//	bit::string s2 = "world";
//	s1 = s2;
//	cout << s1.c_str() << endl;
//
//	return 0;
//}

//namespace bit
//{
//	// string 模拟实现  增删查改
//	class string
//	{
//	public:
//		typedef const char* const_iterator;
//		typedef char* iterator;
//
//		const_iterator begin() const 
//		{
//			return _str;
//		}
//
//		iterator begin()
//		{
//			return _str;
//		}
//
//		iterator end()
//		{
//			return _str + _size;
//		}
//
//		string(const char* str = "")
//			:_str(new char[strlen(str) + 1])
//		{
//			// 已经拷贝'\0'
//			strcpy(_str, str);// while (*dst++ = *src++);
//			_size = strlen(str);
//			_capacity = _size;
//		}
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//			_size = _capacity = 0;
//		}
//
//		//string copy1(s1)
//		string(const string& s)
//			:_str(new char[s._size + 1])
//			, _size(s._size)
//			, _capacity(s._size)
//		{
//			strcpy(_str, s._str);
//		}
//
//		// s1 = s2;
//		// s1 = s1;
//		string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				delete[] _str;
//				_str = new char[s._size + 1];
//				strcpy(_str, s._str);
//				_size = s._size;
//				_capacity = s._capacity;
//			}
//
//			return *this;
//		}
//
//		const char* c_str()
//		{
//			return _str;
//		}
//
//		char& operator[](size_t pos)
//		{
//			assert(pos < _size);
//			return _str[pos];
//		}
//
//		const char& operator[](size_t pos) const
//		{
//			assert(pos < _size);
//			return _str[pos];
//		}
//
//		size_t size()
//		{
//			return _size;
//		}
//
//		size_t capacity()
//		{
//			return _capacity;
//		}
//
//		//reverse
//		void reserve(size_t n)
//		{
//			if (n > _capacity)
//			{
//				char* tmp = new char[n+1];
//				strcpy(tmp, _str);
//				delete[] _str;
//				_str = tmp;
//				_capacity = n;
//			}
//		} 
//
//		void push_back(char ch)
//		{
//			//if (_size == _capacity)
//			//{
//			//	// 扩容
//			//	reserve(_capacity * 2);
//			//}
//
//			//_str[_size] = ch;
//			//++_size;
//			//_str[_size] = '\0';
//			insert(_size, ch);
//		}
//
//		// s1.append("11111");
//		void append(const char* str)
//		{
//			//size_t len = strlen(str);
//			//if (_size+len > _capacity)
//			//{
//			//	// 扩容
//			//	reserve(_size + len);
//			//}
//
//			//strcpy(_str + _size, str);
//			//_size += len;
//
//			insert(_size, str);
//		}
//
//		//s1 += ch
//		const string& operator+=(char ch)
//		{
//			push_back(ch);
//			return *this;
//		}
//
//		const string& operator+=(const char* str)
//		{
//			append(str);
//			return *this;
//		}
//
//		const string& operator+=(const string& s)
//		{
//			append(s._str);
//			return *this;
//		}
//
//		void insert(size_t pos, char ch)
//		{
//			assert(pos <= _size);
//			if (_size == _capacity)
//			{
//				reserve(_capacity * 2);
//			}
//
//			/*int end = _size;
//			while (end >= (int)pos)
//			{
//				_str[end + 1] = _str[end];
//				--end;
//			}*/
//
//			size_t end = _size+1;
//			while (end >= pos + 1)
//			{
//				_str[end] = _str[end - 1];
//				--end;
//			}
//
//			_str[pos] = ch;
//			++_size;
//		}
//
//		void insert(size_t pos, const char* str)
//		{
//			assert(pos <= _size);
//			size_t len = strlen(str);
//			if (_size + len > _capacity)
//			{
//				reserve(_size + len);
//			}
//
//			/*	int end = _size;
//				while (end >= (int)pos)
//				{
//				_str[end + len] = _str[end];
//				--end;
//				}*/
//
//			size_t end = _size + len;
//			while (end >= pos + len)
//			{
//				_str[end] = _str[end-len];
//				--end;
//			}
//
//			while (*str)
//			{
//				_str[pos++] = *str++;
//			}
//
//			_size += len;
//		}
//
//		// s1 > s2
//		// hello  hello!
//		bool operator>(const string& s) const
//		{
//			const char* str1 = _str;
//			const char* str2 = s._str;
//			while (*str1 && *str2)
//			{
//				if (*str1 > *str2)
//				{
//					return true;
//				}
//				else if (*str1 < *str2)
//				{
//					return false;
//				}
//				else
//				{
//					++str1;
//					++str2;
//				}
//			}
//
//			if (*str1)
//			{
//				return true;
//			}
//			else
//			{
//				return false;
//			}
//			/*else if (*str2)
//			{
//			return false;
//			}
//			else
//			{
//			return false;
//			}*/
//		}
//
//		bool operator==(const string& s) const
//		{
//			const char* str1 = _str;
//			const char* str2 = s._str;
//			while (*str1 && *str2)
//			{
//				if (*str1 != *str2)
//				{
//					return false;
//				}
//				else
//				{
//					++str1;
//					++str2;
//				}
//			}
//
//			if (*str1 || *str2)
//			{
//				return false;
//			}
//			else
//			{
//				return true;
//			}
//		}
//
//		bool operator>=(const string& s) const
//		{
//			return *this > s || *this == s;
//		}
//		// ...
//
//		size_t find(char ch)
//		{
//
//		}
//
//		size_t find(const char* str) // strstr ->kmp   
//		{
//
//		}
//
//		// operator+
//		// operator<<
//		// operator>>
//		// getline
//
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity;
//	};
//}
//
//
//
//void test1()
//{
//	bit::string s1("hello");
//	cout << s1.c_str() << endl;
//	bit::string copy1(s1);
//	cout << copy1.c_str() << endl;
//
//	for (size_t i = 0; i < s1.size(); ++i)
//	{
//		// s1.operator[](i); -> s1.operator[](&s1, i);
//		s1[i] = 'a';
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//
//	bit::string::iterator it1 = s1.begin();
//	while (it1 != s1.end())
//	{
//		cout << *it1 << " ";
//		++it1;
//	}
//	cout << endl;
//
//	for (auto e : s1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//void test2()
//{
//	bit::string s1("hello");
//	cout << s1.capacity() << endl;
//
//	s1 += "world";
//	cout << s1.capacity() << endl;
//
//	s1 += '!';
//	cout << s1.capacity() << endl;
//
//	cout << s1.c_str() << endl;
//
//	bit::string s2("helloworld!");
//	s2.insert(5, ' ');
//	cout << s2.c_str() << endl;
//	s2.insert(0, '$');
//	cout << s2.c_str() << endl;
//	s2.insert(0, "bit");
//	cout << s2.c_str() << endl;
//}
//
//int main()
//{
//	test2();
//
//	return 0;
//}

// 实现一个简单的string
// 传统写法 -> 踏实、按部就班
//class my_string
//{
//private:
//	char* _str;
//public:
//	my_string(const char* str = "")
//		:_str(new char[strlen(str)+1])
//	{
//		strcpy(_str, str);
//	}
//
//	// my_string s2(s1)
//	my_string(const my_string& s)
//		:_str(new char[strlen(s._str)+1])
//	{
//		strcpy(_str, s._str);
//	}
//
//	// s1 = s2
//	my_string& operator=(const my_string& s)
//	{
//		if (this != &s)
//		{
//			delete[] _str;
//			_str = new char[strlen(s._str) + 1];
//			strcpy(_str, s._str);
//		}
//
//		return *this;
//	}
//
//	~my_string()
//	{
//		delete[] _str;
//	}
//};

// 现代写法 -> 小聪明 简单
class my_string
{
private:
	char* _str;
public:
	my_string(const char* str = "")
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}

	// my_string s2(s1)
	my_string(const my_string& s)
		:_str(nullptr)
	{
		my_string tmp(s._str);
		swap(tmp._str, _str);
	}

	// s1 = s2
	/*my_string& operator=(const my_string& s)
	{
	if (this != &s)
	{
	my_string tmp(s);
	swap(_str, tmp._str);
	}

	return *this;
	}*/
	// s1 = s2
	// s1 = s1
	my_string& operator=(my_string s)
	{
		swap(_str, s._str);
		return *this;
	}

	~my_string()
	{
		if (_str)
			delete[] _str;
	}
};

int main()
{
	my_string s1("hello");
	my_string s2(s1);
	my_string s3("world");

	s1 = s3;

	return 0;
}