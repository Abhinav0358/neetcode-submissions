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
    int goodNodes(TreeNode* root) {
         int count=0;
         int current_max=root->val;
         goodn(root, current_max, count);
         return count;
    }
    void goodn(TreeNode * root, int current_max, int &count){
        if(!root)return;
        if(root->val>=current_max){
            current_max=root->val;
            count++;
        }
        goodn(root->left, current_max, count);
        goodn(root->right, current_max, count);
    }
};
