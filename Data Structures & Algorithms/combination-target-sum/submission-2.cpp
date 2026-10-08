class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, int target, int ind, int sum){
        if(sum>target){
            return;
        }
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(ind>=nums.size()){
            return;
        }
        solve(nums,ans,temp,target,ind+1,sum);
        temp.push_back(nums[ind]);
        sum+=nums[ind];
        solve(nums,ans,temp,target,ind,sum);
        temp.pop_back();
        sum-=nums[ind];
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,ans,temp,target,0,0);
        return ans;
    }
};
