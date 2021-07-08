#pragma once

enum Color{RED,LACK};
template<class T>
struct RBTreeNode
{
	//节点默认颜色设置为红色。因为如果是黑色，当在红黑树中插入新节点时，
	//会破坏性质四，即每条路径中黑色节点个数必须相同。
	//如果是红色，当在红黑树中插入新节点时，只要插入新节点其双亲
	//节点的颜色不是红色就没有什么影响
	RBTreeNode(const T& x, Color color = RED)
		:left(nullptr)
		, right(nullptr)
		, parent(nullptr)
		, data(x)
		, color(c)
	{}
	RBTreeNode<T>* left;
	RBTreeNode<T>* right;
	RBTreeNode<T>* parent;
	T data;
	Color color;
};

template<class  T>
class RBTree
{
	typedef RBTreeNode<T> Node;

public:
	RBTree()
	{
		head = new Node();
		head->left = nullptr;
		head->right = nullptr;
	}
	bool Insert(const T& data)
	{
		//红黑树首先是一颗二叉搜索树
		//先按照二叉搜索树的规则插入新节点
		Node*& root = GetRoot();
		//空树
		if (nullptr == root)
		{
			root = new Node(data, BLACK);
			root->parent = head;
			head->left = root;
			head->right = root;
			return true;
		}
		//如果树非空：查找待插入节点在树中的位置并保存其双亲
		Node* cur = root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (data < cur - data)
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
		cur->parent = parent;
		 
	}
	Node*& GetRoot()
	{
		return head->parent;
	}
private:
	Node* head;
};