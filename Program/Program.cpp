#include <iostream>

using namespace std;

template <typename T>
class Graph
{
private:

	struct Node
	{
		T data;
		Node* next;

		Node(T data, Node* link = nullptr)
		{
			this->data = data;
			next = link;
		}
	};

	int size;		   //정점의 개수
	int capacity;	   //최대 용량
	T* vertex;		   //정점의 집합
	Node ** list;      //인접 리스트
	int count;		   //인접 행렬의 크기

public:
	Graph()
	{
		size = 0;
		capacity = 0;
		vertex = nullptr;
		list = nullptr;
		count = 0;
	}

	void resize()
	{
		Node ** newlist = new Node * [size];

		for (int i = 0; i < count; i++)
		{
			newlist[i] = nullptr;
		}

		for (int i = 0; i < count; i++)
		{
			newlist[i] = list[i];
		}

		if (list != nullptr)
		{
			for (int i = 0; i < count; i++)
			{
				delete list[i];
			}
			delete[] list;
		}

		list = newlist;
		count = size;
	}

	void resize(int newSize)
	{
		capacity = newSize;

		T* temporary = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			temporary[i] = NULL;
		}

		for (int i = 0; i < size; i++)
		{
			temporary[i] = vertex[i];
		}

		if (vertex != nullptr)
		{
			delete[] vertex;
		}

		vertex = temporary;
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

		if(count > size)
		{
			resize();
		}

		vertex[size++] = data;
	}

	void edge(int i, int j)
	{
		if (size <= 0)
		{
			cout << "adjacency list is empty!" << endl;
		}

		else if (i >= size || j >= size)
		{
			cout << "index out of range!" << endl;
		}

		else
		{
			if (list == nullptr)
			{
				list = new Node * [size];

				for (int i = 0; i < size; i++)
				{
					list[i] = nullptr;
				}
			}

			else if (count < size)
			{
				resize();
			}

			count = size;

			list[i] = new Node(vertex[j], list[i]);
			list[j] = new Node(vertex[i], list[j]);


		}
	}

	~Graph()
	{
		for (int i = 0; i < size; i++)
		{
			Node* deleteNode = list[i];
			Node* nextNode = list[i];

			if (nextNode == nullptr)
			{
				continue;
			}

			else
			{
				while(nextNode != nullptr)
				{
					nextNode = nextNode->next;
					delete deleteNode;
					deleteNode = nextNode;
				}
			}
		}
		delete[] list;
		
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