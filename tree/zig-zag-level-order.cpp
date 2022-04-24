#include<bits/stdc++.h>
#include"node.h"
using namespace std;

int main()
{
    Node *root = new Node(1);

    root->left = new Node(-2);
    root->right = new Node(3);

    root->left->right = new Node(4);

    root->right->left = new Node(5);
    root->right->left->right = new Node(6);
    root->right->left->right->right = new Node(-7);
   
    vector<vector<int>> result;
    Node *temp;
    queue<Node *> Q;
    bool l2r = true;
    Q.push(root);
    while(not Q.empty()) {
        int n = Q.size();
        vector<int> level(n);
        for(int i=0;i<n;i++) {
            temp = Q.front();
            Q.pop();
            if(l2r) {
                level[i] = temp->data;
            }else {
                level[n-i-1] = temp->data;
            }
            if(temp->left) Q.push(temp->left);
            if(temp->right) Q.push(temp->right);
        }
        l2r = not l2r;
        result.push_back(level);
    }
    
    for(auto vec: result) {
        for(int i: vec) {
            cout<< i << ' ';
        }
        cout<< '\n';
    }

    /*



     :--------------1----------------:               
    -2-----------:       :-----------3
                4       5---:
                            6---:
                                -7



    */

    return 0;
}