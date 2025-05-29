/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int  height(Node *root){
        if(root==NULL){
            return 0;
        }
          return 1+ max(height(root->left),height(root->right));
  }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
      if(root==NULL){
          return 0;
      }
      
        if(height(root->left)>height(root->right)){
                return   root->data+sumOfLongRootToLeafPath(root->left);
        }
        else if(height(root->left)<height(root->right)){
             return root->data+sumOfLongRootToLeafPath(root->right);
        }
        else{
             return root->data+max(sumOfLongRootToLeafPath(root->left),sumOfLongRootToLeafPath(root->right)); 
        }
        
    }
};