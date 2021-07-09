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
	bool Insert1(const T& data) //����
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
	//bool Insert2(Node BST, const T& data)
	//{
	//	if (!BST) {
	//		BST = new Node(x);
	//	}
	//	else
	//	{
	//		if (data < BST->data)
	//			Insert2(BST->left, data);
	//		else if (data > BST->data)
	//			Insert2(BST->right, data);
	//	}
	//	return true;
	//}
	bool Erase(const T& data)
	{
		//�ж����Ƿ�Ϊ��
		if (nullptr == root)
			return false;
		//1.�ҵ���ɾ���ڵ������е�λ�ã�����¼�丸�ڵ㡣
		Node* cur = root;
		Node* parent = nullptr;
		while (cur)
		{
			if (data == cur->data)
				break;
			else if (data < cur->data)
			{
				parent = cur;
				cur = cur->left;
			}
			else if (data > cur->data)
			{
				parent = cur;
				cur = cur->right;
			}
		}
		//�������û�д�ɾ����Ӧ�Ľڵ�
		if (nullptr == cur)
			return false;
		//�ҵ���ɾ���ڵ��λ��-->����ɾ��
		if (nullptr == cur->left)
		{
			//curֻ���Һ��ӻ���cur��Ҷ�ӽڵ�
			if (nullptr == parent)
				//curһ���Ǹ��ڵ�
				root = cur->right;
			//delete cur;
			else {
				if (cur == parent->left)
					parent->left = cur->right;
				else
					parent->right = cur->right;
		    //delete cur;
			}
		}
		else if(nullptr == cur->right)
		{
			//curֻ������
			if (nullptr == parent)
			{
				root = cur->left;
				//delete cur;
			}
			else {
				if (cur == parent->left)
					parent->left = cur->left;
				else
					parent->right = cur->left;
                //delete cur;
			}
		}
		else
		{
			//cur���Һ��Ӷ���
		    //1.��cur����������һ������ڵ�--���������в��Ҿ���
			//һ��������������������в��ҵ�
			//�������в���ʱһ��ʱ���Ľڵ㣬Ҳ�������Ҳ�ڵ�
			//�������в���ʱһ��ʱ���µĽڵ㣬Ҳ���������ڵ�
			Node* del = cur->right;
			//parent = cur;
			
			while (del->left)
			{
				parent = del;
				del = del->left;
			}
			//2.������ڵ��е�ֵ��ֵ����ɾ���ڵ�
			cur->data = del->data;
			//3.ɾ������ڵ�
			if (del == parent->left)
				parent->left = del->right;
			else
				parent->right = del - right;
			cur = del;
		}
		delete cur;
		return true;
	}
	void InOrder()
	{
		_InOrder(root);
		std::cout <<std::endl;
	}
	~BSTree()
	{
		_DestroyBSTree(root);
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
	void _DestroyBSTree(Node*& pRoot)
	{
		if (pRoot)
		{
			_DestroyBSTree(pRoot->left);
			_DestroyBSTree(pRoot->right);
			delete pRoot;
			pRoot = nullptr;
		}
	}
};

int TestBSTree()
{
	int a[] = { 5,3,4,1,7,8,2,6,0,9 };
	BSTree<int> t;
	for (auto e : a)
	{
		t.Insert1(e);
	}
	t.InOrder(); 
	return 0;
}