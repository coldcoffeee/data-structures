#include<bits/stdc++.h>
#include"node.h"
using namespace std;

bool areIdentical(Node *p,Node *q)
{
    if(p == NULL || q == NULL)
        return p == q;
    
    return p->data == q->data && areIdentical(p->left,q->left) && areIdentical(p->right, q->right);
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(-2);
    root->right = new Node(3);

    root->left->right = new Node(4);

    root->right->left = new Node(5);
    root->right->left->right = new Node(6);
    root->right->left->right->right = new Node(-7);

    Node *root2 = new Node(1);

    root2->left = new Node(-2);
    root2->right = new Node(3);

    root2->left->right = new Node(4);

    root2->right->left = new Node(5);
    root2->right->left->right = new Node(6);
    root2->right->left->right->right = new Node(-7);

    areIdentical(root,root2) ? cout<< "Identical\n" : cout<< "Not Identical\n";
    
    /*



     :--------------1----------------:               
    -2-----------:       :-----------3
                4       5---:
                            6---:
                                -7



    */
    return 0;
}