//#include<iostream>
//using namespace std;
#if 0
namespace bite//�����ͳд��
{
	//string�ࣺ��̬���͵�˳���
	class string
	{
	public:
		/*string(const char*str ="")
		{
			if (nullptr == str)
			{
				//����յ��ַ���""����һ����Ч���ַ�����ֻ�������ַ���ֻ������һ��'\0'
				_str = new char[1];
				*_str = '\0';
				//��\0���õ��ַ����ռ���
				//_str����һ��ָ�룬��ָ��ָ���˶��ϵ�һ���ַ��ռ�
				//*_str:��_strָ��ָ��ռ��е����ݣ��ÿռ��ڶ��ϣ�������Է���һ���ַ�
				//'0' �ַ�0
				//'\0' ---ת���ַ�����'0'ת������0
				//'\0'==����0�ǵȼ۵�
				//_str = '\0';//_str=0;_str=nullptr
				//_str = 0;//_str=nullptr
				//*_str = '0';//_strָ��Ŀռ��зŵĲ���\0��0
				//*_str = 0;//����--���Ǵ���ɶ��Բ�
				//*_str = '\0';//����
				//_str = "";//���У��ᵼ�¿�ʼ�ĵ����ַ��Ŀռ䶪ʧ
			}
			else
			{
				_str = new char[strlen(str) + 1];//strlenû��'\0'
				strcpy(_str, str);
			}
		}*/
		//ǳ���������������ͬһ����Դ�������ͬһ����Դ�ͷŶ������������
		//�������Ҫ��������������Դ��ÿ������ӵ��һ����Դ
		string(const char*str = "")//���캯��
		{
			if (nullptr == str)
			{
				str = "";
			}
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		string(const string&s)//�������캯��
			:_str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
		}
		string &operator=(const string&s)//��ֵ���������
		{
			if (this != &s)
			{
				//1�������¿ռ�
				char *tmp = new char[strlen(s._str) + 1];
				//2���������¿ռ�
				strcpy(tmp, s._str);
				//3���ͷžɿռ�
				delete[] _str;
				//4����ֵ
				_str = tmp;
			}
			return *this;
		}
		~string()//��������
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
	bite::string s3(s2);//string�ࣺ��û����ʾ�ṩ�������캯�����������ڱ�һ�׶λ�����һ��Ĭ�ϵĿ������캯��--��
	//һ�������е�����ԭ�ⲻ���Ŀ�����һ���¶�����---ֵ�Ŀ���--��ơ�ǳ������
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
//	////string��������������
//	//// ע�⣺string�����֧��ֱ����cin��cout������������
//	//string s("hello, bit!!!");
//	//cout << s.size() << endl;
//	//cout << s.length() << endl;
//	//cout << s.capacity() << endl;
//	//cout << s << endl;
//
//	//// ��s�е��ַ�����գ�ע�����ʱֻ�ǽ�size��0�����ı�ײ�ռ�Ĵ�С
//	//s.clear();
//	//cout << s.size() << endl;
//	//cout << s.capacity() << endl;
//
//	//// ��s����Ч�ַ��������ӵ�10�������λ����'a'�������
//	//// ��aaaaaaaaaa��
//	//s.resize(10, 'a');
//	//cout << s.size() << endl;
//	//cout << s.capacity() << endl;
//
//	//// ��s����Ч�ַ��������ӵ�15�������λ����ȱʡֵ'\0'�������
//	//// "aaaaaaaaaa\0\0\0\0\0"
//	//// ע���ʱs����Ч�ַ������Ѿ����ӵ�15��
//	//s.resize(15);
//	//cout << s.size() << endl;
//	//cout << s.capacity() << endl;
//	//cout << s << endl;
//
//	//// ��s����Ч�ַ�������С��5��
//	//s.resize(5);
//	//cout << s.size() << endl;
//	//cout << s.capacity() << endl;
//	//cout << s << endl;
//
//	//string s;
//	//// ����reserve�Ƿ��ı�string����ЧԪ�ظ���
//	//s.reserve(100);
//	//cout << s.size() << endl;
//	//cout << s.capacity() << endl;
//	//// ����reserve����С��string�ĵײ�ռ��Сʱ���Ƿ�Ὣ�ռ���С
//	//s.reserve(50);
//	//cout << s.size() << endl;
//	//cout << s.capacity() << endl;
//
//	////string�����ķ��ʼ���������
//	//string s("hello Bit");
//	//// 3�ֱ�����ʽ��
//	//// ��Ҫע����������ַ�ʽ���˱���string���󣬻����Ա���ʱ�޸�string�е��ַ���
//	//// �����������ַ�ʽ����string���ԣ���һ��ʹ�����
//	//// 1. for+operator[]
//	//for (size_t i = 0; i < s.size(); ++i)
//	//	cout << s[i] << endl;
//	// //2.������
//	//string::iterator it = s.begin();
//	//while (it != s.end())
//	//{
//	//	cout << *it << endl;
//	//	++it;
//	//}
//	// //3.��Χfor
//	//for (auto ch : s)
//	//	cout << ch << endl;
//
//	//string�������޸Ĳ���
//	//string str;
//	//str.append("hello"); // ��str��׷��һ���ַ�"hello"
//	//str.push_back(' '); // ��str�����ո�
//	//str += 'b'; // ��str��׷��һ���ַ�'b'
//	//str += "it"; // ��str��׷��һ���ַ���"it"
//	//cout << str << endl;
//	//cout << str.c_str() << endl; // ��C���Եķ�ʽ��ӡ�ַ���
//	// ��ȡfile�ĺ�׺
//	//string file1("string.cpp");
//	//size_t pos = file1.rfind('.');
//	//string suffix(file1.substr(pos, file1.size() - pos));
//	//cout << suffix << endl;
//	// npos��string�����һ����̬��Ա����
//	// static const size_t npos = -1;
//	// ȡ��url�е�����
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
//	// ɾ��url��Э��ǰ׺
//	//pos = url.find("://");
//	//url.erase(0, pos + 3);
//	//cout << url << endl;
//}

#include<iostream>
#include <assert.h>
using namespace std;

// ��ǳ��������
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
//		//string(const char* str = "\0")    ����ʾ��
//		//string(const char* str = nullptr) ����ʾ��
//		string(const char* str = "")
//			:_str(new char[strlen(str)+1])
//		{
//			// �Ѿ�����'\0'
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
//	// string ģ��ʵ��  ��ɾ���
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
//			// �Ѿ�����'\0'
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
//			//	// ����
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
//			//	// ����
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

// ʵ��һ���򵥵�string
// ��ͳд�� -> ̤ʵ�������Ͱ�
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

// �ִ�д�� -> С���� ��
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