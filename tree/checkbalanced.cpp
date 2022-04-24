#include<bits/stdc++.h>
using namespace std;

#include"node.h"

int height(Node *node)
{
        if(node == NULL)
            return 0;
            
        int lh = height(node->left);
        int rh = height(node->right);
        if(lh == -1 or rh == -1) return -1;
        if(abs(lh-rh)>1) return -1;
        
        return max(lh,rh)+1;
}
bool isBalanced(Node *root)
{
        return height(root) != -1;
}
int main()
{
    Node *root = new Node(1);
    
    root->left = new Node(2);
    root->right = new Node(3);

    root->right->right = new Node(8);

    root->left->right = new Node(4);
    root->left->left = new Node(5);
    root->left->left->left = new Node(6);
    root->left->left->right = new Node(7);

    cout<< isBalanced(root) <<endl;
}

/*
                    1
                2        3
            5       4        8
        6       7
*/