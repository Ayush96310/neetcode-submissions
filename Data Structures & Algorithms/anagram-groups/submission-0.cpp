class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        int n = strs.size();
        for(int i=0; i<n;i++){
            string arr(26,'0');
            for(char ch:strs[i]){
                arr[ch-'a']++;
            }
            mpp[arr].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
