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

	Bucket* bucket;
	int size;
	int capacity;

public:
	HashTable()
	{
		size = 8;
		bucket = new Bucket[size];
		capacity = 0;

		for (int i = 0; i < size; i++)
		{
			bucket[i].head = nullptr;
			bucket[i].count = 0;
		}
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
		capacity++;
	}

	const int& bucket_count()
	{
		return size;
	}

	void erase(KEY key)
	{
		int hashIndex = hash_function(key);

		Node* currentNode = bucket[hashIndex].head;

		Node* previousNode = nullptr;

		if (currentNode == nullptr)
		{
			cout << "not key found" << endl;

			return;
		}

		else
		{
			while (currentNode != nullptr)
			{
				if (currentNode->key == key)
				{
					if (currentNode == bucket[hashIndex].head)
					{
						bucket[hashIndex].head = currentNode->next;
					}

					else
					{
						previousNode->next = currentNode->next;
					}

					bucket[hashIndex].count--;
					capacity--;
					delete currentNode;
					return;
				}

				else
				{
					previousNode = currentNode;
					currentNode = currentNode->next;
				}
			}
			cout << "not key found" << endl;
		}
	}

	const float& load_factor()
	{
		return (float)capacity / size;
	}

	~HashTable()
	{
		for (int i = 0; i < size; i++)
		{
			Node* deleteNode = bucket[i].head;
			Node* nextNode = deleteNode;

			if (bucket[i].head == nullptr)
			{
				continue;
			}

			else
			{
				while (nextNode != nullptr)
				{
					nextNode = nextNode->next;
					delete deleteNode;
					deleteNode = nextNode;
				}
			}
		}

		delete[] bucket;
	}
};

int main()
{
	HashTable<const char*, int> hashTable;

	hashTable.insert("운석", 200);
	hashTable.insert("생명의 나무", 200);
	hashTable.insert("미스릴", 250);

	cout << hashTable.load_factor() << endl;

	hashTable.erase("운석");
	hashTable.erase("생명의 나무");
	hashTable.erase("미스릴");
	hashTable.erase("VF혈액샘플");

	return 0;
}