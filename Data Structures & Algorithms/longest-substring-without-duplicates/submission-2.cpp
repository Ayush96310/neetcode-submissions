class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mpp;
        int ans = 0;
        int left = 0;
        int right = 0;
        for(int i=0; i<n;i++){
            if(mpp.find(s[i])!=mpp.end()){
                int temp = mpp[s[i]];
                for(int j=left; j<=temp;j++){
                    mpp.erase(s[j]);
                }
                left = temp+1;
            }
            right++;
            ans = max(ans,right-left);
            mpp[s[i]]=i;
        }
        return ans;
    }
};
