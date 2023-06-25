//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    
    int solve(Node*root,int a,int b,int &dist)
    {
        if(root==NULL)
        {
            return -1;
        }
        if(dist!=-1)
        {
            return -1;
        }
        int lh=solve(root->left,a,b,dist);
        int rh=solve(root->right,a,b,dist);
        if(lh!=-1 && rh!=-1)
        {
            dist=lh+rh;
            return -1;
        }
        if((root->data==a && rh!=-1) || (root->data==b && rh!=-1))
        {
            dist=(rh!=-1?rh:lh);
            return -1;
        }
        if((root->data==a && lh!=-1) || (root->data==b && lh!=-1))
        {
            dist=(rh!=-1?rh:lh);
            return -1;
        }
        if(root->data==a|| root->data==b)
        {
            return 1;
        }
        if(lh==-1 && rh==-1)
        {
            return -1;
        }
        return lh!=-1?lh+1:rh+1;
    }
    
    int findDist(Node* root, int a, int b) {
        int ans=-1;
        if(a==b)
        {
            return 0;
        }
        solve(root,a,b,ans);
        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends