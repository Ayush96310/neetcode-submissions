class Solution {
public:
    bool solve(unordered_map<char,unordered_set<char>> &mpp, string& s, unordered_map<char,int>& vis, char ch){
        if(!mpp.size()){
            vis[ch]=1;
            s+=ch;
            return true;
        }
        vis[ch]=0;
        for(auto& t:mpp[ch]){
            if(vis[t]==0) return false;
            else if(vis[t]==1) continue;
            else if(!solve(mpp,s,vis,t)) return false;
        }
        s+=ch;
        vis[ch]=1;
        return true;
    }
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        if(n==1) return words[0];
        unordered_map<char,unordered_set<char>> mpp;
        unordered_map<char,int> vis;
        for(int i=0; i<n-1; i++){
            int flag = 0;
            int p1 = 0;
            int p2 = 0;
            const string &s1 = words[i];
            const string &s2 = words[i+1];
            while(p1<s1.size() && p2<s2.size()){
                if(mpp.find(s1[p1])==mpp.end()){
                    mpp[s1[p1]]={};
                    vis[s1[p1]] = -1;
                }
                if(mpp.find(s2[p2])==mpp.end()){
                    mpp[s2[p2]]={};
                    vis[s2[p2]] = -1;
                }
                if(s1[p1]!=s2[p2] && !flag){
                    mpp[s2[p2]].insert(s1[p1]);
                    vis[s2[p2]] = -1;
                    flag = 1;
                }
                p1++;
                p2++;
            }
            if(p2>=s2.size() && p1<s1.size() && !flag) return "";
        }
        string s = "";
        for(auto t:vis){
            if(vis[t.first]==-1 && !solve(mpp,s,vis,t.first)) return "";
        }
        return s;
    }
};
