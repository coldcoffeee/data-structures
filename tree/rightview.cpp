#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends


/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    vector<int> rightView(Node *root)
    {
        vector<int> result;
        //map(y,map(x,valAtX));
        map<int,pair<int,int>> imap;
        //queue(pair(Node, pair(x,y)));
        queue<pair<Node *,pair<int,int>>> Q;
        pair<Node *,pair<int,int>> curr;
        curr = make_pair(root,make_pair(0,1));
        Q.push(curr);
        while(!Q.empty())
        {
            curr = Q.front();Q.pop();
            if(imap[curr.second.second] != pair<int,int>())
            {
                if(imap[curr.second.second].first < curr.second.first)
                {
                    imap[curr.second.second].first = curr.second.first;
                    imap[curr.second.second].second = curr.first->data;
                }
            }
            else
            {
                imap[curr.second.second].first = curr.second.first;
                imap[curr.second.second].second = curr.first->data;
            }
            if(curr.first->left) Q.push(make_pair(curr.first->left,make_pair(curr.second.first-1,curr.second.second+1)));
            if(curr.first->right) Q.push(make_pair(curr.first->right,make_pair(curr.second.first+1,curr.second.second+1)));
        }
        for(pair<int,pair<int,int>> somePair: imap)
        {
            result.push_back(somePair.second.second);
        }
        return result;
    }

};



// { Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.rightView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
/*
//1 2 3 N N 4 6 N 5 N N 7 N
*/