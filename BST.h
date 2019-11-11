/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 5 - Building a Database with BST*/

#include <iostream>
using namespace std;

//tree of intergers!!!

//convert to a template
template <class T>
//make the node class
class TreeNode
{
public:
	TreeNode();
	TreeNode(int k); //k = key, which in this example is also the value/data
	~TreeNode(); //when creating a template class destructor must br virtual

	int key;
	TreeNode* left; //left pointer
	TreeNode* right; //right pointer
};

template <class T>
//defualt constructor
TreeNode<T>::TreeNode()
{
	//make sure the values are all empty
	key = NULL;
	left = NULL;
	right = NULL;
}

template <class T>
//overloaded constructor
TreeNode<T>::TreeNode(int k)
{
	//make sure the values are all empty
	key = NULL;
	left = NULL;
	right = NULL;
}

//destructor
template <class T>
TreeNode<T>::~TreeNode()
{
	//FILL IN
}

//BUILD THE TREE

template <class T>
class BST
{
private:
	TreeNode* root; //pointer to the root!!!

public:
	//constructor and destructor
	BST();
	~BST();

	bool search(int value);//value is the key
	void insert(int value);
	//add delete function here!
	bool deleteNode(int key);

	//helper functions
	bool isEmpty();
	TreeNode* getMin();
	TreeNode* getMax();
	TreeNode* getSuccessor(TreeNode* d);
	void printTree();
	// a recursive function that allows subtree to print not just the whole tree
	void recPrint(TreeNode* node);
};

//constrcutor
template <class T>
BST<T>::BST()
{
	//initialize the root
	root = NULL; //empty tree
}

//destructor
template <class T>
BST<T>::~BST()
{
	//FILL IN
}

template <class T>
bool BST<T>::isEmpty()
{
	if (root == NULL)
	{
		return true;
	}
}

//allows to print only the subtrees
template <class T>
void BST<T>::recPrint(TreeNode<T>* node)
{
	if (node == NULL)
	{
		return;
	}

	recPrint(node->left);
	cout << node->key << endl;
	recPrint(node->right);
}

//prints the entire tree
template <class T>
void BST<T>::printTree()
{
	recPrint(root);
}

//a function of type TreeNode
template <class T>
TreeNode<T>* BST<T>::getMax()
{
	TreeNode* current = root;

	//if tree is empty
	if (root = NULL)
	{
		return NULL;
	}

	while (current->right != NULL)
	{
		current = current->right;
	}

	//now you are all the way at the bottom right of the tree
	return (current);
}

template <class T>
TreeNode<T>* BST<T>::getMin()
{
	TreeNode* current = root;

	//if tree is empty
	if (root = NULL)
	{
		return NULL;
	}

	while (current->left != NULL)
	{
		current = current->left;
	}

	//now you are all the way at the bottom right of the tree
	return (current);
}

//insert is just a failed search??
template <class T>
void BST<T>::insert(int value)
{
	//have to check to see if the tree is empty
	TreeNode* node = new TreeNode(value);
	if (root == NULL)
	{
		//tree is empty
		root = node;
	}
	else
	{
		//tree is not empty, find the insertion location
		//search the tree to find the point
		TreeNode* current = root; //start the current node at the root
		TreeNode* parent = NULL;

		while (true)//can also say current != NULL
		{
			parent = current;
			if (value < current->key)
			{
				current = current->left;
				if (current = NULL)
				{
					//we found the insertion point - update the parent
					parent->left = node;
					break;
				}
				//going left
			}
			else
			{
				//go right
				current = current->right;
				if (current = NULL)
				{
					//we found the insertion point - update the parent
					parent->right = node;
					break;
				}
			}
		}
	}
}

template <class T>
bool BST<T>::search(int value)
{
	if (root == NULL) //empty tree
	{
		return false;
	}
	else
	{
		//tree is not empty - attempt to look for it
		TreeNode* current = root;
		while (current->key != value)
		{
			if (value < current->key)
			{
				current = current->left;
			}
			else
			{
				current = current->right;
			}
			if (current == NULL)
			{
				//did not find the value
				return false;
			}
		}
		return true;
	}
}

template <class T>
bool BST<T>::deleteNode(int value)
{
	//check to see if the tree is empty
	if (root = NULL)
	{
		return false;
		TreeNode* current = root;
		TreeNode* parent = root;
		bool isLeft = true; // determines whether the node is a left child or not

		//now were going to search for the node
		while (current->key != value)
		{
			parent = current;
			if (value < current->key)
			{
				isLeft = true;
				current = current->left;
			}
			else
			{
				isLeft = false;
				current = current->right;
			}
			if (current == NULL)
			{
				//did not find the value
				return false;
			}
			//if we make it here, we have found the node that needs to be deleted
			//now check the different cases

			//no children
			//check if node to be deleted is a leaf node
			if (current->left == NULL && current->right == NULL)
			{
				if (current == root)
				{
					root = NULL;
				}
				else if (isLeft)
				{
					parent->left = NULL;
				}
				else
				{
					parent->right = NULL;
				}
			}

			//node to be deleted has one child, we need to determine if child is left or right and continue
			else if (current->right == NULL) //child has no right child
			{
				if (current == root)
				{
					root = current->left;
				}
				else if (isLeft)
				{
					parent->left = current->left;
				}
				else
				{
					parent->right = current->left;
				}
			}
			//has no left child
			else if (current->left == NULL) //child has no right child
			{
				if (current == root)
				{
					root = current->right;
				}
				else if (isLeft)
				{
					parent->left = current->right;
				}
				else
				{
					parent->right = current->right;
				}
			}

			//the node to be deleted has two children
			else
			{
				TreeNode* successor = getSuccessor(current);

				if (current == root)
				{
					root = successor;
				}
				else if (isLeft)
				{
					parent->left = successor;
				}
				else
				{
					parent->right = successor;
				}

				successor->left = current->left;
			}
			return true;
		}
	}
}

template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T>* T) // d is the node to be deleted
{
	//sp = successor parent
	TreeNode* sp = d; //node to be deleted
	TreeNode* successor = d;
	//start one right
	TreeNode* current = d->right;

	//one right and all the way left
	while (current != NULL)
	{
		sp = successor;
		successor = current;
		current = current->left;
	}

	if (successor != d->right)
		//successor is a descendant of the right child
	{
		sp->left = successor->right;
		successor->right = d->right;
	}

	return successor;
}

