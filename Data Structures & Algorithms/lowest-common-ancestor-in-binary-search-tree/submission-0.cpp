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
    int solve(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans){
        if(root==nullptr) return -1;
        int l = solve(root->left,p,q,ans);
        int r = solve(root->right,p,q,ans);
        if(l==-1 && r==-1){
            if(root==p || root==q) return 1;
            else return -1;
        }      
        else if(l==1 && r==1){
            ans = root;
            return 1;
        }
        else{
            if(root==p || root==q){            
                ans = root;
            }
            return 1;
        }
        return 1;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q) return root;
        TreeNode* ans = nullptr;
        solve(root,p,q,ans);
        return ans;
    }
};
