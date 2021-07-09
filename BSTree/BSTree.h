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
	bool Insert1(const T& data) //插入
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
		//判断树是否为空
		if (nullptr == root)
			return false;
		//1.找到待删除节点再树中的位置，并记录其父节点。
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
		//如果树中没有待删除对应的节点
		if (nullptr == cur)
			return false;
		//找到待删除节点的位置-->进行删除
		if (nullptr == cur->left)
		{
			//cur只有右孩子或者cur是叶子节点
			if (nullptr == parent)
				//cur一定是根节点
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
			//cur只有左孩子
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
			//cur左右孩子都有
		    //1.在cur的子树中找一个替代节点--左右子树中查找均可
			//一般情况下是在左右子树中查找的
			//左子树中查找时一定时最大的节点，也就是最右侧节点
			//右子树中查找时一定时最下的节点，也就是最左侧节点
			Node* del = cur->right;
			//parent = cur;
			
			while (del->left)
			{
				parent = del;
				del = del->left;
			}
			//2.将替代节点中的值域赋值给待删除节点
			cur->data = del->data;
			//3.删除替代节点
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