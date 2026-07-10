class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p = 1;
        int n = nums.size();
        int zero = 0;
        for(int i=0; i<n;i++){
            if(nums[i]) p*=nums[i];
            else zero++;
        }
        vector<int> ans(n,0);
        if(zero>1){
            return ans;
        }
        for(int i=0; i<n;i++){
            if(!nums[i]) ans[i]=p;
            else if(nums[i] && zero==0) ans[i]=p/nums[i];
            else ans[i]=0;
        }
        return ans;
    }
};
