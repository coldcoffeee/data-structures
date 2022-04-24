#include<bits/stdc++.h>
using namespace std;

#include"node.h"


bool isLeaf(Node* &root)
{
    if(!root->left and !root->right) return true;
    else return false;
}
void addLeftBoundary(Node *root,vector<int> &res)
{
    Node *cur = root->left;
    while(cur)
    {
        if(!isLeaf(cur)) res.push_back(cur->data);
        if(cur->left) cur = cur->left;
        else cur = cur->right;
    }
}
void addLeaves(Node *root,vector<int> &res)
{
    if(isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if(root->left) addLeaves(root->left,res);
    if(root->right) addLeaves(root->right,res);
}
void addRightBoundary(Node *root,vector<int> &res)
{
    Node *cur = root->right;
    vector<int> tmp;
    while(cur)
    {
        if(!isLeaf(cur)) tmp.push_back(cur->data);
        if(cur->right) cur = cur->right;
        else cur = cur->left;
    }
    for(int i=tmp.size()-1;i>=0;--i)
    {
        res.push_back(tmp[i]);
    }
}
vector <int> boundary(Node *root)
{
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root->data);
    addLeftBoundary(root,res);
    addLeaves(root,res);
    addRightBoundary(root,res);
    return res;
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

    vector<int> ans = boundary(root);

    for(int i:ans)
    cout<<i<<' ';
    cout<<'\n';

    return 0;
}

    /*



     :--------------1----------------:               
    2-----------:       :-----------3
                4       5---:
                            6---:
                                7



    */

// Here boundary traversal means anticlock or clockwise traversal.
// if we take anticlockwiese traversal we get, 1 2 4 7 6 5 3 -- an anticlockwise circle

/*
            1
          /  \
        2     7
      /  \   / \
    3     x y   8
     \        /
      4      9
    /  \   /  \
   5    6 10   11

   Boundary traversal would be: 1 2 3 4 5 6 10 11 9 8 7
   x & y are internal nodes, so exclude them

   process:
        1. left boundary excluding leaf
        2. leaves
        3. right boundary in reverse excluding leaves

        1. : for left boundary, traverse through root's left subtree and follow left child of each node,
             if in case left child doesn't exist only then visit right child of that node.
        
        2. : for leaves, perform inorder traversal, it'll give 5 6 10 11 in above example

        3. : for right boundary, traverse through root's right subtree, only follow right children
             in case right child doesn't exist, only then follow left child until leaves are reached.
             As you follow the right subtree, push the elements into a stack and in the end pop them out
             to get the traversal in reverse order.

*/