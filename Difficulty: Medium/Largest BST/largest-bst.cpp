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
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

struct node1
{
    int isbst;  // flag to indicate if the subtree is a binary search tree
    int size;   // size of the subtree
    int mn;     // minimum value in the subtree
    int mx;     // maximum value in the subtree
};

// Recursive function to check if a binary tree is a binary search tree and return information about the subtree.
struct node1 bst(struct Node *root)
{
    struct node1 x; // create a node1 struct
    if(root == NULL) {  // if the root is NULL (empty subtree)
        // set the attributes of x to represent an empty subtree
        x.isbst = 1;
        x.size = 0;
        x.mn = 1000000;
        x.mx = 0;
        return x;  // return x
    }
    struct node1 left = bst(root->left);   // recursively call bst on the left subtree
    struct node1 right = bst(root->right); // recursively call bst on the right subtree
    if(left.isbst == 1 && right.isbst == 1 && root->data > left.mx && root->data < right.mn) { // if both subtrees are binary search trees and the root value is within the range of the left and right subtrees
        // set the attributes of x to represent a binary search tree
        x.isbst = 1;
        x.size = 1 + left.size + right.size;  // size is the sum of sizes of left and right subtrees plus 1 for the root node
        x.mx = max(root->data,right.mx);      // maximum value is the maximum of the root value and the maximum of the right subtree
        x.mn = min(root->data,left.mn);       // minimum value is the minimum of the root value and the minimum of the left subtree
    }
    else {
        // set the attributes of x to represent a non-binary search tree
        x.isbst = 0;
        x.size = max(left.size,right.size);    // size is the maximum of the sizes of the left and right subtrees
        x.mn = 1000000;                         // invalid minimum value
        x.mx = 0;                                // invalid maximum value
    }
    return x;  // return x
};

class Solution{
    public:
    int largestBst(Node *root)
    {
        return bst(root).size;   // call the bst function and return the size of the largest binary search tree
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
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends