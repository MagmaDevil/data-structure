#include <iostream>

using namespace std;

template <typename T>
class Vector
{
private:
	int count;
	int capacity;
	T* container;

public:
	Vector()
	{
		count = 0;
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

		for (int i = 0; i < count; i++)
		{
			temporary[i] = container[i];
		}

		if (container != nullptr)
		{
			delete[] container;
		}

		container = temporary;
	}

	void push_back(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}

		else if (count >= capacity)
		{
			resize(capacity * 2);
		}
		container[count++] = data;
	}

	const int& size()
	{
		return count;
	}

	void pop_back()
	{
		if (count <= 0)
		{
			cout << "Vector is empty!" << endl;
		}

		else
		{
			container[--count] = NULL;
		}
	}

	const T& operator[] (const int& index)
	{
		return container[index];
	}

	~Vector()
	{
		if (container != nullptr)
		{
			delete[] container;
		}
	}
};

int main()
{
	Vector<int> vector;

	vector.push_back(10);
	vector.push_back(20);
	vector.push_back(30);
	vector.push_back(40);

	vector.pop_back();

	for (int i = 0; i < vector.size(); i++)
	{
		cout << vector[i] << endl;
	}

	return 0;
}