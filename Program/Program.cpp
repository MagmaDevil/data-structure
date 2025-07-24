#include <iostream>

using namespace std;

template <typename T>
class PriorityQueue
{
private:
	int index;
	int capacity;

	T* container;

public:
	PriorityQueue()
	{
		index = 0;
		capacity = 0;

		container = nullptr;
	}

	void resize(int newSize)
	{
		capacity = newSize;

		T* temporary = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			temporary[i] = NULL;
		}

		for (int i = 0; i < index; i++)
		{
			temporary[i] = container[i];
		}

		if (container != nullptr)
		{
			delete[] container;
		}

		container = temporary;
	}

	void push(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
			
		else if(index >= capacity)
		{
			resize(capacity * 2);
		}
		
		container[index++] = data;

		int child = index - 1;
		int parent = (child - 1) / 2;

		while (child > 0)
		{
			if (container[parent] < container[child])
			{
				swap(container[parent], container[child]);
			}

			child = parent;
			parent = (child - 1) / 2;
		}
	}

	const bool & empty()
	{
		return index == 0;
	}

	const int & size()
	{
		return index;
	}

	const T & top()
	{
		if (empty())
		{
			exit(1);
		}

		else
		{
			return container[0];
		}
	}

	~PriorityQueue()
	{
		if (container != nullptr)
		{
			delete[] container;
		}
	}
};

int main()
{
	PriorityQueue<int> priorityQueue;

	priorityQueue.push(17);
	priorityQueue.push(31);
	priorityQueue.push(9);
	priorityQueue.push(15);

	cout << priorityQueue.top() << endl;

	return 0;
}