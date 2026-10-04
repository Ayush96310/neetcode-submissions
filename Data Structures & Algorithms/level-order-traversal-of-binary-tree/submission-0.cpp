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
        if(root==nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int> level;
            for(int i=0; i<s;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp!=nullptr){
                    level.push_back(temp->val);
                    if(temp->left!=nullptr) q.push(temp->left);
                    if(temp->right!=nullptr) q.push(temp->right);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};
