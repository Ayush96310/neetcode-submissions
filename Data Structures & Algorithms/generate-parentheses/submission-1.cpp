class Solution {
public:
    void solve(vector<string>& ans, string &temp, int cntOp, int cntCls, int n){
        if(cntOp>n || cntCls>n || cntCls>cntOp){
            return;
        }
        if(cntOp==n && cntCls==n){
            ans.push_back(temp);
            return;
        }
        string temp2 = temp;
        temp+="(";
        cntOp++;
        solve(ans,temp,cntOp,cntCls,n);
        temp=temp2;
        cntOp--;
        temp+=")";
        cntCls++;
        solve(ans,temp,cntOp,cntCls,n);

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        solve(ans,temp,0,0,n);
        return ans;
    }
};
