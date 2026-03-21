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
    int i;
    int kthSmallest(TreeNode* root, int k) {
        i=1;
        return printInOrder(root,k);
        
    }
        int printInOrder(TreeNode* node,int k){
        if(node ==nullptr){
            return -1;
        }

        int left=printInOrder(node->left,k);
        if(left!=-1){
            return left;
        }

        if(k==i){
            i++;
            return node->val;
        }
        else{
            i++;
        }
        return printInOrder(node->right,k);


    }
};