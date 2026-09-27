class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n;i++){
            target = nums[i]*-1;
            int left = i+1;
            int right = n-1;
            while(left<right){
                if(nums[left]+nums[right]==target){
                    st.insert({nums[left],nums[right],nums[i]});
                    left++;
                    right--;
                }
                else if(nums[left]+nums[right]>target){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        for(auto t:st){
            ans.push_back(t);
        }
        return ans;
    }
};
