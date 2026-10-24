// 回归：容器扩容、深拷贝、自引用插入和哈希表扩容。
#include <cassert>
#include <string>
#include "../vector/vector.h"
#include "../string/mystring.h"
#include "../Hash/unordered_map.h"
#include "../Hash/unordered_set.h"
int main(){
 My_vector::vector<std::string> v;v.push_back("one");v.push_back("two");v.insert(v.begin(),"zero");assert(v[0]=="zero");v.erase(v.begin()+1);assert(v[1]=="two");v.reserve(20);v.resize(5,"new");assert(v[4]=="new");auto copy=v;v[0]="changed";assert(copy[0]=="zero");v.pop_back();assert(v.size()==4);v.resize(0);assert(v.empty());
 My_vector::vector<int> mv;mv.push_back(7);assert(mv[0]==7);
 my_string s(nullptr);s.append("abc");s.insert('x',1);assert(std::string(s.c_str())=="axbc");s.insert(s.c_str(),2);assert(std::string(s.c_str())=="axaxbcbc");s.erase(1,3);assert(std::string(s.c_str())=="abcbc");s.resize(10,'z');assert(s.size()==10);
 My_Map::unordered_map<int,std::string> map;for(int i=0;i<100;++i)map[i]=std::to_string(i);for(int i=0;i<100;++i)assert(map[i]==std::to_string(i));
}
