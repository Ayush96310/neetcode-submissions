class Solution {
public:
    void solve(vector<int>& candidates,vector<vector<int>>& ans, vector<int>& temp, int target, int ind, int sum){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        for(int i=ind; i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1]){
                continue;
            }
            if(sum+candidates[i]>target){
                break;
            }
            temp.push_back(candidates[i]);
            sum+=candidates[i];
            solve(candidates,ans,temp,target, i+1, sum);
            temp.pop_back();
            sum-=candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solve(candidates,ans,temp,target,0,0);
        return ans;
    }
};
