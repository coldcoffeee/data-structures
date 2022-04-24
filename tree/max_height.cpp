#include<bits/stdc++.h>
using namespace std;

#include"node.h"

int max_height(Node *root)
{
    if(root)
    {
        return 1+max(max_height(root->left),max_height(root->right));
    }
    else return 0;
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(4);

    root->right->left = new Node(5);
    root->right->left->right = new Node(6);
    root->right->left->right->right = new Node(7);

    cout<<max_height(root)<<'\n';

    /*



     :--------------1----------------:               
    2-----------:       :-----------3
                4       5---:
                            6---:
                                7



    */
   return 0;
}
