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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // fucking bitch ass titty sucking O(n^2) worst case solution 

        // vector<vector<int>> empty(0);
        // if(!root) return empty;
        // vector<vector<int>> vec1 = levelOrder(root->left);
        // vector<vector<int>> vec2 = levelOrder(root->right);
        // int mx = max(vec1.size(),vec2.size());
        // vec1.resize(mx);
        // vec2.resize(mx);
        // vector<vector<int>> output(mx+1);
        // output[0].push_back(root->val);
        // for(int i=0; i<mx; i++){
        //      for(int j=0; j<vec2[i].size(); j++){
        //         vec1[i].push_back(vec2[i][j]);
        //     }
        //     output[i+1]=vec1[i];
        // }
        // return output;



        // The queue solution
        queue<TreeNode*> que;
        if(root)que.push(root);
        // TODO fix size
        vector<vector<int>> ans(0);
        int count=0;
        while(!que.empty()){
            int size=que.size();
            vector<int> thisvec(0);
            for(int i=0; i<size; i++){
                TreeNode * tp = que.front();
                que.pop();
                if(tp->left)que.push(tp->left);
                if(tp->right)que.push(tp->right);
                thisvec.push_back(tp->val);
            }
            ans.push_back(thisvec);
        }
        return ans;

    }


};
