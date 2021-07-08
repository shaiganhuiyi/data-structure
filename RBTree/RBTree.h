#pragma once

enum Color{RED,LACK};
template<class T>
struct RBTreeNode
{
	//�ڵ�Ĭ����ɫ����Ϊ��ɫ����Ϊ����Ǻ�ɫ�����ں�����в����½ڵ�ʱ��
	//���ƻ������ģ���ÿ��·���к�ɫ�ڵ����������ͬ��
	//����Ǻ�ɫ�����ں�����в����½ڵ�ʱ��ֻҪ�����½ڵ���˫��
	//�ڵ����ɫ���Ǻ�ɫ��û��ʲôӰ��
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
		//�����������һ�Ŷ���������
		//�Ȱ��ն����������Ĺ�������½ڵ�
		Node*& root = GetRoot();
		//����
		if (nullptr == root)
		{
			root = new Node(data, BLACK);
			root->parent = head;
			head->left = root;
			head->right = root;
			return true;
		}
		//������ǿգ����Ҵ�����ڵ������е�λ�ò�������˫��
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
		//�����½ڵ�
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