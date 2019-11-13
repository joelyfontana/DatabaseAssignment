/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 5 - Building a Database with BST*/

template <class T, class V>
//make the node class
class TreeNode
{
public:
	TreeNode();
	TreeNode(T k, V value); //k = key, which in this example is also the value/data
	~TreeNode(); //when creating a template class destructor must br virtual

	//ket is of template T
	T key;
	V value;
	TreeNode<T,V>* left; //left pointer
	TreeNode<T,V>* right; //right pointer
};

template <class T, class V>
//defualt constructor
TreeNode<T,V>::TreeNode()
{
	//make sure the values are all empty
	key = NULL;
	left = NULL;
	right = NULL;
}

template <class T, class V>//overloaded constructor
TreeNode<T,V>::TreeNode(T k, V value)
{
	//make sure the values are all empty
	key = NULL;
	left = NULL;
	right = NULL;
}

//destructor
template <class T, class V>
TreeNode<T,V>::~TreeNode()
{
	//FILL IN
}