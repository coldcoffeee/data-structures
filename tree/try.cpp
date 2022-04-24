#include<bits/stdc++.h>
using namespace std;

#include"node.h"

int maxPathSum(Node *node,int &maxSum)
{
	if(node == NULL) return 0;
	int leftMax = maxPathSum(node->left,maxSum);
	int rightMax = maxPathSum(node->right,maxSum);
	maxSum = max(maxSum, node->data + leftMax + rightMax);
	return max(0,node->data + max(leftMax,rightMax));
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
    int maxSum = INT_MIN;
    maxPathSum(root,maxSum);
    cout<<(maxSum)<<'\n';

    /*



     :--------------1----------------:               
    2-----------:       :-----------3
                4       5---:
                            6---:
                                7



    */
   return 0;
}
