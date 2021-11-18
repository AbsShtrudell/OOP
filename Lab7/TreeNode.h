#pragma once
template <class T> class TreeNode
{
private:
	TreeNode<T>* right, * left;
	T info;
public:
	TreeNode(T value)
	{
		info = value;
		right = nullptr;
		left = nullptr;
	}
	~TreeNode(){}

	TreeNode* getRightNode()
	{
		return right;
	}

	TreeNode* getLeftNode()
	{
		return left;
	}

	void setRightNode(TreeNode<T>* node)
	{
		right = node;
	}

	void setLeftNode(TreeNode<T>* node)
	{
		left = node;
	}

	T getInfo()
	{
		return info;
	}

	void setInfo(T newInfo)
	{
		info = newInfo;
	}
};

