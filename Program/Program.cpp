#include <iostream>

using namespace std;

template <typename KEY, typename VALUE>
class HashTable
{
private:
	struct Node
	{
		KEY key;
		VALUE value;
		Node* next;
	};

	struct Bucket
	{
		int count;
		Node* head;
	};

	Bucket * bucket;
	int size;

public:
	HashTable()
	{
		size = 8;
		bucket = new Bucket[size];
	}

	unsigned int hash_function(KEY key)
	{
		return (unsigned int)key % size;
	}

	void insert(KEY key, VALUE value)
	{
		int hashIndex = hash_function(key);

		Node* newNode = new Node;
		newNode->key = key;
		newNode->value = value;
		newNode->next = nullptr;

		if (bucket[hashIndex].count == 0)
		{
			bucket[hashIndex].head = newNode;
		}

		else
		{
			newNode->next = bucket[hashIndex].head;
			bucket[hashIndex].head = newNode;
		}

		bucket[hashIndex].count++;
	}

	const int & bucket_count()
	{
		return size;
	}

	void erase(KEY key)
	{
		int hashIndex = hash_function(key);

		Node* currentNode = bucket[hashIndex].head;

		Node* previousNode = nullptr;

		if(currentNode == nullptr)
		{
			cout << "not key found" << endl;

			return;
		}


		if(currentNode->key == key)
		{
			if(previousNode == nullptr)
			{
				bucket[hashIndex].head = currentNode->next;
			}

			else
			{
				previousNode->next = currentNode->next->next;
			}

			delete currentNode;
			bucket[hashIndex].count--;
		}

		else
		{
			cout << "not key found" << endl;
		}
	}
};

int main()
{
	HashTable<const char*, int> hashTable;

	hashTable.insert("운석", 200);
	hashTable.insert("생명의 나무", 200);
	hashTable.insert("미스릴", 250);

	hashTable.erase("운석");
	hashTable.erase("생명의 나무");
	hashTable.erase("미스릴");
	hashTable.erase("운석");

	return 0;
}