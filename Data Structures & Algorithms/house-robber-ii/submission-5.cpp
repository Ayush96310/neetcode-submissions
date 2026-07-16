class Solution {
public:
    int helper(vector<int>& nums,int start,int end) {
        int prev1 = 0;
        int prev2 = 0;
        for(int i=start; i<end;i++){
            int current = max(prev1,prev2+nums[i]);
            prev2 = prev1;
            prev1 = current;
        }
        return max(prev1,prev2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        return max(helper(nums,0,n-1),helper(nums,1,n));
    }
};
