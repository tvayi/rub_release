#include <iostream>
#include <vector>
#include<forward_list>
#include<unordered_map>

template<typename Key, typename T, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key>  >
class HashTable {
private:
	std::vector<std::forward_list<std::pair<Key, T> > > map_;
	typename std::forward_list<std::pair<Key, T> >::iterator it1;
	int number = 0;

public:

	HashTable() {
		for (int i = 0; i < 10; i++) {
			std::forward_list<std::pair<Key, T> > v;
			map_.push_back(v);
		}
	}


	void erase(const Key& k) {
		for (auto i = map_[my_Hash(k)].begin(); i != map_[my_Hash(k)].end(); i++) {
			std::pair<Key, T> p;
			p = *i;
			if (p.first == k) {
				map_[my_Hash(k)].remove(*i);
				number--;
				break;
			}
		}
	}
	void insert(std::pair<Key, T> p) {
		map_[my_Hash(p.first)].push_front(p);
		number++;
	}
	T& operator[](const Key& k) {
		for (auto i = map_[my_Hash(k)].begin(); i != map_[my_Hash(k)].end(); i++) {
			std::pair<Key, T> p;
			p = *i;
			if (p.first == k)
				return (*i).second;
		}
		auto i = map_[my_Hash(k)].begin();
		std::pair<Key, T> p;
		p = *i;
		return (*i).second;
		
	}
private:
	std::vector<std::forward_list<std::pair<Key, T> > > getMap() {
		return map_;
	}

	size_t my_Hash(const Key& k) {
		return Hash()(k) % map_.size();
	}
	size_t size() { // возвращаем количество элементов в хэш-функции
		return number;
	}
public:
	class Iterator {
	public:
		typename std::forward_list<std::pair<Key, T> >::iterator it;
		std::vector<std::forward_list<std::pair<Key, T> > > map;
		int right;
		int count = 0;
		int index = 0;
		Iterator(HashTable<Key, T>& ob)
		{
			map = ob.getMap();
			right = -1;
			index = 0;

		}
	private:
		int notZero() // находим первый ненулевой список
		{
			for (int i = right + 1; i < 10; i++)
			{
				if (map[i].empty() == 0)
				{
					right = i;
					return 0;
				}
			}
			return 0;
		}
	public:
		Iterator& operator++ ()
		{
			if (count == 0) {
				notZero();
			}

			it = map[right].begin();
			advance(it, index);

			if (it == (map[right].end()))
			{
				notZero();
				it = map[right].begin();
				index = 1;
			}
			else {
				count++;
				index++;
			}
			return *this;
		}
	
		std::pair<Key, T>& operator* ()
		{
			return *it;
		}
	};

	Iterator begin() {
		int right = 0;
		int count = 0;
		int index = 0;
		for (int i = right + 1; i < 10; i++)
		{
			if (map_[i].empty() == 0)
			{
				right = i;
				break;
			}

		}
		return *this;
	}

	Iterator end() {
		int right = 0;
		for (int i = right + 1; i < 10; i++)
		{
			if (map_[i].empty() == 0) {
				right = i;
			}
		}
		return *this;
	}

};

