#pragma once
#include "hash_table.h"
using namespace hash_bucket;
template <class K, class V, class HashFunc = BucketFunc<K>>
class unordered_map
{
	struct mapkofT
	{
		const K &operator()(const std::pair<K, V> &key)
		{
			return key.first;
		}
	};

public:
	typedef typename hash_bucket::HashTable<K, std::pair<K, V>, mapkofT, HashFunc>::iterator iterator;

	bool insert(const std::pair<K, V> key)
	{
		hash.insert(key);
	}
	bool insert(const K &key)
	{
		hash.insert(key);
	}
	iterator begin()
	{
		return hash.begin();
	}
	iterator end()
	{
		return hash.end();
	}

private:
	hash_bucket::HashTable<K, std::pair<K, V>, mapkofT, HashFunc> hash;
};