// 修复：统一包装层与底层哈希表的类型和返回值。
#pragma once
#include "hash_table.h"
namespace My_Set {

template <class K, class Hash = HashFunc<K>>
class unordered_set {
    struct KeyOfSet {
        K operator()(const K& key)
        {
            return key;
        }
    };

private:
    Bucket::HashTable<K, K, KeyOfSet, Hash> _hash;

public:
    typedef typename Bucket::HashTable<K, K, KeyOfSet, Hash>::iterator iterator;
    typedef typename Bucket::HashTable<K, K, KeyOfSet, Hash>::const_iterator const_iterator;
    std::pair<iterator, bool> insert(const K& key)
    {
        return _hash.Insert(key);
    }
    bool erase(const K& key)
    {
        return _hash.Erase(key);
    }
    iterator find(const K& key)
    {
        iterator ret = _hash.Find(key);
        return ret;
    }
    iterator begin()
    {
        return _hash.begin();
    }
    iterator end()
    {
        return _hash.end();
    }
    const_iterator begin() const
    {
        return _hash.begin();
    }
    const_iterator end() const
    {
        return _hash.end();
    }
    K& operator[](const K& key)
    {
        std::pair<iterator, bool> ret = insert(key, K());
        return ret.first->second;
    }
};
}
