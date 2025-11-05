#include <iostream>
namespace My_vector
{
    template <typename T, typename Container>
    class vector
    {
        typedef T *iterator;
        typedef const T *const_iterator;

    private:
        iterator _start=nullptr;
        iterator _end=nullptr;
        iterator end_of_storage=nullptr;

    public:
        vector() {}
        vector(const vector<T> &v)
        {
            reserve(v.capacity()); // 减少扩容次数
            for (auto &e : v)
            {
                push_back(e);
            }
        }
        template<typename InputIterator>
        vector(InputIterator it1,InputIterator it2)
        {
            while (it1!=it2)
            {
                push_back(*it1);
                it1++;
            }
        }
        iterator begin()
        {
            return _start;
        }
        iterator end()
        {
            return _end;
        }
        size_t capacity()
        {
            return end_of_storage-_start;
        }
        size_t size()
        {
            return _end-_start;
        }
        void reserve(size_t n)
        {
            if(n>=size())
            {
                size_t oldsize=size();
                T* tmp=new T[n];
                for(int i=0;i<size();i++)
                {
                    tmp[i]=_start[i];
                }
                delete[] _start;
                _start=tmp;
                _end=tmp+oldsize;
                end_of_storage=tmp+n;
            }
        }
        void insert(iterator pos,T val=T())
        {
            if(_end==end_of_storage)
            {
                size_t len=pos-_start;
                reserve(capacity()==0?4:2*capacity());
                pos=len+_start;
            }
            iterator it=_end-1;
            while(it>=pos)
            {
                *(it+1)=*it;
                it--;
            }
            *it=val;
            ++_end;
            
        }
        void push_back(const T& val)
        {
            insert(_end,val);
        }
        
        
    };
}
