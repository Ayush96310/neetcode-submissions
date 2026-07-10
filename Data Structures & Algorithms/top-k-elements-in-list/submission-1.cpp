class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i=0; i<n;i++){
            mpp[nums[i]]++;
        }
        vector<vector<int>> arr(n+1);
        for(auto it:mpp){
            arr[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i=n; i>=1;i--){
            for(int j=0; j<arr[i].size();j++){
                if(ans.size()<k) ans.push_back(arr[i][j]);
                else break;
            }
        }
        return ans;
    }
};
