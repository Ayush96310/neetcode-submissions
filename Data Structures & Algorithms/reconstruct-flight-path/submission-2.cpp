class Solution {
public:
    void dfs(unordered_map<string,vector<string>>& mpp, vector<string>& ans, string s){
        while(mpp[s].size()){
            string next = mpp[s][mpp[s].size()-1];
            mpp[s].pop_back();
            dfs(mpp,ans,next);
        }
        ans.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> mpp;
        for(auto vec:tickets){
            mpp[vec[0]].push_back(vec[1]);
        }
        for(auto t:mpp){
            sort(mpp[t.first].rbegin(),mpp[t.first].rend());
        }
        vector<string> ans;
        dfs(mpp,ans,"JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
