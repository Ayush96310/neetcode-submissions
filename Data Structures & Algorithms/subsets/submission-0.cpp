class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& subset, int ind){
        if(ind>=nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[ind]);
        solve(nums,ans,subset,ind+1);
        subset.pop_back();
        solve(nums,ans,subset,ind+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        solve(nums,ans,subset,0);
        return ans;
    }
};
