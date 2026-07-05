class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n!=m) return false;
        else{
            unordered_map<char,pair<int,int>> mpp;
            for(int i=0; i<n;i++){
                mpp[s[i]].first++;
                mpp[t[i]].second++;
            }
            for(auto it:mpp){
                if(it.second.first!=it.second.second) return false;
            }
        }
        return true;
    }
};
