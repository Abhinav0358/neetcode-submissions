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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // if(root->val==key){
        //     TreeNode* left=root->left;
        //     TreeNode * right = root->right;
        //     TreeNode *tmp = right->left;
        //     TreeNode * del = root;
        //     root=right;
        //     delete del;
        //     root->left=left;
        //     TreeNode* temp = root;
        //     while(temp->right){
        //         temp=temp->right;
        //     }
        //     if(tmp||temp){
        //         if(temp-> val>tmp->val)temp->left=tmp;
        //     }
        // }else{
        //     if(key<root->val)root->left=dele   teNode(root->left,key);
        //     if(key>root->val)root->right=deleteNode(root->right,key);
        // }
        // return root;
        // if(!root) return nullptr;
        // if(root->val==key){
        //         TreeNode* tmp = root->right;
        //         root->left=(root->left)->left;
        //         if(!root->left){
        //             root->left=tmp;
        //             return root;
        //         }
        //         TreeNode*iter=root->left;
        //         while(iter->right){
        //             iter=iter->right;
        //         }
        //         iter->right=tmp;
        //         return root;
        // }
        // if(root->right&&(root->right)->val==key){
        //         TreeNode* tmp = (root->right)->left;
        //         root->right=(root->right)->right;
        //         if(!root->right){
        //             root->right=tmp;
        //             return root;
        //         }
        //         TreeNode*iter=root->right;
        //         while(iter->left){
        //             iter=iter->left;
        //         }
        //         iter->left=tmp;
        //         return root;
        // }

        // if(key<root->val)root->left=deleteNode(root->left,key);
        // if(key>root->val)root->right=deleteNode(root->right,key);

        // return root;

        if (!root) return nullptr;

        // Step 1: Search for the node
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } 
        // Step 2: Found the node to delete!
        else {
            // Case 1: No left child (covers leaf node and right-child-only node)
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // Case 2: No right child
            else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            
            // Case 3: Node has two children
            // Find the min node in the right subtree (In-order successor)
            TreeNode* minNode = root->right;
            while (minNode->left) {
                minNode = minNode->left;
            }
            
            // Replace current value with successor's value
            root->val = minNode->val;
            
            // Delete the successor from the right subtree
            root->right = deleteNode(root->right, minNode->val);
        }
        return root;

        
    }
};