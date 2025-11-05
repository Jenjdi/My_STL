////#pragma once
////#include<iostream>
////#include<vector>
////using namespace std;
////enum Status
////{
////	EXIST,
////	DELETE,
////	EMPTY
////};
////template<class k,class v>
////struct HashData
////{
////	Status _status = EMPTY;
////	pair<k, v> _kv;
////};
////template<class k,class v>
////class HashTable
////{
////public:
////	HashTable()
////	{
////		_table.resize(10);
////	}
////	
////	bool Insert(const pair<k, v>& kv)
////	{
////		if (_n * 10 / _table.size() > 7)
////		{
////			HashTable<k, v> newHT;
////			newHT.resize(_table.size() * 2);
////			for (int i = 0; i < _table.size(); i++)
////			{
////				if (_table[i].status == EXIST)
////				{
////					newHT.Insert(_table[i]._kv);
////				}
////			}
////			_table.swap(newHT._table);
////		}
////		size_t hashi = kv.first % _table.size();
////		while (_table[hashi].status== EXIST)
////		{
////			++hashi;
////			hashi = hashi % _table.size();//·ÀÖ¹hashiÒç³ö
////		}
////		_table[hashi]._kv = kv;
////		_table[hashi]._status = EXIST;
////		_n++;
////		return true;
////	}
////	HashTable<k, v>* Find(const k& key)
////	{
////		size_t hashi = key % _table.size();
////		while (_table[hashi]._status != EMPTY)
////		{
////			if (_table[hashi]._kv.first() == key)
////			{
////				return &_table[hashi];
////			}
////			hashi++;
////			hashi = hashi % _table.size();
////		}
////		return nullptr;
////	}
////	bool Erase(const k& key)
////	{
////		HashData<k, v>* ret = Find(key);
////		if (ret == nullptr)
////		{
////			return false;
////		}
////		else
////		{
////			ret->_status = DELETE;
////			--_n;
////			return true;
////		}
////		
////	}
////private:
////	vector<HashData<k, v>> _table;
////	size_t _n;
////};
//#include<iostream>
//#include<vector>
//using namespace std;
//enum Status
//{
//	EXIST,
//	EMPTY,
//	DELETE
//};
//template<class k,class v>
//struct HashData
//{
//	pair<k, v> _kv;
//	Status _status;
//};
//template<class k>
//struct HashFunc
//{
//	size_t operator()(const k& key)
//	{
//		return (size_t)key;
//	}
//};
//struct HashString
//{
//	size_t operator()(const string& key)
//	{
//		return key[0];
//	}
//};
//template<class k,class v,class hash=HashFunc<k>>
//class HashTable
//{
//public:
//	HashTable()
//	{
//		_table.resize(10);
//		_n = 0;
//	}
//	hash hs;
//	bool Insert(const pair<k, v>& kv)
//	{
//		if (_n * 10 / _table > 7)
//		{
//			
//			HashTable<k,v,hash> newHT;
//			newHT.resize(_table.size() * 2);
//			for (int i = 0; i < _table.size(); i++)
//			{
//				newHT.Insert(_table[i]._kv);
//				_n++;
//			}
//			_table.swap(newHT._table);
//		}
//		size_t hashi = hs(kv.first) % _table.size();
//		while (_table[hashi].status == EXIST)
//		{
//			hashi++;
//			hashi = hashi % _table.size();
//		}
//		_table[hashi]._kv = kv;
//		_n++;
//	}
//	HashTable<k, v,hash>* Find(const k& key)
//	{
//		size_t hashi = hs(key) % _table.size();
//		while (_table[hashi]._status != EMPTY)
//		{
//			if (_table[hashi]._kv.first == key)
//			{
//				return _table[hashi];
//			}
//			else
//			{
//				++hashi;
//				hashi = hashi % _table.size();
//			}
//		}
//		return nullptr;
//	}
//
//private:
//	vector<HashData<k,v>> _table;
//	size_t _n;
//};
#include<iostream>
#include<vector>
using namespace std;
enum Status
{
	EMPTY,
	DELETE,
	EXIST
};
template<class K,class V>
struct HashNode
{
	HashNode* _next;
	pair<K, V> _kv;
	Status status;
};
template<class K,class V>
class HashTable
{
public:
	~HashTable()
	{
		
		for (size_t i = 0; i < _table.size() - 1; i++)
		{
			node* cur = _table[i];
			while (cur)
			{
				node* next = cur->_next;
				delete cur;
				cur = next;
			}
			_table[i] = nullptr;
		}
	}
	HashTable()
	{
		_table.resize(10,nullptr);
		_n = 0;
	}
	typedef HashNode<K, V> node;
	bool Insert(const pair<K, V>& kv)
	{
		
		if (_n == _table.size())
		{
			/*HashTable<K,V> newHT;
			newHT.resize(_table.size() * 2);
			for (int i = 0; i < _table.size(); i++)
			{
				node* cur = _table[i];
				while (cur)
				{
					newHT.Insert(cur->_kv);
					cur = cur->_next;
				}
			}
			_table.swap(newHT._table);*/
			vector<node*> newHT;
			newHT.resize(2 * _table.size(), nullptr);
			for (size_t i = 0; i < _table.size()-1; i++)
			{
				node* cur = _table[i];
				while (cur)
				{
					node* next = cur->_next;
					size_t hashi = cur->_kv.first % newHT.size();
					cur->_next = newHT;
					cur = newHT;
					cur = cur->_next;
				}
				_table[i] = nullptr;
			}
			_table.swap(newHT);
		}
		size_t hashi = kv.first % _table.size();
		node* newnode = new node(kv);
		newnode->_next = _table[hashi];
		_table[hashi] = newnode;
		_n++;

	}
	HashTable<K, V>* Find(const pair<K, V> key)
	{
		size_t hashi = key.first % _table.size();
		while (_table[hashi].status != EMPTY)
		{
			if (_table[hashi]._kv.first == key.first)
			{
				return _table[hashi];
			}
			else
			{
				++hashi;
				hashi = hashi % _table.size();
			}
		}
		return nullptr;
	}
private:
	 vector<node*>_table;
	 size_t _n;
};