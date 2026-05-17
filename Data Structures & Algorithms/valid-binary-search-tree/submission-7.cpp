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
    bool isValidBST(TreeNode* root) {
        TreeNode*tmp1=root;
        TreeNode*tmp2=root;
        while(tmp1->left){ 
            tmp1=tmp1->left;
        }
        while(tmp2->right){
            tmp2=tmp2->right;
        }
        bool ans=ivb(root, tmp1->val-1, tmp2->val+1);
        return ans;
    }
    bool ivb(TreeNode* root, int lower, int upper){
        if(!root)return true;
        if(!(root->val>lower&&root->val<upper)){
            // cout<<root->val<<endl;
            // cout<<lower<<endl;
            // cout<<upper<<endl;
            return false;
        }
        // if(root->val==lower&&root->val!=absl)return false;
        // if((root->val==upper)&&root->val!=absu)return false;
        bool left = ivb(root->left,lower,root->val);
        bool right = ivb(root->right,root->val,upper);
        return left&&right;       
}
};