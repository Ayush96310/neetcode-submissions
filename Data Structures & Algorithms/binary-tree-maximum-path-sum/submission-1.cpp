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
    int solve(TreeNode* root, int& ans){
        int l = 0;
        int r = 0;
        if(root->left!=nullptr){
            l = solve(root->left,ans);
        }
        if(root->right!=nullptr){
            r = solve(root->right,ans);
        }
        ans = max(ans,max(l,0)+max(r,0)+root->val);
        return max({l,r,0})+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root,ans);
        return ans;
    }
};
