class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>& mpp, vector<int>& vis, int course){
        vis[course] = 0;
        if(mpp.find(course)==mpp.end()){
            vis[course]=1;
            return true;
        }
        for(auto t:mpp[course]){
            if(!vis[t]) return false;
            if(vis[t]==1) continue;
            if(!dfs(mpp,vis,t)) return false;
        }
        vis[course]=1;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>> mpp;
        for(auto t:pre){
            mpp[t[0]].push_back(t[1]);
        }
        vector<int> vis(numCourses,-1);
        for(int i=0;i<numCourses;i++){
            if(mpp.find(i)==mpp.end()) vis[i]=1;
        }
        for(int i=0;i<numCourses;i++){
            if(vis[i]==-1 && !dfs(mpp,vis,i)) return false;
        }
        return true;
    }
};
