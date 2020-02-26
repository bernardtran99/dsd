#include "pch.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class TreeNode
{
public:
	int height, data;
	TreeNode *left, *right;
	TreeNode()
	{
		left = NULL;
		right = NULL;
		data = 0;
		height = 0;
	}

	TreeNode(int n)
	{
		left = NULL;
		right = NULL;
		data = n;
		height = 0;
	}
};

class BST
{
private:
	TreeNode *root;
public:
	BST()
	{
		root = NULL;
	}

	bool isEmpty()
	{
		return root == NULL;
	}

	void makeEmpty()
	{
		root = NULL;
	}

	void insert(int data)
	{
		root = insert(data, root);
	}

	int height(TreeNode *t)
	{
		return t == NULL ? -1 : t->height;
	}

	int max(int lhs, int rhs)
	{
		return lhs > rhs ? lhs : rhs;
	}

	TreeNode *insert(int x, TreeNode *t)
	{
		if (t == NULL)
			t = new TreeNode(x);
		else if (x < t->data)
		{
			t->left = insert(x, t->left);
			if (height(t->left) - height(t->right) == 2)
				if (x < t->left->data)
					t = rotateLeftChild(t);
				else
					t = doubleLeftChild(t);
		}
		else if (x > t->data)
		{
			t->right = insert(x, t->right);
			if (height(t->right) - height(t->left) == 2)
				if (x > t->right->data)
					t = rotateRightChild(t);
				else
					t = doubleRightChild(t);
		}
		t->height = max(height(t->left), height(t->right)) + 1;
		return t;
	}

	TreeNode *rotateLeftChild(TreeNode* k2)
	{
		TreeNode *k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;
		k2->height = max(height(k2->left), height(k2->right)) + 1;
		k1->height = max(height(k1->left), k2->height) + 1;
		return k1;
	}

	TreeNode *rotateRightChild(TreeNode *k1)
	{
		TreeNode *k2 = k1->right;
		k1->right = k2->left;
		k2->left = k1;
		k1->height = max(height(k1->left), height(k1->right)) + 1;
		k2->height = max(height(k2->right), k1->height) + 1;
		return k2;
	}

	TreeNode *doubleLeftChild(TreeNode *k3)
	{
		k3->left = rotateRightChild(k3->left);
		return rotateLeftChild(k3);
	}

	TreeNode *doubleRightChild(TreeNode *k1)
	{
		k1->right = rotateLeftChild(k1->right);
		return rotateRightChild(k1);
	}

	int countNodes()
	{
		return countNodes(root);
	}

	int countNodes(TreeNode *r)
	{
		if (r == NULL)
			return 0;
		else
		{
			int l = 1;
			l += countNodes(r->left);
			l += countNodes(r->right);
			return l;
		}
	}

	bool search(int val)
	{
		return search(root, val);
	}

	bool search(TreeNode *r, int val)
	{
		bool found = false;
		while ((r != NULL) && !found)
		{
			int rval = r->data;
			if (val < rval)
				r = r->left;
			else if (val > rval)
				r = r->right;
			else
			{
				found = true;
				break;
			}
			found = search(r, val);
		}
		return found;
	}

	void inorder()
	{
		inorder(root);
	}

	void inorder(TreeNode *r)
	{
		if (r != NULL)
		{
			inorder(r->left);
			cout << r->data << "  ";
			inorder(r->right);
		}
	}

	void preorder()
	{
		preorder(root);
	}
	void preorder(TreeNode *r)
	{
		if (r != NULL)
		{
			cout << r->data << "  ";
			preorder(r->left);
			preorder(r->right);
		}
	}

	void postorder()
	{
		postorder(root);
	}
	void postorder(TreeNode *r)
	{
		if (r != NULL)
		{
			postorder(r->left);
			postorder(r->right);
			cout << r->data << "  ";
		}
	}
};

int main()
{
	BST MyTree;
	cout << "BST Test" << endl;
	int val;
	char ch;
	do
	{
		cout << "BST Operations" << endl;
		cout << "1. Insert " << endl;
		cout << "2. Count nodes" << endl;
		cout << "3. Search" << endl;
		cout << "4. Check empty" << endl;
		cout << "5. Make empty" << endl;
		int choice;
		cout << "Enter your Choice: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter integer element to insert: ";
			cin >> val;
			MyTree.insert(val);
			break;
		case 2:
			cout << "Nodes = " << MyTree.countNodes() << endl;
			break;
		case 3:
			cout << "Enter integer element to search: ";
			cin >> val;
			if (MyTree.search(val))
				cout << val << " found in the tree" << endl;
			else
				cout << val << " not found" << endl;
			break;
		case 4:
			cout << "Empty status = ";
			if (MyTree.isEmpty())
				cout << "Tree is empty" << endl;
			else
				cout << "Tree is non - empty" << endl;
			break;
		case 5:
			cout << "Tree cleared" << endl;
			MyTree.makeEmpty();
			break;
		default:
			cout << "Wrong Entry" << endl;
			break;
		}

		cout << "Post order : " << endl;
		MyTree.postorder();
		cout << "Pre order : " << endl;
		MyTree.preorder();
		cout << "In order : " << endl;
		MyTree.inorder();
		cout << "Do you want to continue (Type y or n): ";
		cin >> ch;
	}
	while (ch == 'Y' || ch == 'y');
	return 0;
}