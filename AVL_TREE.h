#ifndef AVL_TREE
#define AVL_TREE

#include <iostream>
using namespace std;

struct avl_node				// Node Declaration
{
    int data;
    struct avl_node *left;
    struct avl_node *right;
} *root;

class avlTree			  // Class Declaration
{
 public:
        int height(avl_node *parent);
        int difference(avl_node *parent);
        avl_node *rr(avl_node *parent);
        avl_node *ll(avl_node *parent);
        avl_node *lr(avl_node *parent);
        avl_node *rl(avl_node *parent);
        avl_node  *balanceFactorComputing(avl_node *parent);
        avl_node *insertNode(avl_node *p, int n);
        void print(avl_node *root, int);
        void inorderTraversal(avl_node *parent);
        avlTree()
        {
            root = NULL;
        }
};

#endif
 
int avlTree::height(avl_node *temp)			// Height of AVL Tree
{
    int h = 0;
    if (temp != NULL)
    {
        int l = height (temp->left);
        int r = height (temp->right);
        int maxHeight = max (l, r);
        h = maxHeight + 1;
    }
    return h;
}
 
int avlTree::difference(avl_node *temp)		// Height Difference 
{
    int l = height (temp->left);
    int r = height (temp->right);
    int balanceFactor= l - r;
    return balanceFactor;
}
 
avl_node *avlTree::rr(avl_node *parent)		// Right- Right Rotation
{
    avl_node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
 
avl_node *avlTree::ll(avl_node *parent)	  // Left- Left Rotation
{
    avl_node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

avl_node *avlTree::lr(avl_node *parent)  // Left - Right Rotation
{
    avl_node *temp;
    temp = parent->left;
    parent->left = rr (temp);
    return ll (parent);
}
 
avl_node *avlTree::rl(avl_node *parent)  // Right- Left Rotation
{
    avl_node *temp;
    temp = parent->right;
    parent->right = ll (temp);
    return rr(parent);
}
 
avl_node *avlTree::balanceFactorComputing(avl_node *temp) //Balancing AVL Tree
{
    int bf = difference (temp);
    if (bf > 1)
    {
        if (difference (temp->left) > 0)
            temp = ll (temp);
        else
            temp = lr (temp);
    }
    else if (bf < -1)
    {
        if (difference (temp->right) > 0)
            temp = rl (temp);
        else
            temp = rr (temp);
    }
    return temp;
}
 
avl_node *avlTree::insertNode(avl_node *root, int value)	// Insert Element into the tree
{
    if (root == NULL)
    {
        root = new avl_node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insertNode(root->left, value);
        root = balanceFactorComputing (root);
    }
    else if (value >= root->data)
    {
        root->right = insertNode(root->right, value);
        root = balanceFactorComputing (root);
    }
    return root;
}

void avlTree::print(avl_node *ptr, int level)		// print AVL Tree
{
    int i;
    if (ptr!=NULL)
    {
        print(ptr->right, level + 1);
        cout<<endl;
        if (ptr == root)
        cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
		{
            cout<<"        ";
		}
        cout<<ptr->data;
        print(ptr->left, level + 1);
    }
}

void avlTree::inorderTraversal(avl_node *tree)		// Inorder Traversal of AVL Tree
{
    if (tree == NULL)
	{
        return;
	}
    inorderTraversal (tree->left);
    cout<<tree->data<<"  ";
    inorderTraversal (tree->right);
}
 