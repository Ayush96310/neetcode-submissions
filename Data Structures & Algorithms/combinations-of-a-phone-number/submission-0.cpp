class Solution {
public:
    void solve(string &digits, vector<string> &ans, string &temp, unordered_map<char,vector<char>> &mpp, int ind){
        if(ind==digits.size()){
            ans.push_back(temp);
            return;
        }
        for(auto ch:mpp[digits[ind]]){
            temp+=ch;
            solve(digits,ans,temp,mpp,ind+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return {};
        unordered_map<char,vector<char>> mpp;
        mpp['2'] = {'a','b','c'};
        mpp['3'] = {'d','e','f'};
        mpp['4'] = {'g','h','i'};
        mpp['5'] = {'j','k','l'};
        mpp['6'] = {'m','n','o'};
        mpp['7'] = {'p','q','r','s'};
        mpp['8'] = {'t','u','v'};
        mpp['9'] = {'w','x','y','z'};
        vector<string> ans;
        string temp = "";
        solve(digits, ans, temp, mpp,0);
        return ans;
    }
};
