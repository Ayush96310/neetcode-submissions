class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = t.size();
        int n2 = s.size();
        if(n1>n2) return "";
        unordered_map<char,int> mpp;
        for(char ch:t){
           mpp[ch]++; 
        }
        int cnt =0;
        int left = -1;
        int right = -1;
        int ansStart = -1;
        int mini = INT_MAX;
        while(right<n2-1){
            if(cnt!=n1){
                right++;
                if(mpp[s[right]]>0) cnt++;
                mpp[s[right]]--;
            }
            else{
                if(mini>right-left){
                    mini = right-left;
                    ansStart = left+1;
                }
                mpp[s[left+1]]++;
                if(mpp[s[left+1]]>0){
                    cnt--;
                }
                left++;
            }
        }
        while(cnt==n1){
            if(mini>right-left){
                mini = right-left;
                ansStart = left+1;
            }
            mpp[s[left+1]]++;
            if(mpp[s[left+1]]>0){
                cnt--;
            }
            left++;
        }
        return ansStart == -1 ? "" : s.substr(ansStart, mini);
    }
};
