#include"set.h"
#include"map.h"
void test_map()
{
	mmap::Mymap<int, int> map;
	map.insert({ 1,2 });
	map.insert({ 2,2 });
	map.insert({ 3,3 });
	map.insert({ 4,4 });
	mmap::Mymap<int, int>::iterator it = map.begin();
	while (it != map.end())
	{
		cout << it->first << ":" << it->second << " ";
		++it;
	}
	
}
void test_set()
{
	mset::Myset<int> set;
	set.insert(1);
	set.insert(2);
	set.insert(3);
	set.insert(4);
	mset::Myset<int>::iterator it=set.begin();
	while (it != set.end())
	{
		cout << *it << " ";
		++it;
	}
}
int main()
{

	test_map();
}
