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
    int rob(TreeNode* root) {
        vector<int> a = robpair(root);
        return max(a[0],a[1]);
    }
    vector<int> robpair(TreeNode* root){
        if(!root) return {0,0};
        vector<int> left= robpair(root->left);
        vector<int> right= robpair(root->right);

        int ifskip = max(left[0],left[1]) + max(right[0], right[1]);
        int ifrob = left[1] + right[1] + root->val;

        return {ifrob, ifskip};

    }
};