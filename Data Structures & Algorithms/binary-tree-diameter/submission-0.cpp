/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
       int diameter=0;
       maxDepth(root, diameter);
       return diameter; 
    }
    int maxDepth(TreeNode* root,int &diameter) {
        if(!root)return 0;
        int left = maxDepth(root->left,diameter);
        int right = maxDepth(root->right,diameter);
        if(left+right>diameter)diameter=left+right;
        return max(left,right)+1;
    }
};
