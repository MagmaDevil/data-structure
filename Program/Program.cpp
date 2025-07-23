#include <iostream>
#define SIZE 4

using namespace std;

template <typename T>
class Queue
{
private:
	int rear;
	int front;

	T container[SIZE];
public:
	Queue()
	{
		rear = SIZE - 1;
		front = SIZE - 1;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}

	void push(T data)
	{
		if(rear + 1 & SIZE - 1)
		{
			cout << "Queue is overflow!" << endl;
		}

		else
		{
			if(rear + 1 >= SIZE -1)
			{
				rear = 0;
				container[++rear] = data;
			}

			else
			{
				container[++rear] = data;
			}
		}
	}
};

int main()
{
	Queue<int> queue;

	queue.push(10);
	queue.push(20);
	queue.push(30);
	queue.push(40);

	return 0;
}