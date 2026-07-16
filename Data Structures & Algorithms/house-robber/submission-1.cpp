class Solution {
public:
    int rob(vector<int>& nums) {
        int  n =  nums.size();
        int prev1 = 0;
        int prev2 = 0;
        for(int i=0; i<n;i++){
            int current = max(prev1,prev2+nums[i]);
            prev2 = prev1;
            prev1 = current;
        }
        return max(prev1,prev2);
    }
};
