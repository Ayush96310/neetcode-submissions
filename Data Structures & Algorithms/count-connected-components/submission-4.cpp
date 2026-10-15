class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&mpp,vector<int>&vis,int course,int parent){
        vis[course]=1;
        for(auto t:mpp[course]){
            if(t==parent) continue;
            if(!vis[t]) dfs(mpp,vis,t,course);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> mpp;
        for(auto t:edges){
            mpp[t[0]].push_back(t[1]);
            mpp[t[1]].push_back(t[0]);
        }
        vector<int> vis(n,0);
        int ans = 0;
        for(int i=0; i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(mpp,vis,i,-1);
            }
        }
        return ans;
    }
};
