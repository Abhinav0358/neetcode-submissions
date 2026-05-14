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
    bool isBalanced(TreeNode* root) {
        bool isbalanc=true;
        height(root,isbalanc);
        return isbalanc;
    }
    int height(TreeNode *root, bool &isbalanc){
        if(!root)return 0;
        int left = height(root->left, isbalanc);
        int right = height(root->right, isbalanc);
        cout<<left<<" "<<right<<endl;
        if(abs(right-left)>1){
            isbalanc=false;
            return -1;
        }
        return max(left+1,right+1);
    }
};
