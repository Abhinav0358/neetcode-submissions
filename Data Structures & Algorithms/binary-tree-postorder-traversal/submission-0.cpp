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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> output;
        singlefunction(root, output);
        return output;
    }
    void singlefunction(TreeNode* root, vector<int>&output){
        if(!root)return;
        singlefunction(root->left,output);
        singlefunction(root->right,output);
        output.push_back(root->val);
    }
};