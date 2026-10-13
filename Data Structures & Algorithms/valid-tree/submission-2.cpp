class Solution {
public:
    bool dfs(vector<vector<int>>& edges, unordered_map<int,vector<int>> &mpp, vector<int>& vis, int course, int parent){
        vis[course] = 0;
        if(mpp.size()==1){
            vis[course]=1;
            return true;
        }
        for(auto t:mpp[course]){
            if(t==parent || vis[t]==1) continue;
            else if(!vis[t]) return false;
            else if(!dfs(edges,mpp,vis,t,course)) return false;
        }
        vis[course]=1;
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(!edges.size()) return true;
        if(edges.size()<n-1) return false;
        unordered_map<int,vector<int>> mpp;
        for(auto t:edges){
            mpp[t[0]].push_back(t[1]);
            mpp[t[1]].push_back(t[0]);
        }
        if(mpp.size()!=n) return false;
        vector<int> vis(n,-1);
        for(int i=0; i<n;i++){
            if(vis[i]==-1 && !dfs(edges,mpp,vis,i,-1)) return false;
        }
        return true;
    }
};
