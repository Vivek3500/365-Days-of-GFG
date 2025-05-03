//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  public:
    bool isPrime(int n){
        if(n<=2) return 2;
        for(int i=2; i*i<=n; i++){
            if((n%i)==0) return 0;
        }
        return 1;
    }
  
    Node *primeList(Node *head) {
        // code here
        Node* node=head;
        while(node){
            if(node->val<=2){
                node->val=2;
                node=node->next;
                continue;
            }
            if(!isPrime(node->val)){
                int data=node->val;
                int newdata=-1;
                int less=data-1;
                int more=data+1;
                bool l=1;
                while(true){
                    if(isPrime(less)){
                        break;
                    }else less-=1;
                    if(isPrime(more)){
                        l=0;
                        break;
                    }else more+=1;
                }
                if(l) node->val=less;
                else node->val=more;
            }
            node=node->next;
        }
        return head;
    }
};


//{ Driver Code Starts.

int main() {

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
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends