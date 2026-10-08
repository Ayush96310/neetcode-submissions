class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, vector<bool> &vis){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        } 
        for(int i=0; i<vis.size();i++){
            if(!vis[i]){
                temp.push_back(nums[i]);
                vis[i]=true;
                solve(nums,ans,temp,vis);
                temp.pop_back();
                vis[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> vis(nums.size(),false);
        solve(nums,ans,temp,vis);
        return ans;
    }
};
