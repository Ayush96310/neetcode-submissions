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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int,int> &mpp){
        if(preStart>preEnd || inStart>inEnd){
            return nullptr;
        }
        int rootValue = preorder[preStart];
        TreeNode* root = new TreeNode(rootValue);
        int inRoot = mpp[rootValue];
        int leftsize = inRoot - inStart;
        root->left = build(preorder,inorder,preStart+1,preStart+leftsize,inStart, inRoot-1,mpp);
        root->right = build(preorder,inorder,preStart+leftsize+1,preEnd,inRoot+1, inEnd,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mpp;
        for(int i=0; i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return build(preorder, inorder, 0, preorder.size()-1,0,inorder.size()-1,mpp);
    }
};
