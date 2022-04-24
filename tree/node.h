struct Node{
    int data;
    Node *left,*right;
    Node(int num)
    {
        data = num;
        left = right = nullptr;
    }
};
