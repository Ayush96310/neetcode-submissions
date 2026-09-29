class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> mpp;
        mpp['}']='{';
        mpp[']']='[';
        mpp[')']='(';
        for(char ch:s){
            if(ch=='{' || ch=='(' || ch=='['){
                st.push(ch);
            }
            else{
                if(st.empty() || mpp[ch]!=st.top()){
                    return false;
                }
                else{
                    st.pop();
                }
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};
