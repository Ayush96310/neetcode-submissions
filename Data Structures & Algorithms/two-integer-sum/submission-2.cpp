class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>> mpp;
        int n = nums.size();
        for(int i=0; i<n;i++){
            mpp[nums[i]].push_back(i);
        }
        for(int i=0; i<n;i++){
            if(mpp.find(target-nums[i])!=mpp.end()){
                if(target-nums[i]!=nums[i]) return {i,mpp[target-nums[i]][0]};
                else{
                    if(mpp[nums[i]].size()>1) return {mpp[nums[i]][0],mpp[nums[i]][1]};
                }
            }
        }
        return {};
    }
};
