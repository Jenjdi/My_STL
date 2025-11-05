#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
void test(){
    set<int> s;

    s.insert(111);
    s.insert(31);
    s.insert(155);
    s.insert(144);
    s.insert(11);
    set<int>::iterator it =s.begin();
    while (it!=s.end()){
        cout<<*it<<" ";
        it++;
    }
    
    cout<<endl;
}
void testmap(){
    map<int,string> dict;
    dict.insert({55,"s4s"});
    dict.insert({4,"ss24s"});
    dict.insert({6,"sss242"});
    dict.insert({11,"ss56s"});

    dict[12]="45";



    auto it=dict.begin();
    while(it!=dict.end()){
        cout<< (*it).first<<":"<<(*it).second<<" ";
        it++;
    }
    cout<<endl;
}
int main() {
    test();
    testmap();
}
