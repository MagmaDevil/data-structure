#include <iostream>

using namespace std;

template <typename T>
class Set
{
private:
	struct Node
	{
		T data;
		Node* left;
		Node* right;
	};

	Node* root;
public:
	Set()
	{
		root = nullptr;
	}

	void insert(T data)
	{
		if(root == nullptr)
		{
			root->data = data;
		}

		Node* currentNode = root;
		Node * newNode = new Node;
		newNode = data;

		if (data < root->data)
		{
			currentNode->left = newNode;
		}

		else if(data > root->data)
		{
			currentNode->right = newNode;
		}
	}
};

int main()
{
	Set<int> set;

	set.insert(10);
	set.insert(5);
	set.insert(15);

	return 0;
}