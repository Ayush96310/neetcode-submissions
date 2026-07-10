class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set st(nums.begin(),nums.end());
        int ans = 0;
        for(auto num:nums){
            if(st.count(num)){
                int cnt = 1;
                st.erase(num);
                
                int forward = num+1;
                while(st.count(forward)){
                    cnt++;
                    forward++;
                }
                int backward = num-1;
                while(st.count(backward)){
                    cnt++;
                    backward--;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};
