class Solution {
public:
    bool check(string &s, int left, int right){
        while(left<=right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void solve(string &s, vector<vector<string>>& ans, vector<string>& temp, int start,int len){
        if(start==s.size()){
            ans.push_back(temp);
            return;
        }
        if (start + len > s.size()) return;
        if(check(s,start,start+len-1)){
            temp.push_back(s.substr(start,len));
            solve(s,ans,temp,start+len,1);
            temp.pop_back();
        }
        solve(s,ans,temp,start,len+1);
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,ans,temp,0,1);
        return ans;
    }
};
