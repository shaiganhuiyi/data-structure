#pragma once

template<class T>
struct  BSTNode
{
	BSTNode(const T& val= T())
		: left(nullptr)
		, right(nullptr)
		, data(val)
	 {}
	BSTNode<T>* left;
	BSTNode<T>* right;
	T data;
};

template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
public:
	BSTree()
		: root(nullptr)
	{}
	Node* Find(const T& data)  //查找
	{
		Node* cur = root;
		while (cur)
		{
			if (data == cur->data)
				return cur;
			else if (data < cur->data)
				cur = cur->left;
			else
				cur = cur->right;
		}
		return nullptr;
	}
	bool Insert(const T& data) //插入
	{
		//插入的树是空树
		if (nullptr == root)
		{
			root = new Node(data);
			return true;
		}
		//非空
		//找待插入元素在树中的位置，并保存其双亲
		Node* cur = root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (data < cur->data)
				cur = cur->left;
			else if (data > cur->data)
				cur = cur->right;
			else
				return false;
		}
		//插入新节点
		cur = new Node(data);
		if (data < parent->data)
			parent->left = cur;
		else
			parent->right = cur;
		return true;
		
	}
	void InOrder()
	{
		_InOrder(root);
		std::cout <<std::endl;
	}

	

private:
	Node* root;
	void _InOrder(Node* pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->left);
			std::cout << pRoot->data << " ";
			_InOrder(pRoot->right);
		}
	}
};

int TestBSTree()
{
	int a[] = { 5,3,4,1,7,8,2,6,0,9 };
	BSTree<int> t;
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder(); 
	return 0;
}