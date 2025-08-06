#include <iostream>

using namespace std;

template <typename T>
class Set
{
private:
	struct Node
	{
		T data;
		Node* left = nullptr;
		Node* right = nullptr;

		Node(T data)
		{
			this->data = data;
		}
	};

	Node* root;
public:
	Set()
	{
		root = nullptr;
	}

	void insert(T data)
	{
		Node * newNode = new Node(data);
		
		if(root == nullptr)
		{
			root = newNode;
		}

		else
		{
			Node* currentNode = root;

			while (currentNode != nullptr)
			{
				if (currentNode->data > data)
				{
					delete newNode;

					return;
				}

				else if (currentNode->data < data)
				{
					if(currentNode->left == nullptr)
					{
						currentNode->left = newNode;

						break;
					}
					else
					{
						currentNode = currentNode->left;
					}
				}

				else
				{
					if (currentNode->right == nullptr)
					{
						currentNode->right = newNode;

						break;
					}

					else
					{
						currentNode = currentNode->right;
					}
				}
			}
		}
	}

	void release(Node * root)
	{
		if (root != nullptr)
		{
			release(root->left);
			release(root->right);

			delete root;
		}
	}

	void erase(T data)
	{
		Node* currentNode = root;
		Node* parentNode = nullptr;

		while(currentNode != nullptr && currentNode->data != data)
		{
			parentNode = currentNode;

			if(currentNode->data > data)
			{
				currentNode = currentNode->left;
			}

			else
			{
				currentNode = currentNode->right;
			}
		}

		if (currentNode == nullptr)
		{
			cout << "삭제할 대상이 없습니다." << endl;
		}

		else if (currentNode->left == nullptr && currentNode->right == nullptr)
		{
			if (parentNode != nullptr)
			{
				if (parentNode->left == currentNode)
				{
					parentNode->left = nullptr;
				}

				else
				{
					parentNode->right = nullptr;
				}
			}

			else
			{
				root = nullptr;
			}

			delete currentNode;
		}
		
		
		else if (currentNode->left == nullptr || currentNode->right == nullptr)
		{
			if (currentNode == nullptr)
			{
				if (currentNode->left != nullptr)
				{
					root = currentNode->left;
				}

				else
				{
					root = currentNode->right;
				}
			}

			else
			{
				if (currentNode->left != nullptr)
				{
					parentNode->left = currentNode->left;
				}

				else
				{
					parentNode->right = currentNode->right;
				}
			}

			delete currentNode;
		}

		else if(currentNode->left != nullptr && currentNode->left != nullptr)
		{
			
		}
	}

	~Set()
	{
		release(root);
	}
};

int main()
{
	Set<int> set;

	set.insert(10);
	set.insert(6);
	set.insert(20);
	set.insert(3);
	set.insert(15);

	set.erase(6);

	return 0;
}