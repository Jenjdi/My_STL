#include <iostream>
#include <cassert>
#include<cstring>
using namespace std;
class my_string
{
public:
    my_string()
    {
        _size = 0;
        _str=new char[1];
        _str[0] = '\0';
    }
    my_string(const char *str)
    {
        if(str==nullptr)
        {
            _size = 0;
            _str=new char[1];
            _str[0] = '\0';
        }
        _size = strlen(str);
        _str = new char[_size + 1];
        strcpy(_str, str);
    }
    ~my_string()
    {
        if(_str)
        {
            delete[] _str;
            _str = nullptr;
        }
    }
    void reserve(size_t n)
    {
        if(n>_capacity)
        {
            char* tmp=new char[n];
            strcpy(tmp,_str);
            delete[] _str;
            _str=tmp;
            _capacity=n;
        }
    }
    void insert(char str,size_t pos)
    {
        assert(pos<=_size);
        if(_size==_capacity)
        {
            reserve(_capacity==0?4:2*(_capacity));
        }
        size_t end=_size+1;
        while(end>pos)
        {
            _str[end]=_str[end-1];
            end--;
        }
        _str[pos]=str;
        _size++;
    }
    void insert(char* str,size_t pos)
    {
        assert(pos<=_size);
        if(_size+strlen(str)>=_capacity)
        {
            reserve(_size+strlen(str));
        }
        size_t end=_size+strlen(str);
        while(end>pos+strlen(str)-1)
        {
            _str[end]=str[end-strlen(str)];
            end--;
        }
        strncpy(_str,str,strlen(str));
        _size+=strlen(str);
    }
    void append(char* str)
    {
        if(_size+strlen(str)>_capacity)
        {
            reserve(strlen(str)+_size);
        }
        strcpy(_str+_size,str);
        _size+=strlen(str);
    }
    void push_back(char str)
    {
        if(_size==_capacity)
        {
            reserve(_capacity==0?4:2*(_capacity));
        }
        _str[_size]=str;
        _size++;
        _str[_size]='\0';
    }
    void resize(size_t n,char* ch='\0')
    {
        if(n<_size)
        {
            _size=n;
            _str[_size]='\0';
        }
        else
        {
            reserve(n);
            for(size_t i=_size;i<n;i++)
            {
                _str[i]=ch[i-_size];
            }
        }
    }
    void erase(size_t pos,size_t len=npos)
    {
        if(len==npos||len>=_size-pos)
        {
            _str[pos]='\0';
            _size=pos;
        }
        else
        {
            strcpy(_str+pos,_str+pos+len);
            _size-=len;
        }
    }
    static const int npos;
private:
    char *_str;
    size_t _size;
    size_t _capacity;
};
const int npos=-1;