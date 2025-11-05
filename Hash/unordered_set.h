#pragma once
#include "hash_table.h"
using namespace hash_bucket;
template <class K, class HashFunc = BucketFunc<K>>
class unordered_set
{

	struct setkofT
	{
		const K &operator()(const K &key)
		{
			return key;
		}
	};

public:
	typedef typename hash_bucket::HashTable<K, K, setkofT, HashFunc>::iterator iterator;

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
	hash_bucket::HashTable<K, K, setkofT, HashFunc> hash;
};