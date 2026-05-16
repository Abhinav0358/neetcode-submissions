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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        if(root)que.push(root);
        vector<int> ans;
        while(!que.empty()){
            int size=que.size();
            for(int i=0; i<size; i++){
                TreeNode*tp=que.front();
                que.pop();
                if(tp->left)que.push(tp->left);
                if(tp->right)que.push(tp->right);
                if(i==size-1)ans.push_back(tp->val);
            }
        }
        return ans;
    }
};
