#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <cstring>
template <typename T>
int compara(T firstValue, T secondValue)
{
	if (firstValue < secondValue)
	{
		return -1;
	}
	else if (firstValue > secondValue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template <>
int compara <char*>(char* firstValue, char* secondValue)
{
	return strcmp(firstValue, secondValue);
}

template <typename T>
int compara2(T firstValue, T secondValue)
{
	if (firstValue > secondValue)
	{
		return -1;
	}
	else if (firstValue < secondValue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
template<>
int compara<const char*>(const char* firstValue, const char* secondValue)
{
	if (firstValue < secondValue)
	{
		return -1;
	}
	else if (firstValue > secondValue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
template <typename T>
struct Node
{
	T value;
	Node<T>** children;
	unsigned int nrChildren;
};

template <class T>
class Tree
{
public:
	Node<T>* root;
	unsigned int maxChildrenPerNode;

	Tree(unsigned int nrChildren)
	{
		maxChildrenPerNode = nrChildren;
		root = nullptr;
	}

	void add_node(Node<T>* parent, T value)
	{
		if (parent == nullptr)
		{
			root = new Node<T>;
			root->value = value;
			root->nrChildren = 0;
			root->children = new Node<T>*[maxChildrenPerNode] {};
		}
		else
		{
			parent->children[parent->children] = new Node<T>;
			parent->children[parent->children]->value = value;
			parent->children[parent->children]->nrChildren = 0;
			parent->children[parent->nrChildren]->children = new Node<T>*[maxChildrenPerNode] {};
			parent->nrChildren++;
		}
	}

	void sort(Node<T>* parinte, int (*comparatie)(T, T))
	{
		unsigned int i, j;
		for(i=0; i<parinte->nrChildren-1; i++)
			for (j = i + 1; j < parinte->nrChildren; j++)
			{
				if (comparatie(parinte->children[i]->value, parinte->children[j]->value) > 0)
				{
					T aux;
					aux = parinte->children[i]->value;
					parinte->children[i]->value = parinte->children[j]->value;
					parinte->children[j]->value = aux;
				}
			}
	}
	Node<T>* get_node(unsigned int index = 0, Node<T>* parent = nullptr)
	{
		if (parent == nullptr)
			return root;
		if (index < parent->nrChildren)
			return (parent->children[index]);
		return parent->children[0];
	}
	void delete_node(Node<T>* node)
	{
		unsigned int i;
		if (node == nullptr)
			return;
		for (i = 0; i < node->nrChildren; i++)
			delete_node(node->children[i]);
		delete[]node->children;
		delete[] node->value;
		delete node;
	}
	int count(Node<T>* parinte)
	{
		if (parinte == nullptr)
			return 0;
		unsigned int suma = 0;
		for (unsigned int i = 0; i < parinte->nrChildren; i++)
		{
			suma += count(parinte->children[i]);
		}
		return suma + parinte->nrChildren;
	}

	void insert(Node<T>* parinte, T value, unsigned int poz)
	{
		if (parinte == nullptr)
		{
			root = new Node<T>;
			root->value = value;
			root->nrChildren = 0;
			root->children = new Node<T>*[maxChildrenPerNode] {};
		}
		else
		{
			if (poz < parinte->nrChildren)
			{
				for (unsigned int i = parinte->nrChildren; i > poz; i--)
				{
					parinte->children[i] = parinte->children[i - 1];
				}
				parinte->children[poz] = new Node<T>;
				parinte->children[poz]->value = value;
				parinte->children[poz]->nrChildren = 0;
				parinte->children[poz]->children = new Node<T>*[maxChildrenPerNode] {};
				parinte->nrChildren++;
			}
			else
			{
				parinte->children[parinte->nrChildren] = new Node<T>;
				parinte->children[parinte->nrChildren]->value = value;
				parinte->children[parinte->nrChildren]->nrChildren = 0;
				parinte->children[parinte->nrChildren]->children = new Node<T>*[maxChildrenPerNode] {};
				parinte->nrChildren++;
			}
		}
	}
	Node<T>* find(Node<T>* parinte, int value, int (*comparatie)(T, T))
	{
		if (parinte == nullptr)
			return nullptr;
		if (strcmp(parinte->value, value) == 0)
			return parinte;
		for (unsigned int i = 0; i < parinte->nrChildren; i++)
		{
			Node<T> temp = find(parinte->children[i], value, compara);
			if (temp != nullptr)
				return temp;
		}
		return nullptr;
	}
	void printNodes(Node<T>* parinte)
	{
		unsigned int i;
		for (i = 0; i < parinte->nrChildren; i++)
		{
			printf("%d ", parinte->children[i]->value);
		}
	}
};


template <>
class Tree <char*>
{
public:
	Node<char*>* root;
	unsigned int maxChildrenPerNode;

	Tree(unsigned int nrChildren)
	{
		maxChildrenPerNode = nrChildren;
		root = nullptr;
	}

	void add_node(Node<char*>* parent, const char* value)
	{
		if (parent == nullptr)
		{
			root = new Node<char*>;
			//root->value = value;
			root->value = new char[100] {};
			strcpy(root->value, value);
			root->nrChildren = 0;
			root->children = new Node<char*>*[maxChildrenPerNode] {};
		}
		else
		{
			parent->children[parent->nrChildren] = new Node<char*>;
			//parent->children[parent->nrChildren]->value = value;
			parent->children[parent->nrChildren]->value = new char[100] {};
			strcpy(parent->children[parent->nrChildren]->value, value);
			parent->children[parent->nrChildren]->nrChildren = 0;
			parent->children[parent->nrChildren]->children = new Node<char*>*[maxChildrenPerNode] {};
			parent->nrChildren++;
		}
	}

	void sort(Node<char*>* parinte, int (*comparatie)(char*, char*))
	{
		unsigned int i, j;
		for (i = 0; i < parinte->nrChildren - 1; i++)
			for (j = i + 1; j < parinte->nrChildren; j++)
			{
				if (comparatie(parinte->children[i]->value, parinte->children[j]->value) > 0)
				{
					char* aux;
					aux = parinte->children[i]->value;
					parinte->children[i]->value = parinte->children[j]->value;
					parinte->children[j]->value = aux;
				}
			}
	}
	Node<char*>* get_node(unsigned int index = 0, Node<char*>* parent = nullptr)
	{
		if (parent == nullptr)
			return root;
		if(index<parent->nrChildren)
			return (parent->children[index]);
		return parent->children[0];
	}
	void delete_node(Node<char*>* parent, unsigned int poz)
	{
		if (parent == nullptr)
			return;
		if (poz < parent->nrChildren)
		{
			delete[] parent->children[poz]->children;
			for (unsigned int i = poz; i < parent->nrChildren - 1; i++)
			{
				parent->children[i] = parent->children[i + 1];
			}
			parent->nrChildren--;
		}
	}
	Node<char*>* find(Node<char*>* parinte, const char* value, int (*comparatie)(char*, char*))
	{
		if (parinte == nullptr)
			return nullptr;
		if (strcmp(parinte->value, value) == 0)
			return parinte;
		for (unsigned int i = 0; i < parinte->nrChildren; i++)
		{
			Node<char*>* temp = find(parinte->children[i], value, compara);
			if (temp != nullptr)
				return temp;
		}
		return nullptr;
	}
	int count(Node<char*>* startNode = nullptr)
	{
		if (startNode == nullptr)
			startNode = root;

		if (startNode == nullptr)
			return 0;

		unsigned int totalCount = startNode->nrChildren;
		for (unsigned int i = 0; i < startNode->nrChildren; ++i)
		{
			totalCount += count(startNode->children[i]);
		}

		return totalCount;
	}
	void insert(Node<char*>* parinte, const char* value, unsigned int poz)
	{
		if (parinte == nullptr)
		{
			root = new Node<char*>;
			root->value = new char[100] {};
			strcpy(root->value, value);
			root->nrChildren = 0;
			root->children = new Node<char*>*[maxChildrenPerNode] {};
		}
		else
		{
			if (poz < parinte->nrChildren)
			{
				for (unsigned int i = parinte->nrChildren; i > poz; i--)
				{
					parinte->children[i] = parinte->children[i - 1];
				}
				parinte->children[poz] = new Node<char*>;
				parinte->children[poz]->value = new char[100] {};
				strcpy(parinte->children[poz]->value, value);
				parinte->children[poz]->nrChildren = 0;
				parinte->children[poz]->children = new Node<char*>*[maxChildrenPerNode] {};
				parinte->nrChildren++;
			}
			else
			{
				parinte->children[parinte->nrChildren] = new Node<char*>;
				parinte->children[parinte->nrChildren]->value = new char[100] {};
				strcpy(parinte->children[parinte->nrChildren]->value, value);
				parinte->children[parinte->nrChildren]->nrChildren = 0;
				parinte->children[parinte->nrChildren]->children = new Node<char*>*[maxChildrenPerNode] {};
				parinte->nrChildren++;
			}
		}
	}
	void printNodes(Node<char*>* parinte)
	{
		unsigned int i;
		for (i = 0; i < parinte->nrChildren; i++)
		{
			printf("%s ", parinte->children[i]->value);
		}
	}
};