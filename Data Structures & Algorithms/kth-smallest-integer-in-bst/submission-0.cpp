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
    int kthSmallest(TreeNode* root, int k) {
        int count=1;
        int ans=0;
        traversal(root, k, count, ans);
        return ans;
    }
    void traversal(TreeNode * root, int k, int &count, int & ans){
        if(!root)return;
        traversal(root->left, k , count, ans);
        if(k==count){
            ans=root->val;
        }count++;
        traversal(root->right, k , count, ans);

    }
};
