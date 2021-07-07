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
	Node* Find(const T& data)  //����
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
	bool Insert(const T& data) //����
	{
		//��������ǿ���
		if (nullptr == root)
		{
			root = new Node(data);
			return true;
		}
		//�ǿ�
		//�Ҵ�����Ԫ�������е�λ�ã���������˫��
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
		//�����½ڵ�
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