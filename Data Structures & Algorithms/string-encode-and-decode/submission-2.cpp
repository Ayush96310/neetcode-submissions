class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        int n = strs.size();
        for(int i=0; i<n;i++){
            s=s+to_string(strs[i].size())+"#"+strs[i];
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int n = s.size();
        bool is_string = false;
        string len = "";
        int slen=0;
        for(int i=0; i<n;i++){
            if(s[i]=='#'){
                is_string = true;
                if(len!="0") slen = stoi(len);
                else {
                    ans.push_back("");
                    is_string = false;
                    len = "";
                    continue;
                }
                len = "";
            }
            if(!is_string){
                len+=s[i];
                cout<<len<<endl;
            }
            if(slen>0){
                ans.push_back(s.substr(i+1,slen));
                is_string = false;
                i+=slen;
                slen=0;
            }
        }
        return ans;
    }
};
