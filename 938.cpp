using namespace std;
#include <bits/stdc++.h>

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    int sum=0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        inorder(root,low,high);
        return sum;
        
    }
    void inorder(TreeNode* node,int low,int high){
          if(node ==nullptr){
            return;
        }
        inorder(node->left,low,high);
        if(node->val>=low&&node->val<=high) sum+=node->val;
        inorder(node->right,low,high);


    }

};