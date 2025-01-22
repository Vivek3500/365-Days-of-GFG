//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    Node* reverseNode(Node* node, Node** head){
        if(node == NULL){
            return NULL;
        }
        
        Node* nextNode = reverseNode(node->next, head);
        
        if(nextNode){
            nextNode->next = node;
            node->next = NULL;
        }else{
            (*head) = node;
        }
        return node;
    }
    public:
    Node* addTwoLists(Node* first, Node* second){
        int total = 0, carry = 0;
        Node *res = new Node(-1), *node = NULL, *prevNode = res;
        reverseNode(first, &first);
        reverseNode(second, &second);
        
        while(first || second || carry){
            if(first && second){
                total = first->data + second->data + carry;
                carry = total / 10;
                
                first = first->next;
                second = second->next;
            }else if(first){
                total = first->data + carry;
                carry = total / 10;
                first = first->next;
            }else if(second){
                total = second->data + carry;
                carry = total / 10;
                second = second->next;
            }else{
                total = carry;
                carry = 0;
            }
            node = new Node(total % 10);
            prevNode->next = node;
            prevNode = node;
            node = NULL;
        }
        
        reverseNode(res->next, &(res->next));
        res = res->next;
        while (res != NULL && res->data == 0) {
            res = res->next;
        }
        if (res == NULL) return new Node(0); // This case handles when both numbers are zero
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends