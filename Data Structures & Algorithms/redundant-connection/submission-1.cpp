class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>& mpp, vector<int>& vis,vector<int>& potential, int course, int parent){
        vis[course]=0;
        potential.push_back(course);
        for(auto t:mpp[course]){
            if(t==parent) continue;
            if(vis[t]==0){
                potential.push_back(t);
                return true;
            }
            if(vis[t]==-1){
                if(dfs(mpp,vis,potential,t,course)) return true;
                potential.pop_back();
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> mpp;
        for(auto t:edges){
            mpp[t[0]].push_back(t[1]);
            mpp[t[1]].push_back(t[0]);
        }
        vector<int> vis(edges.size()+1,-1);
        vector<int> potential;
        dfs(mpp,vis,potential,1,-1);
        unordered_map<int,int> st;
        int i = 0;
        int n = potential.size();
        for(;i<n;i++){
            if(potential[i]==potential[n-1]){
                break;
            }
        }
        for(;i<n-1;i++){
            st[potential[i]]=potential[i+1];
        }
        for(int i=edges.size()-1; i>=0;i--){
            if((st.find(edges[i][0])!=st.end() && st[edges[i][0]]==edges[i][1])
            || (st.find(edges[i][1])!=st.end() && st[edges[i][1]]==edges[i][0])
            ){
                return {edges[i][0],edges[i][1]};
            }
        }
        return {0};
    }
};
