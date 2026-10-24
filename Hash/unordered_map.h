// 修复：统一包装层与底层哈希表的类型和返回值。
#pragma once
#include "hash_table.h"
namespace My_Map {

template <class K, class V, class Hash = HashFunc<K>>
class unordered_map {
    struct KeyOfMap {
        K operator()(const std::pair<K, V>& kv)
        {
            return kv.first;
        }
    };

private:
    Bucket::HashTable<K, std::pair<K, V>, KeyOfMap, Hash> _hash;

public:
    typedef typename Bucket::HashTable<K, std::pair<K, V>, KeyOfMap, Hash>::iterator iterator;
    typedef typename Bucket::HashTable<K, std::pair<K, V>, KeyOfMap, Hash>::const_iterator const_iterator;
    std::pair<iterator,bool> insert(const std::pair<K, V>& kv)
    {
        return _hash.Insert(kv);
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
    V& operator[](const K& key)
    {
        std::pair<iterator, bool> ret = insert(std::make_pair(key, V()));
        return ret.first->second;
    }
};
}
