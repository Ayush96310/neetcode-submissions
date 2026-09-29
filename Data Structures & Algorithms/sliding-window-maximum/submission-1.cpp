class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<k;i++){
            pq.push({nums[i],i});
        }
        int maxVal = pq.top().first;
        int maxInd = pq.top().second;
        ans.push_back(maxVal);
        for(int i=k;i<n;i++){
            pq.push({nums[i],i});
            if(i-k!=maxInd){
                if(maxVal<nums[i]){
                    maxVal = nums[i];
                    maxInd = i;
                }
            }
            else{
                while(pq.top().second<=i-k){
                    pq.pop();
                }                
                maxVal = pq.top().first;
                maxInd = pq.top().second;
            }
            ans.push_back(maxVal);
        }
        return ans;
    }
};
