#pragma once
#include <iostream>
#include "TreeNode.h"

template <class T> class Tree
{
private:
	TreeNode<T> *root;

protected:

	bool addToNode(TreeNode<T>* destination, TreeNode<T>* newNode)
	{
		if (destination == NULL) 
		{
			return true;
		}
		if (destination->getInfo() < newNode->getInfo())
		{
			if (addToNode(destination->getRightNode(), newNode))
				destination->setRightNode(newNode);
			return false;
		}
		if (destination->getInfo() > newNode->getInfo())
		{
			if (addToNode(destination->getLeftNode(), newNode))
				destination->setLeftNode(newNode);
			return false;
		}
		return false;
	}

	void postorder(TreeNode<T>* node)
	{
		if (node == NULL)
		{
			return;
		}
		preorder(node->getLeftNode());
		preorder(node->getRightNode());
		std::cout << node->getInfo() << " ";
	}

	void preorder(TreeNode<T>* node)
	{
		if (node == NULL)
		{
			return;
		}
		std::cout << node->getInfo() << " ";
		preorder(node->getLeftNode()); 
		preorder(node->getRightNode());
		
	}

public:

	Tree(T rootVal)
	{
		root = new TreeNode<int>(rootVal);
	}
	~Tree(){}

	

	void addNode(TreeNode<T>* newNode)
	{
		addToNode(root, newNode);
	}
	void viewPostorder() 
	{
		postorder(root);
	}
	void viewPreorder()
	{
		preorder(root);
	}
	TreeNode<T>* getMaxNode() 
	{
		TreeNode<T>* node = root;
		while (node->getRightNode()) {
			node = node->getRightNode();
		}
		return node;
	}
	TreeNode<T>* getMinNode() 
	{
		TreeNode<T>* node = root;
		while (node->getLeftNode()) {
			node = node->getLeftNode();
		}
		return node;
	}
	TreeNode<T>* getRoot()
	{
		return root;
	}
};

