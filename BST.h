/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 5 - Building a Database with BST*/

#pragma once
#include <iostream>
#include "TreeNode.h"
#include <fstream>
using namespace std;

//convert to a template
//BUILD THE TREE

template <class T, class V>
class BST
{
private:
	
	void serializationNode(TreeNode<T, V>* node, ofstream& file);

public:
	TreeNode<T, V>* root; //pointer to the root!!!
	//constructor and destructor
	BST();
	~BST();
	int insertRun = 0;

	//return key
	T searchWithValue(V value);
	//return value
	V searchWithKey(T key);

	void insert(T key, V value);
	//add delete function here!
	bool deleteNode(T key);
	//maybe make another delete for the key????

	//helper functions
	bool isEmpty();
	TreeNode<T, V>* getMin();
	TreeNode<T, V>* getMax();
	TreeNode<T, V>* getSuccessor(TreeNode<T,V>* d);
	void printTree();
	TreeNode<T,V>* peek();
	void serialization(string newFileName);
	
	// a recursive function that allows subtree to print not just the whole tree
	void recPrint(TreeNode<T,V>* node);

	//create a variable to see how many nodes are even in the tree
	unsigned int numberNodes =0;
};


//exceptions 
class nodeDNEexception : public runtime_error
{
public:
	nodeDNEexception(string message) :runtime_error(message.c_str())
	{}
};

class treeEmptyException : public runtime_error
{
public:
	treeEmptyException(string message) :runtime_error(message.c_str())
	{}
};


//constrcutor
template <class T, class V>
BST<T,V>::BST()
{
	//initialize the root
	root = NULL; //empty tree
}

//destructor
template <class T, class V>
BST<T,V>::~BST()
{
	//FILL IN
}

template <class T, class V>
bool BST<T,V>::isEmpty()
{
	if (root == NULL)
	{
		return true;
	}
}

template <class T, class V>
TreeNode<T,V>* BST<T, V>::peek()
{
	if (root==NULL)
	{
		throw runtime_error("tree is empty - cannot peek");
	}
	//cout << "not empty" << endl;
	return root;
}

//allows to print only the subtrees
template <class T, class V>
void BST<T,V>::recPrint(TreeNode<T,V>* node)
{
	//make sure the tree is not empty
	if (node == NULL)
	{
		return;
	}
	//if tree is not empty
	recPrint(node->left);
	//dereference the node->value!!
	cout << "key: " << node->key <<"\tvalue: " <<*(node->value)<< endl;
	recPrint(node->right);
}

//prints the entire tree
template <class T, class V>
void BST<T,V>::printTree()
{
	if (root == NULL)
	{
		throw treeEmptyException("The tree is empty");
	}
	recPrint(root);
}

//traverses the tree inorder to write to it
template <class T, class V>
void BST<T, V>::serialization(string newFileName)
{
	ofstream file;
	//cout << "after file" <<endl;
	file.open(newFileName);
	//cout << "after open file" << endl;
	serializationNode(root, file);
	file.close();
	//cout << "File is closed" << endl;
}

template <class T, class V>
void BST<T, V>::serializationNode(TreeNode<T,V>* node, ofstream& file)
{
	//check to see if the node is null
	if (node == NULL)
	{
		//cout << "enters if statement" << endl;
		return;
	}
	//INORDER TRAVERSAL
	//write the left node to the file
	serializationNode(node->left, file);
	//cout << "after serializationNode left" << endl;
	file << *(node->value) << endl;
	//cout << "after file input" << endl;
	//write the right node to the file
	serializationNode(node->right, file);
	//cout << "after serializationNode right" << endl;
}

//a function of type TreeNode
template <class T, class V>
TreeNode<T,V>* BST<T,V>::getMax()
{
	TreeNode<T, V>** current = root;

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

template <class T, class V>
TreeNode<T,V>* BST<T,V>::getMin()
{
	TreeNode<T, V>** current = root;

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
template <class T, class V>
void BST<T,V>::insert(T key, V value)
{
	insertRun++;
	
	//have to check to see if the tree is empty
	TreeNode<T, V>* node = new TreeNode<T,V>(key, value);
	if (root == NULL)
	{
		//tree is empty
		root = node;
		numberNodes++;
		//cout << "number of nodes1: " << numberNodes << endl;
	}
	else
	{
		//tree is not empty, find the insertion location
		//search the tree to find the point
		TreeNode<T, V>* current = root; //start the current node at the root
		TreeNode<T, V>* parent = NULL;

		while (current != NULL)//can also say current != NULL
		{
			parent = current;
			if (key < current->key)
			{
				current = current->left;
				if (current == NULL)
				{
					//we found the insertion point - update the parent
					parent->left = node;
					numberNodes++;
					//cout << "number of nodes2: " << numberNodes << endl;
					break;
				}
				//going left
			}
			else
			{
				//go right
				current = current->right;
				if (current == NULL)
				{
					//we found the insertion point - update the parent
					parent->right = node;
					numberNodes++;
					//cout << "number of nodes3: " << numberNodes << endl;
					break;
				}
			}
		}
	}
	//cout << "insert run: " << insertRun << endl;
}

template <class T, class V>
T BST<T,V>::searchWithValue(V value)
{
	if (root == NULL) //empty tree
	{
		throw runtime_error("Tree is empty");
	}
	else
	{
		//tree is not empty - look for the student passed in in the student tree
		TreeNode<T, V>* current = root;
		while (current->value != value)
		{
			if (value < current->value)
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
				throw runtime_error("value could not be found");
			}
		}
		return current->key;
	}
}

template <class T, class V>
V BST<T, V>::searchWithKey(T key)
{
	if (root == NULL) //empty tree
	{
		throw runtime_error("tree is empty");
	}
	else
	{
		//tree is not empty - look for the student passed in in the student tree
		TreeNode<T, V>* current = root;
		while (current->key != key)
		{
			if (key < current->key)
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
				throw runtime_error("key could not be found");
			}
		}
		return current->value;
	}
}

template <class T, class V>
bool BST<T,V>::deleteNode(T key)
{
	//check to see if the tree is empty
	if (root = NULL)
	{
		return false;
		TreeNode<T,V>* current = root;
		TreeNode<T,V>* parent = root;
		bool isLeft = true; // determines whether the node is a left child or not

		//now were going to search for the node
		while (current->key != key)
		{
			parent = current;
			if (key < current->key)
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
				TreeNode<T,V>* successor = getSuccessor(current);

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

template <class T, class V>
TreeNode<T,V>* BST<T,V>::getSuccessor(TreeNode<T,V>* d) // d is the node to be deleted
{
	//sp = successor parent
	TreeNode<T, V>* sp = d; //node to be deleted
	TreeNode<T, V>* successor = d;
	//start one right
	TreeNode<T, V>* current = d->right;

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

