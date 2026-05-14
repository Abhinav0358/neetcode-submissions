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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        singlefunc(root, output);
        return output;

    }
    void singlefunc(TreeNode* root, vector<int>&output){
        if(!root)return;
        if(root->left)singlefunc(root->left,output);
        output.push_back(root->val);
        if(root->right)singlefunc(root->right,output);   
    }
};