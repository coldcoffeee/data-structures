#include "node.h"
#include <vector>
struct Tree
{
    Node *root;
    void constructFromInorder(std::vector<int> inorder)
    {
        int n = inorder.size();
        if(n == 0) return;
    }
};