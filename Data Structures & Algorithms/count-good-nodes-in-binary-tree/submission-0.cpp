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
    void solve(TreeNode* root, int &ans, int maxi){
        if(root->val>=maxi){
            maxi = root->val;
            ans++;
        }
        if(root->left!=nullptr) solve(root->left,ans,maxi);
        if(root->right!=nullptr) solve(root->right,ans,maxi);
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        int maxi = INT_MIN;
        solve(root,ans,maxi);
        return ans;
    }
};
