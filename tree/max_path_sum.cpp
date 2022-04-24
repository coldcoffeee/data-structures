#include<bits/stdc++.h>
#include"node.h"
using namespace std;

int maxPathSum(Node *node,int &maxSum)
{
    if(node == NULL) return 0;
    int lmax = maxPathSum(node->left, maxSum) < 0 ? 0 : maxPathSum(node->left, maxSum) ;
    int rmax = maxPathSum(node->right, maxSum) >= 0 ? maxPathSum(node->right, maxSum) : 0;
    maxSum = max(maxSum,node->data + lmax + rmax);
    // maxSum = max(maxSum,node->data + lmax + rmax);
    return node->data + max(lmax,rmax);
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

    int maxSum=INT_MIN;
    maxPathSum(root,maxSum);
    cout<< maxSum << '\n';

    /*



     :--------------1----------------:               
    -2-----------:       :-----------3
                4       5---:
                            6---:
                                -7



    */
    return 0;
}