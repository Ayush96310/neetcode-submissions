class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i=0; i<n;i++){
            mpp[nums[i]]++;
        }
        unordered_map<int,vector<int>> mpp2;
        for(auto it:mpp){
            mpp2[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i=n; i>=1;i--){
            if(mpp2.find(i)!=mpp2.end()){
                for(int j=0; j<mpp2[i].size();j++){
                    if(ans.size()<k) ans.push_back(mpp2[i][j]);
                    else break;
                }
            }
        }
        return ans;
    }
};
