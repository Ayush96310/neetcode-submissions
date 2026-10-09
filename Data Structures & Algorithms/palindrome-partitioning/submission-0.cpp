class Solution {
public:
    bool check(string &s){
        int n = s.size();
        int left = 0;
        int right = n-1;
        while(left<=right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void solve(string &s, vector<vector<string>>& ans, vector<string>& temp, int ind){
        int n = s.size();
        if(ind>=n){
            ans.push_back(temp);
            return;
        }
        for(int i=ind; i<n;i++){
            string sub = s.substr(ind,i-ind+1);
            if(!check(sub)){
                continue;
            }
            temp.push_back(sub);
            solve(s,ans,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,ans,temp,0);
        return ans;
    }
};
