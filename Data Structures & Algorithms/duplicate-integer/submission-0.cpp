class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,bool> mpp;
        int n = nums.size();
        for(int i=0; i<n;i++){
            if(mpp.find(nums[i])!=mpp.end()) return true;
            mpp[nums[i]]=true;
        }
        return false;
    }
};