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
    bool solve(TreeNode* root, int mini, int maxi){
        if(root->val>=maxi || root->val<=mini){
            return false;
        }
        bool l = true;
        bool r = true;
        if(root->left!=nullptr){
            l = solve(root->left,mini,root->val);
        }
        if(root->right!=nullptr){
            r = solve(root->right,root->val,maxi);
        }
        return l&r;
    }
    bool isValidBST(TreeNode* root) {
        int mini = INT_MIN;
        int maxi = INT_MAX;
        return solve(root,mini,maxi);
    }
};
