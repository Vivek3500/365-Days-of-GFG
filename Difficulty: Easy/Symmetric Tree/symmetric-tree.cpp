/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool isSymmetric(Node* root) {
        // Code here
        if(root==NULL){
            return true;
        }
        return isValid(root->left, root->right);
    }
    bool isValid(Node* root1, Node* root2){
        if(root1==NULL && root2==NULL){
            return true;
        }    
        if(root1!=NULL && root2==NULL){
            return false;
        }
        if(root1==NULL && root2!=NULL){
            return false;
        }
        if(root1->data != root2->data){
            return false;
        }
        return isValid(root1->left, root2->right) && isValid(root1->right, root2->left);
    }
};