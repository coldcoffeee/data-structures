#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int num)
    {
        data = num;
        left = right = nullptr;
    }
};

struct Tree{
    Node *root;
    static void preorder(Node *node)
    {
        if(node == nullptr)
            return;
        cout<< node->data <<' ';
        preorder(node->left);
        preorder(node->right);
    }
    static void inorder(Node *node)
    {
        if(node == nullptr)
            return;
        
        inorder(node->left);
        cout<< node->data << ' ';
        inorder(node->right);
    }
    static void postorder(Node *node)
    {
        if(node == nullptr)
            return;
        postorder(node->left);
        postorder(node->right);
        cout<< node->data << ' ';
    }

    static void levelorder(Node *root)
    {
        queue<Node *> Q;
        Q.push(root);
        Node *temp;
        while(!Q.empty())
        {
            temp = Q.front();
            Q.pop();
            cout<< temp->data << ' ';
            if(temp->left != nullptr)
                Q.push(temp->left);
            if(temp->right != nullptr)
                Q.push(temp->right);
        }
    }

    static void preorder_using_stack(Node *root)
    {
        stack<Node *> stk;
        Node *temp;
        stk.push(root);
        while(!stk.empty())
        {
            temp = stk.top();
            stk.pop();
            cout<< temp->data <<' ';
            if(temp->right != nullptr)
            stk.push(temp->right);
            if(temp->left != nullptr)
            stk.push(temp->left);
        }

    }
    static void postorder_using_stack(Node *root)
    {
        stack<Node *> stk;
        stk.push(root);
        Node *temp;
        while(!stk.empty())
        {
            temp = stk.top();

            if(temp == nullptr)
            {
                stk.pop();
                temp = stk.top();
                cout<< temp->data << ' ';
                continue;
            }

            stk.push(temp->right);
            stk.push(temp->left);
        }
    }

    static void inorder_using_stack(Node *root)
    {
        stack<Node *> stk;
        Node *temp = root;
        while (true)
        {
            if(temp)
            {
                stk.push(temp);
                temp = temp->left;
            }
            else
            {
                if(stk.empty()) break;
                temp = stk.top();
                stk.pop();
                cout<< temp->data <<' ';
                temp = temp->right;
            }
        }
        cout<<endl;
        
    }
    // static void inorder_using_stack(Node *root)
    // {
    //     stack<Node *> stk;
    //     Node *temp;
    //     stk.push(root);
    //     while(!stk.empty())
    //     {
    //         temp = stk.top();
    //         if(temp == nullptr)
    //         {
    //             stk.pop();
    //             temp = stk.top();
    //             cout<< temp->data << ' ';
    //             stk.pop();
    //             stk.push(temp->right);
    //         }
    //         else
    //             stk.push(temp->left);
    //     } 
    // }
};

int main()
{
    Tree tree;
    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->left->right = new Node(5);
    tree.root->left->right->left = new Node(6);
    tree.root->left->left = new Node(4);

    tree.root->right = new Node(3);
    tree.root->right->right = new Node(8);
    tree.root->right->right->left = new Node(9);
    tree.root->right->right->right = new Node(10);
    tree.root->right->left = new Node(7);

    Tree::inorder(tree.root);
    cout<<endl;
    Tree::inorder_using_stack(tree.root);

}