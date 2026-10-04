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
    int solve(TreeNode* root, bool &ans){
        if(root==nullptr){
            return 0;    
        }
        int leftDepth = solve(root->left,ans);
        int rightDepth = solve(root->right,ans);
        if(abs(leftDepth-rightDepth)>1){
            ans = ans & false;
        }
        else{
            ans = ans & true;
        }
        return max(leftDepth,rightDepth)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        solve(root,ans);
        return ans;
    }
};
