#include<iostream>
#include<vector>
using namespace std;

#include"node.h"

int height(Node *node)
{
    if(node == NULL)
        return 0;

    int l_height = height(node->left);
    int r_height = height(node->right);
    return 1+max(l_height,r_height);
}

int diameter(Node *node)
{
    static int max_d = 0;
    if(node == NULL)
        return 0;
    int current_diameter = height(node->left) + height(node->right);
    max_d = max(max_d,current_diameter);
    diameter(node->left);
    diameter(node->right);
    return max_d;
}

int diameter_optimised(Node *node,int &max_diameter)
{
    if(node == NULL)
        return 0;
    int lh = diameter_optimised(node->left,max_diameter);
    int rh = diameter_optimised(node->right,max_diameter);

    max_diameter = max(max_diameter,lh+rh);//omit this line and you get a function to find the tree's height

    //at each recursive call, compare and store heights of left and right subtree into max_diameter variable
    //max_diameter has to be passed externally to retain data over different recursive calls

    return 1+max(lh,rh);
}

int main()
{
    Node *root = new Node(1);
    
    root->left = new Node(2);
    root->right = new Node(3);


    root->left->right = new Node(4);

    root->left->right->left = new Node(8);
    root->left->right->left->left = new Node(9);
    root->left->right->left->left->right = new Node(10);

    root->left->left = new Node(5);
    root->left->left->left = new Node(6);
    root->left->left->right = new Node(7);

    cout<< diameter(root) <<endl;
    int max_diameter = 1;
    cout<< diameter_optimised(root,max_diameter) <<endl;

}

/*
                                    1
                        2                   3
            5                   4             
        6       7           8
                        9
                           10
*/
