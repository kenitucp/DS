#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
//底层--平衡二叉搜索树，复杂度：log n；高效--快速查找在不在
void test_set()
{
	set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(2);
	s.insert(4);

	//迭代器，区间左闭右开
	set<int>::iterator it = s.begin();
	while (it!=s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//查找
	set<int>::iterator ret = s.find(2);
	if (ret != s.end())
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}
	if (ret != s.end())
	{
         s.erase(ret);//得传有效的迭代器或者想删除的值，如果删除的值set里面没有就不删--先find，有再删
	}
	//s.erase(20);

}
//k结构--通过一个值找另一个值--字典、统计字数
void test_map()
{
	map<string, string> dict;
	dict.insert(pair<string, string>("sort", "排序"));
	dict.insert(pair<string, string>("insert", "插入"));
	dict.insert(pair<string, string>("delete", "删除"));

	map<string, string>::iterator dit = dict.begin();
	//auto dit = dict.begin();//c++11支持
	while (dit != dict.end())
	{
		//pair<k,v>& operator*()
		cout << (*dit).first << "" << (*dit).second << endl;//dit结点有俩个值，封装在pair的结构体里。
		////pair<k,v>*operator->()
		//cout << dit->first << "" << dit->second << endl;
		++dit;
	}
	cout << endl;
	//用途1：字典
	string str;
	while (cin >> str)
	{
		auto ret = dict.begin();
		if (ret != dict.end())
		{
			cout << ret->second << endl;
		}
		else
		{
			cout << "该单词不在此字典中" << endl;
		}
	}
	//用途2：统计次数
	string strs[] = { "苹果", "香蕉", "草莓", "西瓜", "草莓", "草莓", "西瓜", "香蕉", "香蕉", "香蕉", "香蕉" };
	map<string, int>countmap;
	for (auto str : strs)
	{
		//1、在 ++次数
		//2、不在 insert pair<水果,1>
		auto ret = countmap.find(str);
		if (ret!=countmap.end())//找到了
		{
			ret->second++;
		}
		else
		{
			countmap.insert(pair<string, int>(str, 1));
		}
	}
	//统计次数的第二种方法
	for (auto str : strs)
	{
		//insert插入成功返回真，失败返回假
		//pair<map<string, int>::iterator,bool> ret=countmap.insert(pair<string, int>(str, 1));
		auto ret = countmap.insert(pair<string, int>(str, 1));
		if (ret.second == false)//插入失败，里面已经有这个值了，次数++
		{
           ret.first->second++;
		}
	}
	//统计次数第3种方法
	string strs[] = { "苹果", "香蕉", "草莓", "西瓜", "草莓", "草莓", "西瓜", "香蕉", "香蕉", "香蕉", "香蕉" };
	map<string, int>countmap;
	for (auto str : strs)
	{
		countmap[str]++;//为什么？
	}
}
#include<vector>
void GetFavoriteFruit(const vector<string>& fruits，size_t k)
{
	//先统计每个水果出现次数
	map<string, size_t> m;
	for (auto &e : fruits)
	{
		auto it = m.find(e);
		if (it != m.end())
		{
			it->second++;
		}
		else
		{
			m.insert(make_pair(e, 1));
		}
	}
	//出现次数最多的前k个水果--TOP-K--优先级队列
	multimap<size_t, string,greater<size_t>> mm;
	for (auto &e : m)
	{
		mm.insert(make_pair(e.second, e.first));
	}
	vector<string> ret;
	
}
int main()
{
	//test_set();
	test_map();
}