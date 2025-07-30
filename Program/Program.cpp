#include <iostream>

using namespace std;

template <typename T>
class Graph
{
private:
	int size;            	 //정점의 개수
	int capacity;			 //최대 용량
	T* vertex;				 //정점의 집합
	int** matrix;			 //인접 행렬
	int count;				 //인접 행렬의 크기

public:
	Graph()
	{
		size = 0;
		capacity = 0;
		vertex = nullptr;
		matrix = nullptr;
		count = 0;
	}

	void resize(int newSize)
	{
		capacity = newSize;

		T* container = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			container[i] = NULL;
		}

		for (int i = 0; i < size; i++)
		{
			container[i] = vertex[i];
		}

		if (vertex != nullptr)
		{
			delete[] vertex;
		}

		vertex = container;
	}

	void push(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}

		else if (size >= capacity)
		{
			resize(capacity * 2);
		}
		vertex[size++] = data;
	}

	void edge(int i, int j)
	{
		if(vertex == nullptr)
		{
			cout << "adjacency matrix is empty!" << endl;
		}

		else if(i >= size || j >= size)
		{
			cout << "index out of range!" << endl;
		}

		else
		{
			if(matrix == nullptr)
			{
				count = size;

				matrix = new int* [size];

				for (int i = 0; i < size; i++)
				{
					matrix[i] = new int[size];

					for (int j = 0; j < size; j++)
					{
						matrix[i][j] = 0;
					}
				}
			}
			matrix[i][j] = 1;
			matrix[j][i] = 1;
		}
	}

	~Graph()
	{
		if(matrix != nullptr)
		{
			for (int i = 0; i < size; i++)
			{
				delete[] matrix[i];
			}

			delete[] matrix;
		}

		delete[] vertex;
	}
};

int main()
{
	Graph<char> graph;

	graph.push('A');
	graph.push('B');
	graph.push('C');

	graph.edge(0, 1);

	return 0;
}