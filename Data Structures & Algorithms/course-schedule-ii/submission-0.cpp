class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>& mpp, vector<int>& vis, int course,vector<int>& ans){
        vis[course] = 0;
        if(!mpp[course].size()){
            ans.push_back(course);
            vis[course]=1;
            return true;
        }
        for(auto t:mpp[course]){
            if(!vis[t]) return false;
            if(vis[t]==1) continue;
            if(!dfs(mpp,vis,t,ans)) return false;
        }
        ans.push_back(course);
        vis[course]=1;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>> mpp;
        vector<int> ans;
        for(auto t:pre){
            mpp[t[0]].push_back(t[1]);
        }
        vector<int> vis(numCourses,-1);
        for(int i=0;i<numCourses;i++){
            if(mpp.find(i)==mpp.end()) mpp[i]={};
        }
        for(int i=0;i<numCourses;i++){
            if(vis[i]==-1 && !dfs(mpp,vis,i,ans)) return {};
        }
        return ans;
    }
};
