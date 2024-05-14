#include <iostream>

using namespace std;

template <class datakey, class datavalue>
struct mapcontent
{
	datakey k;
	datavalue v;
	int index;
};

template <class datakey, class datavalue>
class Map
{
private:
	mapcontent* first;
	mapcontent* last;
public:
	Map() : head(nullptr), tail(nullptr), count(0) {}
	~Map() = default;
	datavalue& operator[](datakey key)
	{
		mapcontent* current = first;
		while (current != nullptr) {
			if (current->key == key)
				return current->value;
			current = current->next;
		}
		mapcontent* new_node = new mapcontent;
		if (first == nullptr)
		{
			new_node->key = key;
			new_node->value = datavalue();
		}
		else
		{
			new_node->next = first;
			first = new_node;
		}
		return first->value;
	}
	index begin()
	{
		return make_tuple(first->key, first->value);
	}
	index end()	{		return tuple<datakey, datavalue>(0, nullptr);	}
};

template <class datakey, class datavalue>
class index
{
public:
	int* p;
	index& operator++()
	{
		p++;
		return *this;
	}
	bool operator != (index &m)
	{
		return p != m.p;
	}
	int operator* ()
	{
		return *p;
	}
};

int main()
{
	Map<int, const char *> m;
	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";
	for (auto[key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	m[20] = "result";
	for (auto[key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	return 0;
}
