#include "hash.cpp"
int main()
{
	
	HashTable<std::string, int> a;
	a.insert({ "banana", 3 });
	a.insert({ "potato", 4 });
	a.insert({ "mushroom", 10 });
	a.insert({ "pear", 13 });
	a.erase("pear");
	std::cout << "Number of mushrooms is " << a["mushroom"] << "\n";
	auto it = HashTable<std::string, int>::Iterator(a);
	int k = 0;
	++it;
	
	std::cout << (*it).first << "\n";
	++it;
	std::cout << (*it).first << "\n";
	++it;
	std::cout << (*it).first << " " << (*it).second << " " << "\n";



	return 0;
}
