//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node* reverseKGroup(Node* head, int k) {
    // Initialize pointers for the reversal process
    Node* p = NULL;  // Previous node
    Node* q;         // Next node
    Node* c = head;  // Current node
    
    int m = k; // Counter for reversing k nodes
    
    // Reverse the first k nodes
    while (m-- && c) {
        q = c->next;    // Store the next node
        c->next = p;    // Reverse the current node's pointer
        p = c;          // Move the previous pointer to the current node
        c = q;          // Move the current pointer to the next node
    }
    
    // After reversing the first k nodes,
    // recursively reverse the remaining list
    if (head) {
        head->next = reverseKGroup(c, k);  // Connect the end of the reversed group to the next reversed group
    }
    
    // Return the new head of the reversed group
    return p;
}
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends