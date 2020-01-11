/*Write C++ code for AVL-TREE class, in which Tree node will store the Height of node
along with data.
 Empty Tree Height: -1
 Leaf Node Height: 0
1. Implement an AVL-insert function, which is modification of the "insert" function of
BST class written in the earlier assignment so that the tree remains always balanced
by using the AVL rotations. Time complexity must be O (log N).
2. Implement an AVL-print function by changing the ascending order print function of
BST written earlier. AVL-print should print the height of each node along with data.*/

#include <iostream>
#include "AVL_TREE.h"

using namespace std;

int main()
{
    int perform, value;
    avlTree avl;
    while (1)
    {
        cout<<"\n********************AVL Tree Implementation*********************"<<endl;
        cout<<"1)Insert Element into the tree"<<endl;
        cout<<"2)Display Balanced AVL Tree"<<endl;
        cout<<"3)Inorder traversal(Ascending Order)"<<endl;
        cout<<"4)Exit"<<endl;
        cout<<"Enter operation you want to perform: ";
        cin>>perform;
        switch(perform)
        {
        case 1:
            cout<<"Enter value to be inserted: ";
            cin>>value;
            root = avl.insertNode(root, value);
            break;
        case 2:
            if (root == NULL)
            {
                cout<<"Tree is Empty"<<endl;
                continue;
            }
            cout<<"Balanced AVL Tree:"<<endl;
            avl.print(root, 1);
            break;
        case 3:
            cout<<"Inorder Traversal:"<<endl;
            avl.inorderTraversal(root);
            cout<<endl;
            break;
        case 4:
            exit(1);    
            break;
        default:
            cout<<"Wrong War!"<<endl;
        }
    }
	system("PAUSE");
    return 0;
}
 
