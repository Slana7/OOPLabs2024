#pragma once
#include <iostream>

template <class KeyType, class DataType>
struct NodeContent {
	KeyType key;
	DataType data;
	int index;
};

template <class KeyType, class DataType>
struct Node {
	NodeContent<KeyType, DataType> content;
	Node<KeyType, DataType>* next;

	Node() : next(nullptr) { content.index = 0; }

	~Node() { delete next; }

	bool operator !=(Node<KeyType, DataType>& node) { return content.key != node.content.key; }

	Node<KeyType, DataType>& operator ++() {
		*this = *(this->next);
		return *this;
	}

	NodeContent<KeyType, DataType> operator *() { return this->content; }
};

template <class KeyType, class DataType>
class Map {
	Node<KeyType, DataType>* first;
	Node<KeyType, DataType>* last;
	int size;

public:
	Map() : size(0) {
		first = new Node<KeyType, DataType>;
		first->content.index = size;
		first->next = nullptr;
		last = first;
	}

	~Map() { delete first; }

	DataType& operator[](KeyType key) {
		Node<KeyType, DataType>* nptr = first;
		while (nptr != last) {
			if (key == nptr->content.key)
				return nptr->content.data;
			nptr = nptr->next;
		}
		nptr->content.key = key;
		nptr->next = new Node<KeyType, DataType>;
		last = nptr->next;
		last->content.index = ++size;
		last->next = nullptr;
		return nptr->content.data;
	}

	class Iterator {
		Node<KeyType, DataType>* current;

	public:
		Iterator(Node<KeyType, DataType>* node) : current(node) {}

		bool operator!=(const Iterator& other) const {
			return current != other.current;
		}

		Iterator& operator++() {
			if (current) {
				current = current->next;
			}
			return *this;
		}

		NodeContent<KeyType, DataType>& operator*() {
			return current->content;
		}
	};

	Iterator begin() const {
		return Iterator(first);
	}

	Iterator end() const {
		return Iterator(nullptr);
	}

	void Set(KeyType key, DataType data) {
		(*this)[key] = data;
	}

	bool Get(const KeyType& key, DataType& value) {
		Node<KeyType, DataType>* nptr = first;
		while (nptr != last) {
			if (key == nptr->content.key) {
				value = nptr->content.data;
				return true;
			}
			nptr = nptr->next;
		}
		return false;
	}

	int Count() {
		return size;
	}

	void Clear() {
		delete first;
		first = new Node<KeyType, DataType>;
		first->content.index = size = 0;
		first->next = nullptr;
		last = first;
	}

	bool Delete(const KeyType& key) {
		Node<KeyType, DataType>* nptr = first;
		if (first->content.key == key) {
			first = first->next;
			delete nptr;
			size--;
			return true;
		}
		while (nptr->next != last) {
			if (nptr->next->content.key == key) {
				Node<KeyType, DataType>* temp = nptr->next;
				nptr->next = temp->next;
				delete temp;
				size--;
				return true;
			}
			nptr = nptr->next;
		}
		return false;
	}

	bool Includes(const Map<KeyType, DataType>& map) {
		DataType temp;
		for (const auto& nodeContent : map) {
			if (!Get(nodeContent.key, temp)) {
				return false;
			}
		}
		return true;
	}
};

int main() {
	Map<int, const char*> m;
	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";

	for (auto& nodeContent : m) {
		printf("Index:%d, Key=%d, Value=%s\n", nodeContent.index, nodeContent.key, nodeContent.data);
	}

	m[20] = "result";

	for (auto& nodeContent : m) {
		printf("Index:%d, Key=%d, Value=%s\n", nodeContent.index, nodeContent.key, nodeContent.data);
	}

	return 0;
}
